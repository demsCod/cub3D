// #include "../../includes/includes.h"

// #include <time.h>

// #define MOVE_SPEED 4.0
// #define ROT_SPEED 0.6

// double	ft_min(double a, double b)
// {
// 	if (a < b)
// 		return (a);
// 	return (b);
// }

// int is_wall(t_map *map, double x, double y)
// {
//     int map_x = (int)x;
//     int map_y = (int)y;
    
//     if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
//         return 1; // Consider out of bounds as a wall
    
//     return (map->map[map_y][map_x] == '1');
// }

// double get_delta_time()
// {
//     static clock_t last_time = 0;
//     clock_t current_time = clock();
//     double delta = (double)(current_time - last_time) / CLOCKS_PER_SEC;
//     last_time = current_time;
//     return delta;
// }

// int move_right(t_player *r)
// {
//     double delta_time = get_delta_time();
//     double rot_speed = ROT_SPEED * delta_time;
//     double prev_dx = r->dir_x;
//     double prev_px = r->plane_x;

//     r->dir_x = r->dir_x * cos(-rot_speed) - r->dir_y * sin(-rot_speed);
//     r->dir_y = prev_dx * sin(-rot_speed) + r->dir_y * cos(-rot_speed);
//     r->plane_x = r->plane_x * cos(-rot_speed) - r->plane_y * sin(-rot_speed);
//     r->plane_y = prev_px * sin(-rot_speed) + r->plane_y * cos(-rot_speed);
//     return (0);
// }

// int move_left(t_player *r)
// {
//     double delta_time = get_delta_time();
//     double rot_speed = ROT_SPEED * delta_time;
//     double prev_dx = r->dir_x;
//     double prev_px = r->plane_x;

//     r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
//     r->dir_y = prev_dx * sin(rot_speed) + r->dir_y * cos(rot_speed);
//     r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
//     r->plane_y = prev_px * sin(rot_speed) + r->plane_y * cos(rot_speed);
//     return (0);
// }

// int	move_up(t_player *r, t_map *map)
// {
//     double delta_time = get_delta_time();
//     double move_speed = MOVE_SPEED * delta_time;
//     double new_x = r->x + r->dir_x * move_speed;
//     double new_y = r->y + r->dir_y * move_speed;
    
//     if (!is_wall(map, new_x, r->y))
//         r->x = new_x;
//     if (!is_wall(map, r->x, new_y))
//         r->y = new_y;
    
//     return 0;
// }

// int	move_down(t_player *r, t_map *map)
// {
//     double delta_time = get_delta_time();
//     double move_speed = MOVE_SPEED * delta_time;
//     double new_x = r->x - r->dir_x * move_speed;
//     double new_y = r->y - r->dir_y * move_speed;
    
//     if (!is_wall(map, new_x, r->y))
//         r->x = new_x;
//     if (!is_wall(map, r->x, new_y))
//         r->y = new_y;
    
//     return 0;
// }

// int	keyfonction(int keycode, t_all *data)
// {
//     if (keycode == XK_Escape)
//     {
//         free_all_exit(data);
//     }

//     if (keycode == XK_Left)
//         move_left(data->player);
    
//     if (keycode == XK_Right)
//         move_right(data->player);
    
//     if (keycode == XK_Up)
//         move_up(data->player, data->map);
    
//     if (keycode == XK_Down)
//         move_down(data->player, data->map);
    
//     return (0);
// }

#include "../../includes/includes.h"
#include <time.h>

#define MOVE_SPEED 4.0
#define ROT_SPEED 3.0
#define WALL_MARGIN 0.2  // Collision buffer distance from walls

static double get_delta_time(void)
{
    static clock_t last_time = 0;
    static double delta = 0;
    clock_t current_time;
    
    current_time = clock();
    if (last_time == 0)
    {
        last_time = current_time;
        return (1.0 / 60.0);  // First frame assumes 60 FPS
    }
    delta = (double)(current_time - last_time) / CLOCKS_PER_SEC;
    last_time = current_time;
    // Clamp delta time to prevent jumps if game freezes
    if (delta > 0.1)
        delta = 0.1;
    return (delta);
}

static int is_wall(t_map *map, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;
    
    // Check map boundaries first
    if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
        return 1; // Consider out of bounds as a wall
    
    return (map->map[map_y][map_x] == '1');
}

static int check_collision(t_map *map, double x, double y)
{
    // Check the actual position plus a small margin around the player
    return (is_wall(map, x - WALL_MARGIN, y - WALL_MARGIN) ||
            is_wall(map, x + WALL_MARGIN, y - WALL_MARGIN) ||
            is_wall(map, x - WALL_MARGIN, y + WALL_MARGIN) ||
            is_wall(map, x + WALL_MARGIN, y + WALL_MARGIN));
}

int move_rotate(t_player *r, double rotation_dir)
{
    double delta_time;
    double rot_speed;
    double prev_dx;
    double prev_px;

    delta_time = get_delta_time();
    rot_speed = (ROT_SPEED * delta_time) * rotation_dir;
    prev_dx = r->dir_x;
    prev_px = r->plane_x;

    // Rotate direction vector
    r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
    r->dir_y = prev_dx * sin(rot_speed) + r->dir_y * cos(rot_speed);
    
    // Rotate camera plane
    r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
    r->plane_y = prev_px * sin(rot_speed) + r->plane_y * cos(rot_speed);
    
    return (0);
}

int move_player(t_player *r, t_map *map, double forward_dir)
{
    double delta_time;
    double move_speed;
    double new_x;
    double new_y;

    delta_time = get_delta_time();
    move_speed = MOVE_SPEED * delta_time * forward_dir;
    
    // Calculate new position
    new_x = r->x + r->dir_x * move_speed;
    new_y = r->y + r->dir_y * move_speed;
    
    // Split movement into X and Y components for sliding along walls
    if (!check_collision(map, new_x, r->y))
        r->x = new_x;
    if (!check_collision(map, r->x, new_y))
        r->y = new_y;
    
    return (0);
}

// Additional movement functions for strafing (optional)
int strafe_player(t_player *r, t_map *map, double strafe_dir)
{
    double delta_time;
    double move_speed;
    double new_x;
    double new_y;

    delta_time = get_delta_time();
    move_speed = MOVE_SPEED * delta_time * strafe_dir;
    
    // Move perpendicular to viewing direction
    new_x = r->x + r->plane_x * move_speed;
    new_y = r->y + r->plane_y * move_speed;
    
    if (!check_collision(map, new_x, r->y))
        r->x = new_x;
    if (!check_collision(map, r->x, new_y))
        r->y = new_y;
    
    return (0);
}

int keyfonction(int keycode, t_all *data)
{
    if (keycode == XK_Escape)
        free_all_exit(data);
    
    // Rotation (left/right)
    if (keycode == XK_Left)
        move_rotate(data->player, 1.0);  // Positive for counter-clockwise
    if (keycode == XK_Right)
        move_rotate(data->player, -1.0); // Negative for clockwise
    
    // Movement (forward/backward)
    if (keycode == XK_w || keycode == XK_Up)
        move_player(data->player, data->map, 1.0);  // Forward
    if (keycode == XK_s || keycode == XK_Down)
        move_player(data->player, data->map, -1.0); // Backward
    
    // Strafing (optional)
    if (keycode == XK_a)
        strafe_player(data->player, data->map, -1.0); // Strafe left
    if (keycode == XK_d)
        strafe_player(data->player, data->map, 1.0);  // Strafe right
    
    return (0);
}
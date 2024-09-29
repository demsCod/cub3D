#include "../../includes/includes.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

int is_wall(t_map *map, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;
    
    if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
        return 1; // Consider out of bounds as a wall
    
    return (map->map[map_y][map_x] == '1');
}

int move_right(t_player *r)
{
	double		prev_dx;
	double		prev_px;
	double		rot_speed;

	prev_dx = r->dir_x;
	prev_px = r->plane_x;
	rot_speed = -0.045;
	r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
	r->dir_y = prev_dx * sin(rot_speed) + r->dir_y * cos(rot_speed);
	r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
	r->plane_y = prev_px * sin(rot_speed) + r->plane_y * cos(rot_speed);
	return (0);
}
int move_left(t_player *r)
{
	double		prev_dx;
	double		prev_px;
	double		rot_speed;

	prev_dx = r->dir_x;
	prev_px = r->plane_x;
	rot_speed = 0.045;
	r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
	r->dir_y = prev_dx * sin(rot_speed) + r->dir_y * cos(rot_speed);
	r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
	r->plane_y = prev_px * sin(rot_speed) + r->plane_y * cos(rot_speed);
	return (0);
}

int	move_up(t_player *r, t_map *map)
{
	double move_speed = 0.45;
    double new_x = r->x + r->dir_x * move_speed;
    double new_y = r->y + r->dir_y * move_speed;
    
    // Check for collision
    if (!is_wall(map, new_x, r->y))
        r->x = new_x;
    if (!is_wall(map, r->x, new_y))
        r->y = new_y;
    
    return 0;
}

int	move_down(t_player *r, t_map *map )
{
	double move_speed = 0.45;
    double new_x = r->x - r->dir_x * move_speed;
    double new_y = r->y - r->dir_y * move_speed;
    
    // Check for collision
    if (!is_wall(map, new_x, r->y))
        r->x = new_x;
    if (!is_wall(map, r->x, new_y))
        r->y = new_y;
    
    return 0;
}
int	keyfonction(int keycode, t_all *data)
{
	if (keycode == XK_Escape)
		exit(0);

	if (keycode == XK_Left)
		move_left(data->player);
	
	if (keycode == XK_Right)
		move_right(data->player);
	
	if (keycode == XK_Up)
		move_up(data->player, data->map);
	
	if (keycode == XK_Down)
		move_down(data->player, data->map);
	
	return (0);
}

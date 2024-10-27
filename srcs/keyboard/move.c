#include "../../includes/includes.h"
#include <time.h>

#define MOVE_SPEED 2.0
#define ROT_SPEED 1.3
#define WALL_MARGIN 0.10


// static int	is_wall(t_map *map, double x, double y)
// {
// 	int	map_x;
// 	int	map_y;

// 	map_x = (int)x;
// 	map_y = (int)y;
// 	if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
// 		return (1);
// 	return (map->map[map_y][map_x] == '1');
// }

// // int	move_right(t_player *r)
// // {
// 	double	delta_time;
// 	double	rot_speed;
// 	double	old_dir_x;
// 	double	old_plane_x;

// 	delta_time = get_delta_time();
// 	rot_speed = ROT_SPEED * delta_time;
// 	old_dir_x = r->dir_x;
// 	old_plane_x = r->plane_x;
// 	// Rotate camera direction
// 	r->dir_x = r->dir_x * cos(-rot_speed) - r->dir_y * sin(-rot_speed);
// 	r->dir_y = old_dir_x * sin(-rot_speed) + r->dir_y * cos(-rot_speed);
// 	r->plane_x = r->plane_x * cos(-rot_speed) - r->plane_y * sin(-rot_speed);
// 	r->plane_y = old_plane_x * sin(-rot_speed) + r->plane_y * cos(-rot_speed);
//     r->plane_x = -r->dir_y * 0.66;
//     r->plane_y = r->dir_x * 0.66;
// 	return (0);
// }

// int	move_left(t_player *r)
// {
// 	double	delta_time;
// 	double	rot_speed;
// 	double	old_dir_x;
// 	double	old_plane_x;

// 	delta_time = get_delta_time();
// 	rot_speed = ROT_SPEED * delta_time;
// 	old_dir_x = r->dir_x;
// 	old_plane_x = r->plane_x;
// 	// Rotate camera direction
// 	r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
// 	r->dir_y = old_dir_x * sin(rot_speed) + r->dir_y * cos(rot_speed);
// 	// Rotate camera plane consistently with direction
// 	r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
// 	r->plane_y = old_plane_x * sin(rot_speed) + r->plane_y * cos(rot_speed);
//     r->plane_x = -r->dir_y * 0.66;
//     r->plane_y = r->dir_x * 0.66;
// 	return (0);
// }
int	move_up(t_all *all)
{
	double move_x;
	double move_y;
	t_player *r = all->ply;

	move_x = cos(r->angle) * PLAYER_SPEED;
	move_y = sin(r->angle) * PLAYER_SPEED;
    mlx_pixel_put(all->mlx_p, all->win_p, move_x * TILE_SIZE, move_y *TILE_SIZE, 0xFFFFFF);

	return (0);
}

// int	move_down(t_player *r, t_map *map)
// {
// 	double	delta_time;
// 	double	move_speed;
// 	double	move_x;
// 	double	move_y;

// 	delta_time = get_delta_time();
// 	move_speed = MOVE_SPEED * delta_time;
// 	// Move in the opposite direction we're facing
// 	move_x = -(r->dir_x * move_speed);
// 	move_y = -(r->dir_y * move_speed);
// 	// Check collisions separately
// 	if (!is_wall(map, r->x + move_x, r->y))
// 		r->x += move_x;
// 	if (!is_wall(map, r->x, r->y + move_y))
// 		r->y += move_y;
// 	return (0);
// }

// int	strafe_left(t_player *r, t_map *map)
// {
// 	double	delta_time;
// 	double	move_speed;
// 	double	move_x;
// 	double	move_y;

// 	delta_time = get_delta_time();
// 	move_speed = MOVE_SPEED * delta_time;
// 	// For strafing left,
// 		// rotate the direction vector 90 degrees counter-clockwise
// 	move_x = -r->dir_y * move_speed;
// 	move_y = r->dir_x * move_speed;
// 	if (!is_wall(map, r->x + move_x, r->y))
// 		r->x += move_x;
// 	if (!is_wall(map, r->x, r->y + move_y))
// 		r->y += move_y;
// 	return (0);
// }

// int	strafe_right(t_player *r, t_map *map)
// {
// 	double	delta_time;
// 	double	move_speed;
// 	double	move_x;
// 	double	move_y;

// 	delta_time = get_delta_time();
// 	move_speed = MOVE_SPEED * delta_time;
// 	// For strafing right, rotate the direction vector 90 degrees clockwise
// 	move_x = r->dir_y * move_speed;
// 	move_y = -r->dir_x * move_speed;
// 	if (!is_wall(map, r->x + move_x, r->y))
// 		r->x += move_x;
// 	if (!is_wall(map, r->x, r->y + move_y))
// 		r->y += move_y;
// 	return (0);
// }

int	keyfonction(int keycode, t_all *data)
{
	if (keycode == XK_Escape)
		exit(0);

	// Rotation
	// if (keycode == XK_Left)
	// 	move_left(data->player);
	// if (keycode == XK_Right)
	// 	move_right(data->player);
		
	if (keycode == XK_Up || keycode == XK_w)
		move_up(data);
	// if (keycode == XK_Down || keycode == XK_s)
	// 	move_down(data->player, data->map);

	// // Strafing (optional)
	// if (keycode == XK_a)
	// 	strafe_left(data->player, data->map);
	// if (keycode == XK_d)
	// 	strafe_right(data->player, data->map);

	return (0);
}
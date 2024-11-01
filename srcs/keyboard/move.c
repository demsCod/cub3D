#include "../../includes/includes.h"
#include <time.h>

#define MOVE_SPEED 2.0
#define ROT_SPEED 1.3
#define MAX_DELTA 0.1

static double	ft_get_delta(void)
{
	static clock_t	last_time;
	clock_t			current_time;
	double			delta;

	last_time = 0;
	current_time = clock();
	delta = (double)(current_time - last_time) / CLOCKS_PER_SEC;
	last_time = current_time;
	if (delta > MAX_DELTA)
		delta = MAX_DELTA;
	return (delta);
}

static int	ft_check_bounds(int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
		return (1);
	return (0);
}

static int	ft_check_margin_point(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (ft_check_bounds(map_x, map_y))
		return (1);
	return (map->map[map_y][map_x] == '1');
}

static int	ft_is_wall(t_map *map, double x, double y)
{
	if (ft_check_margin_point(map, x + WALL_MARGIN, y)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y)
		|| ft_check_margin_point(map, x, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x, y - WALL_MARGIN)
		|| ft_check_margin_point(map, x + WALL_MARGIN, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x + WALL_MARGIN, y - WALL_MARGIN)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y - WALL_MARGIN))
		return (1);
	return (ft_check_margin_point(map, x, y));
}

static void	ft_rotate_vectors(t_player *r, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = r->dir_x;
	old_plane_x = r->plane_x;
	r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
	r->dir_y = old_dir_x * sin(rot_speed) + r->dir_y * cos(rot_speed);
	r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
	r->plane_y = old_plane_x * sin(rot_speed) + r->plane_y * cos(rot_speed);
}

int	ft_move_right(t_player *r)
{
	double	delta_time;
	double	rot_speed;

	delta_time = ft_get_delta();
	rot_speed = -ROT_SPEED * delta_time;
	ft_rotate_vectors(r, rot_speed);
	return (0);
}

int	ft_move_left(t_player *r)
{
	double	delta_time;
	double	rot_speed;

	delta_time = ft_get_delta();
	rot_speed = ROT_SPEED * delta_time;
	ft_rotate_vectors(r, rot_speed);
	return (0);
}

static int	ft_try_move(t_player *r, t_map *map, double new_x, double new_y)
{
	if (!ft_is_wall(map, new_x, new_y))
	{
		r->x = new_x;
		r->y = new_y;
	}
	return (0);
}

int	ft_move_up(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x + r->dir_x * move_speed;
	new_y = r->y + r->dir_y * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_move_down(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x - r->dir_x * move_speed;
	new_y = r->y - r->dir_y * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_strafe_left(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x - r->dir_y * move_speed;
	new_y = r->y + r->dir_x * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_strafe_right(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x + r->dir_y * move_speed;
	new_y = r->y - r->dir_x * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_key_function(int keycode, t_all *data)
{
	if (keycode == XK_Escape)
		free_all_exit(data);
	if (keycode == XK_Left)
		ft_move_left(data->player);
	if (keycode == XK_Right)
		ft_move_right(data->player);
	if (keycode == XK_Up || keycode == XK_w)
		ft_move_up(data->player, data->map);
	if (keycode == XK_Down || keycode == XK_s)
		ft_move_down(data->player, data->map);
	if (keycode == XK_a)
		ft_strafe_left(data->player, data->map);
	if (keycode == XK_d)
		ft_strafe_right(data->player, data->map);
	return (0);
}
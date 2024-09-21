#include "../../includes/cub3D.h"

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

int move_right(t_ray_player *r)
{
	double		prev_dx;
	double		prev_px;
	double		rot_speed;

	prev_dx = r->d_x;
	prev_px = r->plane_X;
	rot_speed = 3;
	r->d_x = r->d_x * cos(rot_speed) - r->d_y * sin(rot_speed);
	r->d_y = prev_dx * sin(rot_speed) + r->d_y * cos(rot_speed);
	r->plane_X = r->plane_X * cos(rot_speed) - r->plane_Y * sin(rot_speed);
	r->plane_Y = prev_px * sin(rot_speed) + r->plane_Y * cos(rot_speed);
	return (0);
}
int move_left(t_ray_player *r)
{
	double		prev_dx;
	double		prev_px;
	double		rot_speed;

	prev_dx = r->d_x;
	prev_px = r->plane_X;
	rot_speed = -3;
	r->d_x = r->d_x * cos(rot_speed) - r->d_y * sin(rot_speed);
	r->d_y = prev_dx * sin(rot_speed) + r->d_y * cos(rot_speed);
	r->plane_X = r->plane_X * cos(rot_speed) - r->plane_Y * sin(rot_speed);
	r->plane_Y = prev_px * sin(rot_speed) + r->plane_Y * cos(rot_speed);
	return (0);
}

int	move_back(t_ray_player *r)
{
	double		move_speed;

	move_speed = 3;
	r->x += r->d_x * move_speed;
	r->y += r->d_y * move_speed;
	return(0);
}

int	move_front(t_ray_player *r)
{
	double		move_speed;

	move_speed = 3;
	r->x -= r->d_x * move_speed;
	r->y -= r->d_y * move_speed;
	return(0);

}
int	keyfonction(int keycode, t_map_data *data)
{
	printf("press\n");
	if (keycode == XK_Escape)
		exit(0);

	if (keycode == XK_Left)
	{
		move_left(data->r_play);
	}
	if (keycode == XK_Right)
	{
		move_right(data->r_play);
	}
	if (keycode == XK_Up)
	{
		move_back(data->r_play);
	}
	if (keycode == XK_Down)
	{
		move_front(data->r_play);
	}
	data->start = true;
	return (0);
}

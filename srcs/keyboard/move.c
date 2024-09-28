#include "../../includes/includes.h"

    double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
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

int	move_up(t_player *r)
{
	double		move_speed;

	move_speed = 0.45;
	r->x += r->dir_x * move_speed;
	r->y += r->dir_y * move_speed;
	return(0);
}

int	move_down(t_player *r)
{
	double		move_speed;

	move_speed = 0.45;
	r->x -= r->dir_x * move_speed;
	r->y -= r->dir_y * move_speed;
	return(0);
}
int	keyfonction(int keycode, t_player *data)
{
	printf("press\n");
	if (keycode == XK_Escape)
		exit(0);

	if (keycode == XK_Left)
	{
		move_left(data);
	}
	if (keycode == XK_Right)
	{
		move_right(data);
	}
	if (keycode == XK_Up)
	{
		move_up(data);
	}
	if (keycode == XK_Down)
	{
		move_down(data);
	}
	return (0);
}

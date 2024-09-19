#include "../../includes/cub3D.h"

void init_camera(t_map_data *data)
{
	int x = 0;
	while (x < SCREEN_WIDHT_SIZE)
	{
		data->r_play->camera_X = 2 * x / (double)SCREEN_WIDHT_SIZE - 1;
		data->r_play->ray_dir_x = data->r_play->d_x + data->r_play->plane_X * data->r_play->camera_X;
		data->r_play->ray_dir_x = data->r_play->d_y + data->r_play->plane_Y * data->r_play->camera_X;
		x++;
	}
}
int	keyfonction(int keycode, t_map_data *data)
{
	if (keycode == XK_Escape)
	{
		exit(0);
	}
	if (keycode == XK_Left)
	{
		data->r_play->a -= 0.1;
		if (data->r_play->a < 0)
			data->r_play->a += 2 * PI;
		data->r_play->d_x = cos(data->r_play->a) * 5;
		data->r_play->d_y = sin(data->r_play->a) * 5;
		
	}
	if (keycode == XK_Right)
	{
		data->r_play->a += 0.1;
		if (data->r_play->a > 2 * PI)
			data->r_play->a -= 2 * PI;
		data->r_play->d_x = cos(data->r_play->a) * 5;
		data->r_play->d_y = sin(data->r_play->a) * 5;
	}
	if (keycode == XK_Up)
	{
		data->r_play->x += data->r_play->d_x;
		data->r_play->y += data->r_play->d_y;
	}
	if (keycode == XK_Down)
	{
		data->r_play->x -= data->r_play->d_x;
		data->r_play->y -= data->r_play->d_y;
	}
	init_camera(data);
	draw_background(data);
	return (0);
}

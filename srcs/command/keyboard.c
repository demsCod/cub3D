#include "../../includes/cub3D.h"

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
	draw_background(data);
	return (0);
}

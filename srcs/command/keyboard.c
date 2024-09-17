#include "../../includes/cub3D.h"

int	keyfonction(int keycode, t_map_data *data)
{
	int x; int y;
	if (keycode == XK_Escape)
	{
		exit(0);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		x = (data->r_play->x ) / 30;
		y = (data->r_play->y +10.0)  / 30;
		if(data->map[y][x] != WALL )
			data->r_play->y += 2.0;
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		x = (data->r_play->x -1.9) / 30;
		y = (data->r_play->y )  / 30;
		if (data->map[y][x] != WALL )
			data->r_play->x -= 2.0;
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		x = (data->r_play->x +10.0) / 30;
		y = (data->r_play->y)  / 30;
		if(data->map[y][x] != WALL )
			data->r_play->x += 2.0;
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		x = (data->r_play->x) / 30;
		y = (data->r_play->y -2.0)  / 30;
		if(data->map[y][x] != WALL )
			data->r_play->y -= 2.0;
	}
	draw_background(data);
	return (0);
}
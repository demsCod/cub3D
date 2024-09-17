#include "../../includes/cub3D.h"

int	keyfonction(int keycode, t_map_data *data)
{
	if (keycode == XK_Escape)
	{
		exit(0);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		data->r_play->y += 2.0;
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		data->r_play->x -= 2.0;
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		data->r_play->x += 2.0;
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		data->r_play->y -= 2.0;
	}
	draw_background(data);
	return (0);
}
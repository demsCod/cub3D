#include "../../includes/cub3D.h"

void dda_work(t_map_data *data)
{
	if (data->r_play->ray_dir_x < 0)
	{
		data->r_play->step_x = -1;
		data->r_play->side_dist_x = (data->r_play->x - data->r_play->map_x) * data->r_play->delta_dist_x;
	}
	else
	{
		data->r_play->step_x = 1;
		data->r_play->side_dist_x = (data->r_play->map_x + 1.0 - data->r_play->x) * data->r_play->delta_dist_x;
	}
	if (data->r_play->ray_dir_y < 0)
	{
		data->r_play->step_y = -1;
		data->r_play->side_dist_y = (data->r_play->y - data->r_play->map_y) * data->r_play->delta_dist_y;
	}
	else
	{
		data->r_play->step_y = 1;
		data->r_play->side_dist_y = (data->r_play->map_y + 1.0 - data->r_play->y) * data->r_play->delta_dist_y;
	}
	printf(" s_y =  %d\n" , data->r_play->step_y );
	printf(" s_x =  %d\n" , data->r_play->step_x );
	printf("y=%d\n x = %d\n", data->r_play->map_y / 30 , data->r_play->map_x / 30);

	while (42)
	{
		if (data->r_play->side_dist_x < data->r_play->side_dist_y)
		{
			data->r_play->side_dist_x += data->r_play->delta_dist_x;
			data->r_play->map_x += data->r_play->step_x;
			data->r_play->side = 0;
		}
		else
		{
			data->r_play->side_dist_y += data->r_play->delta_dist_y;
			data->r_play->map_y += data->r_play->step_y;
			data->r_play->side = 1;
		}
		if (data->map[data->r_play->map_y / 30][data->r_play->map_x / 30] == '1')
		{
			printf("y_prime==%d\n x_prime==%d\n", data->r_play->map_y / 30, data->r_play->map_x / 30);
			break;
		}
	}
	/*calculer la distance des murs !*/

}

void init_camera(t_map_data *data)
{
	int x = 0;
	while (x < SCREEN_WIDHT_SIZE)
	{
		data->r_play->camera_X = 2 * x / (double)SCREEN_WIDHT_SIZE - 1;
		data->r_play->ray_dir_x = data->r_play->d_x + data->r_play->plane_X * data->r_play->camera_X;
		data->r_play->ray_dir_y = data->r_play->d_y + data->r_play->plane_Y * data->r_play->camera_X;
		x++;
	}
	data->r_play->map_x = (int)data->r_play->x;
	data->r_play->map_y = (int)data->r_play->y;
	data->r_play->delta_dist_x = fabs(1 / data->r_play->ray_dir_x);
	data->r_play->delta_dist_y = fabs(1 / data->r_play->ray_dir_y);
	dda_work(data);
	
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

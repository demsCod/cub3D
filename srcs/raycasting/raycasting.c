/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/09/20 21:32:12 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void calcul_wall_distance(t_map_data *data)
{

	if (data->r_play->side == 0)
		data->r_play->wall_dist = (data->r_play->map_x - data->r_play->x + (1 - data->r_play->step_x) / 2) / data->r_play->ray_dir_x;
	else
		data->r_play->wall_dist = (data->r_play->map_y - data->r_play->y + (1 - data->r_play->step_y) / 2) / data->r_play->ray_dir_y;

	data->r_play->line_height = (int)(SCREEN_HEIGHT_SIZE / data->r_play->wall_dist);

	data->r_play->draw_start = -data->r_play->line_height / 2 + SCREEN_HEIGHT_SIZE / 2;
	if (data->r_play->draw_start < 0)
		data->r_play->draw_start = 0;

	data->r_play->draw_end = data->r_play->line_height / 2 + SCREEN_HEIGHT_SIZE / 2;
	if (data->r_play->draw_end >= SCREEN_HEIGHT_SIZE)
		data->r_play->draw_end = SCREEN_HEIGHT_SIZE - 1;

	if (data->r_play->side == 0)
		data->r_play->wall_x = data->r_play->y + data->r_play->wall_dist * data->r_play->ray_dir_x;
	else
		data->r_play->wall_x = data->r_play->x + data->r_play->wall_dist * data->r_play->ray_dir_y;
	data->r_play->wall_x -= floor(data->r_play->wall_x);
}

void calcul_distance_inter(t_map_data *data)
{
	while (1)
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
			// printf("y_prime==%d | x_prime==%d\n", data->r_play->map_y / 30, data->r_play->map_x / 30);
			break;
		}
	}
}
void dda_work(t_map_data *data, int x)
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
	calcul_distance_inter(data);
	calcul_wall_distance(data);
	// printf("s_y =  %d | " , data->r_play->step_y );
	// printf("s_x =  %d\n" , data->r_play->step_x );
	draw_camera(data, data->r_play,  data->draw, x);
	printf("y=%d | x = %d\n", data->r_play->map_y / 30 , data->r_play->map_x / 30);
	/*find the shorter intersection*/
	/*calculate_wall_distance*/
	// printf("wall_dist ==%f\n", data->r_play->wall_dist);
	// printf("wall_x ==%f\n", data->r_play->wall_x);
	/*drawing_wall*/
}
void	draw_camera (t_map_data *data, t_ray_player *r_play, t_draw_data *draw, int x)
{
	(void)draw;
	
	while (r_play->draw_start < r_play->draw_end)
	{
		img_pix_put(data->background_img, x, r_play->draw_start, BLUE_PIXEL);
		r_play->draw_start++;
	}
}
void init_camera(t_map_data *data)
{
	int x = 0;
	
	data->background_img->addr = mlx_get_data_addr(data->background_img->mlx_img,
			&data->background_img->bpp, &data->background_img->line_len,
			&data->background_img->endian);
	ft_memset(data->background_img->addr, 0, (SCREEN_HEIGHT_SIZE * data->background_img->line_len + SCREEN_WIDHT_SIZE * (data->background_img->bpp / 8)));
	while (x < SCREEN_WIDHT_SIZE)
	{
		data->r_play->camera_X = 2 * x / (double)SCREEN_WIDHT_SIZE - 1;
		data->r_play->ray_dir_x = data->r_play->d_x + data->r_play->plane_X * data->r_play->camera_X;
		data->r_play->ray_dir_y = data->r_play->d_y + data->r_play->plane_Y * data->r_play->camera_X;
		data->r_play->map_x = (int)data->r_play->x;
		data->r_play->map_y = (int)data->r_play->y;
		data->r_play->delta_dist_x = fabs(1 / data->r_play->ray_dir_x);
		data->r_play->delta_dist_y = fabs(1 / data->r_play->ray_dir_y);
		dda_work(data, x);
		x++;
	}
}
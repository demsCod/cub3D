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
		data->r_play->wall_dist = data->r_play->side_dist_x - data->r_play->delta_dist_x;
	else	
		data->r_play->wall_dist = data->r_play->side_dist_y - data->r_play->delta_dist_y;

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
void	ft_update_pixel_map(t_map_data *data, t_ray_player *ray, int x)
{
	t_cardinal_direction	dir;
	int						tex_x;
	int						color;
	double					pos;
	double					step;

	dir = ft_get_cardinal_direction(ray);
	tex_x = (int)(ray->wall_x * TEXTURE_SIZE);
	if ((ray->draw_start == 0 && ray->ray_dir_x < 0) || (ray->draw_end == 1 && ray->ray_dir_y > 0))
		tex_x = TEXTURE_SIZE - tex_x - 1;
	step = 1.0 * TEXTURE_SIZE / ray->line_height;
	pos = (ray->draw_start - SCREEN_HEIGHT_SIZE / 2 + ray->line_height / 2) * step;
	while (ray->draw_start < ray->draw_end)
	{
		pos += step;
		color = (data->texture_buffer)[dir][TEXTURE_SIZE
			* ((int)pos & (TEXTURE_SIZE - 1)) + tex_x];
		if (dir == NORTH || dir == SOUTH)
			color = (color >> 1) & 0x7F7F7F;
		if (color > 0)
			data->pixels[ray->draw_start][x] = color;
		ray->draw_start++;
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
	ft_update_pixel_map(data, data->r_play, x);
	//draw_camera(data, data->r_play,  data->draw, x);
}
// bool	ft_create_texture_buffer_from_img(t_map_data *data)
// {
// 	int	*pixels;
// 	int	i;
// 	int	j;

// 	pixels = ft_calloc(sizeof(int), data->background_img-> * img->height);
// 	if (!pixels)
// 		return (false);
// 	i = -1;
// 	while (++i < img->height)
// 	{
// 		j = -1;
// 		while (++j < data->background_img->)
// 			pixels[i * data->background_img-> + j] = img->addr[i * data->background_img-> + j];
// 	}
// 	data->texture_buffer[dir] = pixels;
// 	return (true);
// }
/*
bool	ft_create_pixel_map(t_map_data *data)
{
	int	i;

	data->pixels = ft_calloc(sizeof(int *), SCREEN_HEIGHT_SIZE + 1);
	if (!data->pixels)
		return (false);
	i = -1;
	while (++i < SCREEN_HEIGHT_SIZE)
	{
		data->pixels[i] = ft_calloc(sizeof(int), SCREEN_WIDHT_SIZE);
		if (!data->pixels[i])
			return (ft_free_void_array((void **)data->pixels, i), false);
	}
	return (true);
}*/
void	draw_pixel_map (t_map_data *data, t_ray_player *r_play, t_draw_data *draw, int j)
{
	(void)draw;
	t_img_data img;
	(void)r_play;
	(void)j;
	int		x;
	int		y;
	img.img = mlx_new_image(data->mlx_ptr, SCREEN_WIDHT_SIZE, SCREEN_HEIGHT_SIZE);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	y = -1;
	while (++y < SCREEN_HEIGHT_SIZE)
	{
		x = -1;
		while (++x < SCREEN_WIDHT_SIZE)
		{
			if (data->pixels[y][x] > 0)
				img.addr[y * (img.line_len / 4) + x] = data->pixels[y][x];
			else if (y < SCREEN_HEIGHT_SIZE / 2)
				img.addr[y * (img.line_len / 4) + x] = data->ceiling_hex;
			else if (y < SCREEN_HEIGHT_SIZE -1)
				img.addr[y * (img.line_len / 4) + x] = data->floor_hex;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, img.img);
}
void init_camera(t_map_data *data)
{
	int x = 0;
	
	printf("%d\n", x);
	while (x < SCREEN_WIDHT_SIZE)
	{
		printf("%d\n", x);
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
	//mlx_destroy_image(data->mlx_ptr, data->background_img);
}
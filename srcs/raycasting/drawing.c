/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:29:48 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:22 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_cardinal_direction	ft_get_cardinal_direction(t_player *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (WEST);
		return (EAST);
	}
	else
	{
		if (ray->step_y > 0)
			return (SOUTH);
		return (NORTH);
	}
}

void	init_pix(t_pixel *pix, t_player *player)
{
	pix->color = 0;
	pix->pos = 0;
	pix->step = 0;
	pix->dir = ft_get_cardinal_direction(player);
	pix->tex_x = (int)(player->wall_x * (TEXTURE_SIZE));
	if (player->side == 0 && player->ray_dir_x > 0)
		pix->tex_x = TEXTURE_SIZE - pix->tex_x - 1;
	if (player->side == 1 && player->ray_dir_y < 0)
		pix->tex_x = TEXTURE_SIZE - pix->tex_x - 1;
	pix->step = 1.0 * TEXTURE_SIZE / player->line_height;
	pix->pos = (player->draw_start - WIN_HEIGHT / 2 + player->line_height / 2)
		* pix->step;
}

void	set_pixel_map(t_player *player, t_map *map, int x)
{
	t_pixel	pix;

	init_pix(&pix, player);
	while (player->draw_start < player->draw_end)
	{
		pix.tex_y = (int)pix.pos & (TEXTURE_SIZE - 1);
		pix.pos += pix.step;
		if (pix.tex_x >= 0 && pix.tex_x < TEXTURE_SIZE && pix.tex_y >= 0
			&& pix.tex_y < TEXTURE_SIZE)
		{
			pix.color = (map->texture_buffer)[pix.dir]
			[TEXTURE_SIZE * pix.tex_y + pix.tex_x];
			if (pix.dir == NORTH || pix.dir == SOUTH)
				pix.color = (pix.color >> 1) & 0x7F7F7F;
			if (pix.color > 0 && player->draw_start >= 0
				&& player->draw_start < WIN_HEIGHT && x >= 0 && x < WIN_WIDHT)
				player->pixel_map[player->draw_start][x] = pix.color;
		}
		player->draw_start++;
	}
}

void	ft_draw_pixel_map(t_player *player, t_map *m)
{
	t_img_data	img;
	int			x;
	int			y;

	img.img = mlx_new_image(player->mlx_ptr, WIN_WIDHT, WIN_HEIGHT);
	if (img.img == NULL)
		exit(0);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.line_len,
			&img.endian);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDHT)
		{
			if (player->pixel_map[y][x] > 0)
				img.addr[y * (img.line_len / 4) + x] = player->pixel_map[y][x];
			else if (y < WIN_HEIGHT / 2)
				img.addr[y * (img.line_len / 4) + x] = m->cei_texture;
			else if (y < WIN_HEIGHT)
				img.addr[y * (img.line_len / 4) + x] = m->flo_texture;
		}
	}
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, img.img, 0, 0);
	mlx_destroy_image(player->mlx_ptr, img.img);
}

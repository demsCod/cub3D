#include "../../includes/cub3D.h"

void	img_pix_put(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void drawing_wall(t_map_data *data, int x, int y)
{
	data->w_widht = 30;
	data->w_height = 30;
	int i;
	int j;

	i = y;
	while (i < y + data->w_height)
	{
		j = x;
		while (j < x + data->w_widht)
		{
			img_pix_put(data->background_img, i, j, BLUE_PIXEL);
			j++;
		}
		++i;
	}
}


void	draw_wall(t_map_data *data)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while(data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == WALL)
			{
				drawing_wall(data, y * 30, x * 30);
			}
			x++;
		}
		y++;
	}

}

int	draw_player_rect(t_map_data *data)
{
	unsigned int y;
	unsigned int x;

	data->p_widht = 10;
	data->p_height = 10;

	y = data->r_play->y;
	while (y < data->r_play->y + data->p_height)
	{
		x = data->r_play->x;
		while (x < data->r_play->x + data->p_widht)
		{
			img_pix_put(data->background_img, x, y, 0XFFFFFF);
			x++;
		}
		++y;
	}
	return (0);
}
void	draw_background(t_map_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->background_img->addr = mlx_get_data_addr(data->background_img->mlx_img,
			&data->background_img->bpp, &data->background_img->line_len,
			&data->background_img->endian);
	while (y < 1900)
	{
		x = 0;
		while (x < 1080)
		{
			img_pix_put(data->background_img, y, x, 0X000000);
			x++;
		}
		y++;
	}
	draw_player_rect(data);
	draw_wall(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background_img->mlx_img, 0, 0);
}
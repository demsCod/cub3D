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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == WALL)
			{
				drawing_wall(data, j * 30, i * 30);
			}
			i++;
		}
		j++;
	}

}
void	draw_background(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->background_img->addr = mlx_get_data_addr(data->background_img->mlx_img,
			&data->background_img->bpp, &data->background_img->line_len,
			&data->background_img->endian);
	while (j < 1900)
	{
		i = 0;
		while (i < 1080)
		{
			img_pix_put(data->background_img, j, i, 0X000000);
			i++;
		}
		j++;
	}
	draw_player_rect(data);
	draw_wall(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background_img->mlx_img, 0, 0);
}

int	draw_player_rect(t_map_data *data)
{
	unsigned int i;
	unsigned int j;

	data->p_widht = 10;
	data->p_height = 10;

	i = data->r_play->y;
	while (i < data->r_play->y + data->p_height)
	{
		j = data->r_play->x;
		while (j < data->r_play->x + data->p_widht)
		{
			img_pix_put(data->background_img, i, j, 0XFFFFFF);
			j++;
		}
		++i;
	}
	return (0);
}
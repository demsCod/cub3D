#include "../../includes/cub3D.h"

void	img_pix_put(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void drawing_wall(t_map_data *data, int x, int y)
{
	data->w_widht = RECT_WALL_SIZE;
	data->w_height = RECT_WALL_SIZE;
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
void draw_line(t_img_data *img, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx, sy;
	int err;

	// Déterminer les directions x et y
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;

	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	// Calcul de l'erreur initiale sans ternaire
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;

	int e2;

	while (1)
	{
		img_pix_put(img, x1, y1, color);  // Placer un pixel à la position courante

		if (x1 == x2 && y1 == y2)
			break;

		e2 = err;

		// Mise à jour de x1 et y1 en fonction de l'erreur
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}


int	draw_player_rect(t_map_data *data)
{
	unsigned int y;
	unsigned int x;
	int player_center_x;
	int player_center_y;
	int line_length;
	int line_end_x;
	int line_end_y;

	data->p_widht = RECT_P_SIZE;
	data->p_height = RECT_P_SIZE;

	player_center_x = data->r_play->x + data->p_widht / 2;
	player_center_y = data->r_play->y + data->p_height / 2;
	y = data->r_play->y;
	while (y < data->r_play->y + data->p_height)
	{
		x = data->r_play->x;
		while (x < data->r_play->x + data->p_widht)
		{
			img_pix_put(data->background_img, x, y, WHITE_PIXEL);
			x++;
		}
		++y;
	}

	line_length = 50; 
	line_end_x = player_center_x + cos(data->r_play->a) * line_length;
	line_end_y = player_center_y - sin(data->r_play->a) * line_length;
	draw_line(data->background_img, player_center_x, player_center_y, line_end_x, line_end_y, RED_PIXEL);

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
	while (y < SCREEN_WIDHT_SIZE)
	{
		x = 0;
		while (x < SCREEN_HEIGHT_SIZE)
		{
			if (x % 30 == 0 || y % 30 == 0)
				img_pix_put(data->background_img, y, x, GREY_PIXEL);
			else
				img_pix_put(data->background_img, y, x, BLACK_PIXEL);
			x++;
		}
		y++;
	}
	y = 0;
	draw_wall(data);
	while (y < SCREEN_WIDHT_SIZE)
	{
		x = 0;
		while (x < SCREEN_HEIGHT_SIZE)
		{
			if (x % 30 == 0 || y % 30 == 0)
				img_pix_put(data->background_img, y, x, GREY_PIXEL);
			x++;
		}
		y++;
	}
	draw_player_rect(data);
	//raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background_img->mlx_img, 0, 0);
}
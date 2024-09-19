#include "../../includes/cub3D.h"

void	img_pix_put(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void drawing_wall(t_map_data *data, int x, int y)
{
	int i;
	int j;

	i = y;
	while (i < y + RECT_WALL_SIZE)
	{
		j = x;
		while (j < x + RECT_WALL_SIZE)
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
				drawing_wall(data, y * RECT_WALL_SIZE, x * RECT_WALL_SIZE);
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

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;

	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	int e2;

	while (1)
	{
		img_pix_put(img, x1, y1, color);  
		if (x1 == x2 && y1 == y2)
			break;
		e2 = err;
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
	int y;
	int x;
	
	y = data->r_play->y;
	while (y < data->r_play->y + RECT_P_SIZE)
	{
		x = data->r_play->x;
		while (x < data->r_play->x + RECT_P_SIZE)
		{
			img_pix_put(data->background_img, x, y, WHITE_PIXEL);
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
	// double cameraX = 2 * data->r_play->x ;
	data->background_img->addr = mlx_get_data_addr(data->background_img->mlx_img,
			&data->background_img->bpp, &data->background_img->line_len,
			&data->background_img->endian);
	while (y < SCREEN_WIDHT_SIZE)
	{
		x = 0;
		while (x < SCREEN_HEIGHT_SIZE)
		{
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
			if (x % RECT_WALL_SIZE == 0 || y % RECT_WALL_SIZE == 0)
				img_pix_put(data->background_img, y, x, GREY_PIXEL);
			x++;
		}
		y++;
	}
	draw_player_rect(data);
	draw_head(data);
	//raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background_img->mlx_img, 0, 0);
}
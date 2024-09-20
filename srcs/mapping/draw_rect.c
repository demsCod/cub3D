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
	// int	y;
	// int	x;

	// y = 0;
	// x = 0;

	
	if (data->background_img == NULL)
	{
		fprintf(stderr, " get_data_addr fail\n");
		exit (1);
	}
	// while (y < SCREEN_WIDHT_SIZE)
	// {
	// 	x = 0;
	// 	while (x < SCREEN_HEIGHT_SIZE)
	// 	{
	// 		img_pix_put(data->background_img, y, x, BLACK_PIXEL);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// draw_wall(data);
	// y = 0;
	// while (y < SCREEN_WIDHT_SIZE)
	// {
	// 	x = 0;
	// 	while (x < SCREEN_HEIGHT_SIZE)
	// 	{
	// 		if (x % RECT_WALL_SIZE == 0 || y % RECT_WALL_SIZE == 0)
	// 			img_pix_put(data->background_img, y, x, GREY_PIXEL);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// draw_player_rect(data);
	// draw_ray(data);
	// draw_camera(data, data->r_play,  data->draw);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->background_img->mlx_img, 0, 0);
}


void draw_ray(t_map_data *data)
{
	int player_center_x;
    int player_center_y;
    double line_length;
    int line_end_x = 1;
	int line_end_y  = 1;
	int x;
    int y;
    float a;
    int i;
	
    a = data->r_play->a;
	line_length = 0.1;
    player_center_x = data->r_play->x + RECT_P_SIZE / 2;
    player_center_y = data->r_play->y + RECT_P_SIZE / 2;
	i = 0;
	while (i < 60)
    {
        a+=0.01;
		if (a < 0)
			a += 2 * PI;
        if (a > 2 * PI)
			a -= 2 * PI;
        line_length = 0;
        while (line_length < 900)
        {
            line_end_x = player_center_x + cos(a) * line_length;
            line_end_y = player_center_y + sin(a) * line_length;
            y = line_end_y / RECT_WALL_SIZE;
            x = line_end_x / RECT_WALL_SIZE;
            if (y < SCREEN_HEIGHT_SIZE && x < SCREEN_WIDHT_SIZE)
            {
                if (data->map[y][x] == WALL)
                    break;
            }
            line_length+=1.0;
        }
		draw_line(data->background_img, player_center_x , player_center_y, line_end_x, line_end_y, GREEN_PIXEL);
        i++;
	}
}

void draw_head(t_map_data *data)
{
    int player_center_x;
    int player_center_y;
    double line_length;
    int line_end_x = 1;
	int line_end_y  = 1;
	int x;
    int y;
    float a;

    a = data->r_play->a;
    line_length = 0.1;
    player_center_x = data->r_play->x + RECT_P_SIZE / 2;
    player_center_y = data->r_play->y + RECT_P_SIZE / 2;
	while (line_length < 30)
    {
            line_end_x = player_center_x + cos(a) * line_length;
            line_end_y = player_center_y + sin(a) * line_length;
            y = line_end_y / RECT_WALL_SIZE;
            x = line_end_x / RECT_WALL_SIZE;
            if (y < SCREEN_HEIGHT_SIZE && x < SCREEN_WIDHT_SIZE)
            {
                if (data->map[y][x] == WALL)
                    break;
            }
            line_length+=1.0;
    }
	draw_line(data->background_img, player_center_x , player_center_y, line_end_x, line_end_y, WHITE_PIXEL);
}

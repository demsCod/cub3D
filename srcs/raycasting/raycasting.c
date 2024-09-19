/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/09/19 20:33:54 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/* 
	  cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
      rayDirX = dirX + planeX * cameraX;
      rayDirY = dirY + planeY * cameraX;
*/

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
		if (i %2 == 0)
			draw_line(data->background_img, player_center_x , player_center_y, line_end_x, line_end_y, GREEN_PIXEL);
		else
        	draw_line(data->background_img, player_center_x , player_center_y, line_end_x, line_end_y, WHITE_PIXEL);
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

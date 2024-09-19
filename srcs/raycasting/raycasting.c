/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/09/17 15:54:13 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
    int i;

    line_length = 0.1;
     player_center_x = data->r_play->x + RECT_P_SIZE / 2;
     player_center_y = data->r_play->y + RECT_P_SIZE / 2;
    printf("%f\n", data->r_play->a);
    i = 0;
    a = data->r_play->a;

    while (i < 60)
    {
        a+=0.01;
		if (a < 0)
			a += 2 * PI;
        if (a > 2 * PI)
			a -= 2 * PI;
        line_length = 0;
        while (line_length < 100)
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
/*void raycasting(t_map_data *data)
{
    int r;
    int dof;
    int y_o;
    int x_o;
    float r_x, r_y;
    float r_a;
    float a_tan;

    draw_line(data->background_img, data->r_play->x, data->r_play->y, r_x, r_y, GREEN_PIXEL);
    r++;  // Passe au rayon suivant
    
}*/

/* raycasting(t_map_data *data)
{
    int r;
    int m_x;
    int m_y;
    int m_p;
    int dof;
    int y_o;
    int x_o;
    float r_x;
    float r_y;
    float r_a;
    float a_tan;

    r = 0;
    r_a = data->r_play->a;
    while (r < 0)
    {
        a_tan = -1/tan(r_a);
        if(r_a > PI)
        {
            r_y = (((int)data->r_play->y >> 6) << 6) -0.0001;
            r_x = (data->r_play->y - data->r_play->x) * a_tan + data->r_play->x;
            y_o = -RECT_WALL_SIZE;
            x_o = y_o * a_tan;
        }
        if(r_a < PI)
        {
            r_y = (((int)data->r_play->y >> 6) << 6) + RECT_WALL_SIZE;
            r_x = (data->r_play->y - data->r_play->x) * a_tan + data->r_play->x;
            y_o = RECT_WALL_SIZE;
            x_o = y_o * a_tan;
        }
        if (r_a == 0 || r_a == PI)
        {
            r_x = data->r_play->x;
            r_y = data->r_play->y;
            dof = 8;
        }
        while (dof < 8)
        {
            m_x = (int)
        }
    }

}*/
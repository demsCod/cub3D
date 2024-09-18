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
#include <math.h>

void raycasting(t_map_data *data)
{
    int y = 0;
    int x = 0;

    float r_x = data->r_play->x;
    float r_y;

    while(r_x != data->r_play->x + 10.0)
    {
        r_y = data->r_play->y;
        while (1)
        {
            x = r_x / RECT_WALL_SIZE;
            y = r_y / RECT_WALL_SIZE;
            if (data->map[y][x] == WALL)
                break ;
            img_pix_put(data->background_img, r_x, r_y, RED_PIXEL);
            r_y += 2.0;
        }
        r_x++;
    }
}
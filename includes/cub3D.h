/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/09/16 22:38:18 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <errno.h>
# include <stdbool.h>

# define KEYPRESS 2
# define KEYRELEASE 3

#define RED_PIXEL 0xFF0000
#define BLUE_PIXEL 0x000000FF
#define BLACK_PIXEL 0x000000
#define GREEN_PIXEL 0X00FF00

# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'

# define MALLOC_FAIL "Error\nMalloc failed"
# define OPEN_FAIL "Error\nOpen failed"
# define MAP_KO "Error\nThe map is not correct"
# define WINDOWSFAIL "Error\nWindows initiation failed"

typedef struct o_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img_data;

typedef struct s_player_rect
{
    float	x;
    float	y;
    int width;
    int height;
    int color;
}	t_rect_player;

typedef struct s_wall_rect
{
    float	x;
    float	y;
    int width;
    int height;
    int color;
}	t_wall_rect;

typedef struct map_data
{
	int fd;
	char **map;
	void *mlx_ptr;
	void *mlx_win;
	int   p_height;
	int   p_widht;
	int   w_height;
	int   w_widht;
	t_img_data	*player_img;
	t_img_data	*wall_img;
	t_img_data	*background_img;
	t_rect_player *r_play;
	t_wall_rect	  *r_wall;
}	t_map_data;

int draw_player_rect(t_map_data *data);
void	draw_background(t_map_data *data);
#endif

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

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <errno.h>
# include <stdbool.h>
# include <sys/sysmacros.h>
# include <math.h>


# define PI 3.1415926535
# define RECT_P_SIZE 10
# define RECT_WALL_SIZE 30
# define SCREEN_WIDHT_SIZE 1900
# define SCREEN_HEIGHT_SIZE 1080
# define KEYPRESS 2
# define KEYRELEASE 3

#define RED_PIXEL 0xFF0000
#define BLUE_PIXEL 0x000000FF
#define GREEN_PIXEL 0X00FF00
#define WHITE_PIXEL 0XFFFFFF
#define GREY_PIXEL 0X808080
#define BLACK_PIXEL 0X000000

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
    float   d_y;
    float   d_x;
    float   a;
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

void	img_pix_put(t_img_data *img, int x, int y, int color);
int     draw_player_rect(t_map_data *data);
void	draw_background(t_map_data *data);
void	draw_wall(t_map_data *data);
void    drawing_wall(t_map_data *data, int x, int y);
int	    keyfonction(int keycode, t_map_data *data);
void	init_game(t_map_data *data);
int	    create_map(t_map_data *data);
int     find_player(t_map_data *data, char option);
void    raycasting(t_map_data *data);
#endif

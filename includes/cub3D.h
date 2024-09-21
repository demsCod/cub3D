/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 21:12:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/09/20 21:16:17 by mdembele         ###   ########.fr       */
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
# define FOV 60
# define KEYPRESS 2
# define KEYRELEASE 3
# define NUM_TEXTURES 4

#define RED_PIXEL 0xFF0000
#define BLUE_PIXEL 0x000000FF
#define GREEN_PIXEL 0X00FF00
#define WHITE_PIXEL 0XFFFFFF
#define GREY_PIXEL 0X808080
#define BLACK_PIXEL 0X000000

# define TEXTURE_SIZE 10
# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'

# define MALLOC_FAIL "Error\nMalloc failed"
# define OPEN_FAIL "Error\nOpen failed"
# define MAP_KO "Error\nThe map is not correct"
# define WINDOWSFAIL "Error\nWindows initiation failed"

typedef enum e_cardinal_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_cardinal_direction;

typedef struct o_img
{
    void	*img;
    int	*addr;
	char	*path;
	int		widht;
	int		height;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img_data;

typedef struct s_player_rect
{
    float	x;
    float	y;
    float   d_x;
    float   d_y;
    float   a;
	float   a_y;
	float   a_x;
	double camera_X;
	double camera_Y;
	double plane_X;
	double plane_Y;
	double ray_dir_x;
	double ray_dir_y;
	double delta_dist_x;
	double delta_dist_y;
	double side_dist_x;
	double side_dist_y;
	int 	step_x;
	int 	step_y;
	int 	map_x;
	int 	side;
	int		map_y;
	double 	wall_dist;
	double  wall_x;
	int 	line_height;
	int 	draw_start;
	int		 draw_end;
}	t_ray_player;

typedef struct s_data
{
	// ...
	int *texture_buffer[NUM_TEXTURES];
} t_draw_data;


typedef struct map_data
{
	long	floor_hex;
	long	ceiling_hex;
	int						col;
	int						row;
	char					index;
	int						start_row;
	int						start_col;
	int						start_map;
	char					*path_texture[4];
	int						offset;
	int						**map_int;
	char **pixels;
	int fd;
	char **map;
	void *mlx_ptr;
	void *mlx_win;
	void *mlx_win2;
	int					*texture_buffer[4];
	int   p_height;
	int   p_widht;
	int   w_height;
	int   w_widht;
	bool start;
	t_img_data	*player_img;
	t_img_data	*wall_img;
	t_img_data	*background_img;
	t_img_data	*background_img2;
	t_ray_player *r_play;
	t_draw_data  *draw;
}	t_map_data;

/*drawing*/
void 	draw_line(t_img_data *img, int x1, int y1, int x2, int y2, int color);
int     draw_player_rect(t_map_data *data);
void	draw_background(t_map_data *data);
void 	init_camera(t_map_data *data);
void	draw_wall(t_map_data *data);
void	img_pix_put(t_img_data *img, int x, int y, int color);
void    drawing_wall(t_map_data *data, int x, int y);
int	    create_map(t_map_data *data);
/*gaming*/
int	    keyfonction(int keycode, t_map_data *data);
void	init_game(t_map_data *data);
int     find_player(t_map_data *data, char option);
void    draw_head(t_map_data *data);
void 	draw_ray(t_map_data *data);
void 	draw_camera (t_map_data *data, t_ray_player *r_play, t_draw_data *draw, int x);
void init_camera(t_map_data *data);
#endif

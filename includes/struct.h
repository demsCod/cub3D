/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:38 by ibaby             #+#    #+#             */
/*   Updated: 2024/10/23 19:22:04 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#define TEXTURE_SIZE 128
# define NUM_TEXTURES 4

# define WIN_WIDHT 1900
# define WIN_HEIGHT 1080
typedef enum e_cardinal_direction
{
	NORTH = 1,
	SOUTH = 0,
	WEST = 3,
	EAST = 2
}	t_cardinal_direction;

typedef struct s_map
{
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char 	*path_texture[4];
	int 	*texture_buffer[4];
	int		flo_texture;
	int		cei_texture;
	char	**map;
	int		map_fd;
	char	player_direction;
	int 	floor_hex;
	int 	ceiling_hex;
	char 	index;
	int 	start_row;
	int 	start_col;
	int 	str_index;
	int		offset;
}	t_map;



// Before starting, ensure that you have installed both the mlx
  // and glfw libraries
// To successfully run your file, ensure that you have included the 'mlx' library.
// When compiling the code, you must include the necessary frameworks
  // and link the glfw library, as well as the libmlx.a.
// The flag (-O3 -ffast-math) is used for optimization.
// The flag (-framework) is used to specify the required frameworks.
// the flag (-lglfw) is for linking the glfw library
// the flag (-L) is for the path to the glfw library
// the flag (-o) is for the name of the executable file
// to run the program (./cub)

// example:
// cc -O3 -ffast-math -framework Cocoa -framework OpenGL -framework IOKit -lglfw (path to libmlx42.a) -L(path to glfw library) cub3d.c -o cub

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX/MLX42.h" // include the mlx library

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

typedef struct s_player //the player structure
{
 int  plyr_x; // player x position in pixels
 int  plyr_y; // player y position in pixels
 double angle; // player angle
 float fov_rd; // field of view in radians
 int  rot; // rotation flag
 int  l_r; // left right flag
 int  u_d; // up down flag
} t_player;

typedef struct s_ray //the ray structure
{
 double ray_ngl; // ray angle
 double distance; // distance to the wall
 int  flag;  // flag for the wall
} t_ray;

typedef struct s_data //the data structure
{
 char **map2d; // the map
 int  p_x;  // player x position in the map
 int  p_y;  // player y position in the map
 int  w_map;  // map width
 int  h_map;  // map height
} t_data;

typedef struct s_mlx //the mlx structure
{
 mlx_image_t  *img; // the image
 mlx_t   *mlx_p; // the mlx pointer
 t_ray   *ray; // the ray structure
 t_data   *dt; // the data structure
 t_player  *ply; // the player structure
} t_mlx;
view raw

typedef struct s_all
{
	t_map 		*map;
	t_player	*player;
	t_gun		*gun;
}	t_all;

typedef struct s_img_data
{
	char	*pwwath;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img_data;


 


#endif
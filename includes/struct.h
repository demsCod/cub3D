/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:38 by ibaby             #+#    #+#             */
/*   Updated: 2024/10/25 15:46:19 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TEXTURE_SIZE 128
# define NUM_TEXTURES 4

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

typedef enum e_cardinal_direction
{
	NORTH = 1,
	SOUTH = 0,
	WEST = 3,
	EAST = 2
}				t_cardinal_direction;

typedef struct s_map
{
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	char		*path_texture[4];
	int			*texture_buffer[4];
	int			flo_texture;
	int			cei_texture;
	char		**map;
	int			p_x;
	int			p_y;
	int			w_map;
	int			h_map;
	int			map_fd;
	char		player_direction;
	int			floor_hex;
	int			ceiling_hex;
	char		index;
	int			start_row;
	int			start_col;
	int			str_index;
	int			offset;
}				t_map;

typedef struct s_player //the player structure
{
	int plyr_x;   // player x position in pixels
	int plyr_y;   // player y position in pixels
	double angle; // player angle
	float fov_rd; // field of view in radians
	int rot;      // rotation flag
	int l_r;      // left right flag
	int u_d;      // up down flag
}				t_player;

typedef struct s_ray //the ray structure
{
	double ray_ngl;  // ray angle
	double distance; // distance to the wall
	int flag;        // flag for the wall
}				t_ray;

typedef struct s_mlx //the mlx structure
{
	void  *mlx_p;     // the mlx pointer
	void  *win_p;
	t_ray *ray;       // the ray structure
	t_map *dt;       // the data structure
	t_player *ply;    // the player structure
}				t_all;



typedef struct s_img_data
{
	char		*pwwath;
	void		*img;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img_data;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:38 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/27 17:09:40 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#define TEXTURE_SIZE 256
# define NUM_TEXTURES 4
typedef enum e_cardinal_direction
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_cardinal_direction;

typedef struct s_map
{
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char 	*path_texture[4];
	int 	*texture_buffer[NUM_TEXTURES];
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


typedef struct s_dir
{
    double x;
    double y;
}   t_dir;

typedef struct s_plane
{
    double x;
    double y;
}   t_plane;


typedef struct s_camera
{
    double x;
    double y;
}   t_camera;

typedef struct s_ray
{
    t_dir dir;
}   t_ray;

typedef struct s_delta_distance
{
    double x;
    double y;
}   t_delta_distance;

typedef struct s_wall_data
{
	int		line_height;
	double 	wall_dist;
	int		draw_start;
	int		draw_end;
}	t_wall_data;


typedef struct s_data
{
	int *texture_buffer[NUM_TEXTURES];
} t_data;

typedef struct s_player
{
	char	initial_direction;
	double 	x;
    double 	y;
	double 	dir_x;
    double 	dir_y;
	double 	ray_dir_x;
    double 	ray_dir_y;
	double  camera_x;
	double	plane_x;
	double	plane_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double 	side_dist_x;
	double 	side_dist_y;
	int		side;
	int		map_x;
	int		map_y;
	int 	step_x;
	int 	step_y;
	int		line_height;
	double	wall_dist;
	int		draw_start;
	int		draw_end;
	double	wall_x;

	t_data	data;
	int		**pixel_map;
	void	*mlx_ptr;
	void	*win_ptr;

}	t_player;


typedef struct s_gun {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
} t_gun;


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
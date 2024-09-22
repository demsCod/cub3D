#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "../../includes/includes.h"

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

typedef struct s_pos
{
    double x;
    double y;
}   t_pos;

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

typedef struct s_player
{
	char	initial_direction;
	t_pos	pos;
	t_plane plane;
	t_dir	dir;
}	t_player;
void init_player_data(t_player *player); 

# endif
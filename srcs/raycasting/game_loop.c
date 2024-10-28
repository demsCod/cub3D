#include "raycasting.h"

void free_2d_tab_int(int **tab, int index)
{
	int i = 0;
	while (index > 0)
	{
		free(tab[i]);
		--index;
		i++;
	}
}


int check_circle(float angle, char c) 
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
		return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
		return (1);
	}
	return (0);
}

int inter_check(float angle, float *inter, float *step, bool is_horizon) 
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int wall_hit(float x, float y, t_all *all) // check the wall hit
{
	int  x_m;
	int  y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE); // get the x position in the map
	y_m = floor (y / TILE_SIZE); // get the y position in the map
	if ((y_m >= all->dt->h_map || x_m >= all->dt->w_map))
		return (0);
	if (all->dt->map[y_m] && x_m <= (int)strlen(all->dt->map[y_m]))
		if (all->dt->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

float get_horizontal_size(t_all *all)
{
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int  pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE * tan(all->ray->ray_ngl);
	h_y = floor(all->ply->plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(all->ray->ray_ngl, &h_x, &x_step, false);
	h_x = all->ply->plyr_x + (h_y - all->ply->plyr_y) / tan(all->ray->ray_ngl);
	if ((check_circle(all->ray->ray_ngl, 'y') && x_step > 0) || (!check_circle(all->ray->ray_ngl, 'y') && x_step < 0)) // check y_step value
		x_step *= -1;
	while(wall_hit(h_x , h_y - pixel, all))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - all->ply->plyr_x, 2) + pow(h_y - all->ply->plyr_y, 2)));
}

float get_vertical_size(t_all *all)
{
	float v_x;
	float v_y;
	float x_step;
	float y_step;
	int  pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(all->ray->ray_ngl);
	v_x = floor(all->ply->plyr_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(all->ray->ray_ngl, &v_x, &x_step, false);
	v_y = all->ply->plyr_y + (v_x - all->ply->plyr_x) * tan(all->ray->ray_ngl);
	if ((check_circle(all->ray->ray_ngl, 'x') && y_step < 0) || (!check_circle(all->ray->ray_ngl, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while(wall_hit(v_x - pixel, v_y, all))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - all->ply->plyr_x, 2) + pow(v_y - all->ply->plyr_y, 2)));
}

void casting_ray(t_all *all)
{
	int x;
	double horizon;
	double vertical;

	x = 0;
	all->ray->ray_ngl = all->ply->angle - (all->ply->fov_rd / 2);
	while(x < S_W)
	{
		all->ray->flag = 0;
		horizon = get_horizontal_size(all);
		vertical = get_vertical_size(all);
		printf("%f --- %f\n", horizon, vertical);
		if (vertical <= horizon)
			all->ray->distance = vertical;
		else
		{
			all->ray->distance = horizon;
			all->ray->flag = 1;
		}
		x++;
		all->ray->ray_ngl += (all->ray->ray_ngl / S_W);
	}
}
int game_loop(t_all *all)
{
	int i;

    i = ft_create_pixel_map(all);
	if (i == -1)
        exit(92);
    casting_ray(all);
    // ft_draw_pixel_map(all->player, all->map, all);
	free_2d_tab_int(all->dt->pixel_map, i);
    return (0);
}
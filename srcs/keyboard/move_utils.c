/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:18:49 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 16:58:04 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"
#include <time.h>

double	ft_get_delta(void)
{
	static clock_t	last_time;
	clock_t			current_time;
	double			delta;

	last_time = 0;
	current_time = clock();
	delta = (double)(current_time - last_time) / CLOCKS_PER_SEC;
	last_time = current_time;
	if (delta > MAX_DELTA)
		delta = MAX_DELTA;
	return (delta);
}

static int	ft_check_bounds(int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_x >= WIN_WIDHT || map_y >= WIN_HEIGHT)
		return (1);
	return (0);
}

int	ft_check_margin_point(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (ft_check_bounds(map_x, map_y))
		return (1);
	return (map->map[map_y][map_x] == '1');
}

int	ft_is_wall(t_map *map, double x, double y)
{
	if (ft_check_margin_point(map, x + WALL_MARGIN, y)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y)
		|| ft_check_margin_point(map, x, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x, y - WALL_MARGIN)
		|| ft_check_margin_point(map, x + WALL_MARGIN, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x + WALL_MARGIN, y - WALL_MARGIN)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y + WALL_MARGIN)
		|| ft_check_margin_point(map, x - WALL_MARGIN, y - WALL_MARGIN))
		return (1);
	return (ft_check_margin_point(map, x, y));
}

void	ft_rotate_vectors(t_player *r, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = r->dir_x;
	old_plane_x = r->plane_x;
	r->dir_x = r->dir_x * cos(rot_speed) - r->dir_y * sin(rot_speed);
	r->dir_y = old_dir_x * sin(rot_speed) + r->dir_y * cos(rot_speed);
	r->plane_x = r->plane_x * cos(rot_speed) - r->plane_y * sin(rot_speed);
	r->plane_y = old_plane_x * sin(rot_speed) + r->plane_y * cos(rot_speed);
}

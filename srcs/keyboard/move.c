/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:18:49 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 17:22:20 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"
#include <time.h>

int	ft_move_up(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x + r->dir_x * move_speed;
	new_y = r->y + r->dir_y * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_move_down(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x - r->dir_x * move_speed;
	new_y = r->y - r->dir_y * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_strafe_left(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x - r->dir_y * move_speed;
	new_y = r->y + r->dir_x * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_strafe_right(t_player *r, t_map *map)
{
	double	delta_time;
	double	move_speed;
	double	new_x;
	double	new_y;

	delta_time = ft_get_delta();
	move_speed = MOVE_SPEED * delta_time;
	new_x = r->x + r->dir_y * move_speed;
	new_y = r->y - r->dir_x * move_speed;
	return (ft_try_move(r, map, new_x, new_y));
}

int	ft_key_function(int keycode, t_all *data)
{
	if (keycode == XK_Escape)
		free_all_exit(data);
	if (keycode == XK_Left)
		ft_move_left(data->player);
	if (keycode == XK_Right)
		ft_move_right(data->player);
	if (keycode == XK_Up || keycode == XK_w)
		ft_move_up(data->player, data->map);
	if (keycode == XK_Down || keycode == XK_s)
		ft_move_down(data->player, data->map);
	if (keycode == XK_a)
		ft_strafe_left(data->player, data->map);
	if (keycode == XK_d)
		ft_strafe_right(data->player, data->map);
	return (0);
}

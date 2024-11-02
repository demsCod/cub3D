/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:18:49 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 16:53:35 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	ft_move_right(t_player *r)
{
	double	delta_time;
	double	rot_speed;

	delta_time = ft_get_delta();
	rot_speed = -ROT_SPEED * delta_time;
	ft_rotate_vectors(r, rot_speed);
	return (0);
}

int	ft_move_left(t_player *r)
{
	double	delta_time;
	double	rot_speed;

	delta_time = ft_get_delta();
	rot_speed = ROT_SPEED * delta_time;
	ft_rotate_vectors(r, rot_speed);
	return (0);
}

int	ft_try_move(t_player *r, t_map *map, double new_x, double new_y)
{
	if (!ft_is_wall(map, new_x, new_y))
	{
		r->x = new_x;
		r->y = new_y;
	}
	return (0);
}

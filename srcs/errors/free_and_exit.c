/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:00:40 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 21:04:58 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	free_and_exit(int status, t_map *map)
{
	ft_free(map->NO_texture);
	ft_free(map->SO_texture);
	ft_free(map->EA_texture);
	ft_free(map->WE_texture);
	ft_free(map->cei_texture);
	ft_free(map->flo_texture);
	close(map->map_fd);
	free_2d_str(map->map);
	exit(status);
}

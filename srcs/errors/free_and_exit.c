/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:00:40 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/06 13:30:54 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	free_2d_tab_int(int **tab, int index);

void	free_and_exit(int status, t_map *map)
{
	ft_free(map->no_texture);
	ft_free(map->so_texture);
	ft_free(map->ea_texture);
	ft_free(map->we_texture);
	ft_free(map->path_texture[0]);
	ft_free(map->path_texture[1]);
	ft_free(map->path_texture[2]);
	ft_free(map->path_texture[3]);
	if (map->map_fd != 0 && map->map_fd != 1 && map->map_fd != 2
		&& map->map_fd != -1)
		close(map->map_fd);
	free_2d_str(map->map);
	exit(status);
}

void	free_all_exit(int status, t_all *all)
{		
	if (all->player->mlx_ptr)
	{
		if (all->player->win_ptr)
			mlx_destroy_window(all->player->mlx_ptr, all->player->win_ptr);
		mlx_destroy_display(all->player->mlx_ptr);
	}
	free(all->player->mlx_ptr);
	free_2d_tab_int(all->map->texture_buffer, 4);
	free_and_exit(status, all->map);
	exit(0);
}

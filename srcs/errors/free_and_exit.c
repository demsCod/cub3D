// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   free_and_exit.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/18 21:00:40 by ibaby             #+#    #+#             */
// /*   Updated: 2024/10/03 20:33:49 by mdembele         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "error.h"
// void free_2d_tab_int(int **tab, int index);
// void	free_and_exit(int status, t_map *map)
// {
// 	ft_free(map->NO_texture);
// 	ft_free(map->SO_texture);
// 	ft_free(map->EA_texture);
// 	ft_free(map->WE_texture);
// 	if (map->map_fd != 0 && map->map_fd != 1 && map->map_fd != 2
// 		&& map->map_fd != -1)
// 		close(map->map_fd);
// 	free_2d_str(map->map);
// 	exit(status);
// }
// void free_all_exit(t_all *all)
// {
// 	mlx_destroy_window(all->player->mlx_ptr, all->player->win_ptr);
// 	mlx_destroy_display(all->player->mlx_ptr);
// 	free(all->player->mlx_ptr);
// 	free_2d_tab_int(all->map->texture_buffer, 3);
// 	free_and_exit(1, all->map);
// 	exit(93);
// }
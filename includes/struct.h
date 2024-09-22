/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:55:38 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 19:49:44 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../srcs/raycasting/raycasting.h"

typedef struct map_data
{
	int fd;
	char **map;
}	t_map_data;

typedef struct s_map
{
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*flo_texture;
	char	*cei_texture;
	char	**map;
	int		map_fd;
	char	player_direction;
}	t_map;

#endif
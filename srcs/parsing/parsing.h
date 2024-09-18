/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:51:29 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 20:04:35 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/cub3D.h"

int		get_map(t_map *map, char *map_path);
int		open_map(char *map_path);

char	*get_info(char *line);
int		info_to_map(char *info, t_map *map, char *type);
bool	need_more_info(t_map *map);
int		add_infos(char *line, t_map *map);

int	check_if_closed(char **map, int j, int i);
int	check_map_char(char c, t_map *map);
int	add_initial_direction(char direction, t_map *map);

#endif
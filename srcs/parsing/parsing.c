/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:38:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/17 13:02:02 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_map(t_map *map, char *map_path)
{
	char	**file;
	int		i;

	map->map_fd = open_map(map_path);
	if (map->map_fd == -1)
		return (EXIT_FAILURE);
	file = read_file(map->map_fd);
	if (file == NULL || file[0] == NULL)
		return (ft_free(file), EXIT_FAILURE);
	i = 0;
	while (ft_strcmp(file[i], "\n") == 0)
		++i;
	while (need_more_info(map) == true)
	{
		add_infos(file[i++], map);
		while (ft_strcmp(file[i], "\n") == 0)
			++i;
	}
	map->map = strdup2d(&file[i]);
	if (map->map == NULL/*  || parse_map(map->map) == EXIT_FAILURE */)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	add_infos(char *line, t_map *map)
{
	char	*info;

	info = get_info(line);
	if (info == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (info_to_map(info, map, "NO"));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (info_to_map(info, map, "SO"));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (info_to_map(info, map, "WE"));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (info_to_map(info, map, "EA"));
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (info_to_map(info, map, "F"));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (info_to_map(info, map, "C"));
	else if (ft_strcmp(line, "\n") == 0)
		return (EXIT_SUCCESS);
	else
		return (double_err(line, ": unrecognized info", false), EXIT_FAILURE);
	return (EXIT_FAILURE);
}

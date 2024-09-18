/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:38:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 19:05:48 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_map(char **map, t_map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\0')
		{
			if (map[j][i] == '0')
			{
				if (check_if_closed(map, j, i) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			else if (check_map_char(map, j , i) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS)
}

int	get_file_infos(char **file, t_map *map)
{
	int	i;

	i = 0;
	while (ft_strcmp(file[i], "\n") == 0)
		++i;
	while (need_more_info(map) == true)
	{
		if (file[i] == NULL)
			return (print_err("cannot find all the infos", false), EXIT_FAILURE);
		if (add_infos(file[i++], map) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		while (file[i] != NULL && ft_strcmp(file[i], "\n") == 0)
			++i;
	}
	map->map = strdup2d(&file[i]);
	if (map->map == NULL/*  || parse_map(map->map) == EXIT_FAILURE */)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_map(t_map *map, char *map_path)
{
	char	**file;

	map->map_fd = open_map(map_path);
	if (map->map_fd == -1)
		return (EXIT_FAILURE);
	file = str2d_file(map->map_fd);
	if (file == NULL || file[0] == NULL)
		return (ft_free(file), EXIT_FAILURE);
	if (get_file_infos(file, map) == EXIT_FAILURE)
		return (free_2d_str(file), EXIT_FAILURE);
	return (free_2d_str(file), EXIT_SUCCESS);
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

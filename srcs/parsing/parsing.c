/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:38:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/07 12:42:03 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <unistd.h>

int	parse_map(char **map, t_map *map_data)
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
				{
					print_err("map is not closed", false);
					return (EXIT_FAILURE);
				}
			}
			else
				if (check_map_char(map, j, i, map_data) == EXIT_FAILURE)
					return (EXIT_FAILURE);
		}
		if (map[j + 1] != NULL)
			map[j][ft_strlen(map[j]) - 1] = '\0';
	}
	return (EXIT_SUCCESS);
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
			return (print_err("cannot find all the infos", false),
				EXIT_FAILURE);
		if (add_infos(file[i++], map) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		while (file[i] != NULL && ft_strcmp(file[i], "\n") == 0)
			++i;
	}
	if (file[i] == NULL)
		return (ft_putendl_fd("Error\nno map", 2), EXIT_FAILURE);
	map->map = strdup2d(&file[i]);
	if (map->map == NULL || parse_map(map->map, map) == EXIT_FAILURE)
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
		return (ft_putendl_fd("Error\nfailed to read file", STDERR_FILENO),
			ft_free(file), EXIT_FAILURE);
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
		return (free(info), EXIT_SUCCESS);
	else
		return (double_err(line, ": unrecognized info", false),
			free(info), EXIT_FAILURE);
}

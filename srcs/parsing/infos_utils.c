/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:02:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 17:11:04 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	info_to_map(char *info, t_map *map, char *type)
{
	char	**target;

	if (ft_strcmp(type, "NO") == 0)
		target = &map->NO_texture;
	else if (ft_strcmp(type, "SO") == 0)
		target = &map->SO_texture;
	else if (ft_strcmp(type, "WE") == 0)
		target = &map->WE_texture;
	else if (ft_strcmp(type, "EA") == 0)
		target = &map->EA_texture;
	else if (ft_strcmp(type, "F") == 0)
		target = &map->flo_texture;
	else if (ft_strcmp(type, "C") == 0)
		target = &map->cei_texture;
	else
		return (free(info), EXIT_FAILURE);
	if (*target != NULL)
		return (print_err("duplicate element", false), free(info),
			EXIT_FAILURE);
	*target = info;
	return (EXIT_SUCCESS);
}

char	*get_info(char *line)
{
	int		i;
	char	*info;

	i = 0;
	if (ft_strchr(line, ' ') == NULL)
		return (double_err("unrecognized info: ", line, false), NULL);
	line = ft_strchr(line, ' ');
	while (line[i] == ' ')
		++i;
	info = ft_strdup(&line[i]);
	if (info == NULL)
		return (NULL);
	i = ft_strlen(info);
	if (info[i - 1] == '\n')
		info[i - 1] = '\0';
	i = -1;
	while (info[++i])
	{
		if (info[i] == true)
			return (double_err("unexpected whitespace in info: ", info, false),
				free(info), NULL);
	}
	return (info);
}

bool	need_more_info(t_map *map)
{
	if (map->NO_texture == NULL)
		return (true);
	else if (map->SO_texture == NULL)
		return (true);
	else if (map->WE_texture == NULL)
		return (true);
	else if (map->EA_texture == NULL)
		return (true);
	else if (map->flo_texture == NULL)
		return (true);
	else if (map->cei_texture == NULL)
		return (true);
	else
		return (false);
}

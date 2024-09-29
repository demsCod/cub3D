/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:02:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/26 21:21:00 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int parse_atou(char *str);
int	color_to_struct(t_map *map, char *info, char type);

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
		return (color_to_struct(map, info, 'F'));
	else if (ft_strcmp(type, "C") == 0)
		return (color_to_struct(map, info, 'C'));
	else
		return (free(info), EXIT_FAILURE);
	if (*target != NULL)
		return (print_err("duplicate element", false), free(info),
			EXIT_FAILURE);
	if (ft_strcmp(type, "F") == 0 || ft_strcmp(type, "C") == 0)
		info = ft_re_strtrim(info, " ");
	if (info == NULL)
		return (print_err("info_to_map: strtrim failed", false), EXIT_FAILURE);
	*target = info;
	return (EXIT_SUCCESS);
}

char	*get_info(char *line)
{
	int		i;
	char	*info;

	i = 0;
	if (ft_strchr(line, ' ') == NULL && ft_strchr(line, '\t'))
		return (double_err("unrecognized info: ", line, false), NULL);
	while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		++i;
	while (line[i] == ' ' || line[i] =='\t')
		++i;
	if (line[i] == '\0' || line[i] == '\n')
		return (double_err("unrecognized info: ", line, false), NULL);
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
	else if (map->flo_texture == -1)
		return (true);
	else if (map->cei_texture == -1)
		return (true);
	else
		return (false);
}

int	color_to_struct(t_map *map, char *info, char type)
{
	char	**split;
	int		tab[3];
	
	if (count_char(info, ',') != 2)
		return (EXIT_FAILURE);
	if ((type == 'C' && map->cei_texture != -1)
		|| (type == 'F' && map->flo_texture != -1))
		return (EXIT_FAILURE);
	split = ft_split(info, ',');
	if (split == NULL)
		return (EXIT_FAILURE);
	if (ft_strlen_2d(split) != 3)
		return (free_2d_str(split), EXIT_FAILURE);
	tab[0] = parse_atou(split[0]);
	tab[1] = parse_atou(split[1]);
	tab[2] = parse_atou(split[2]);
	if (tab[0] == -1 || tab[2] == -1 || tab[2] == -1)
		return (EXIT_FAILURE);
	if (type == 'C')
		map->cei_texture = tab[0] * pow(256, 2) + tab[1] * 265 + tab[2];
	else if (type == 'F')
		map->flo_texture = tab[0] * pow(256, 2) + tab[1] * 265 + tab[2];
	return (free_2d_str(split), EXIT_SUCCESS);
}

int parse_atou(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
		if (number > 255)
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return (number);
}

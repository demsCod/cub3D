/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:02:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/26 20:15:24 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	open_map(char *map_path)
{
	int		fd;
	char	*last_dot;

	last_dot = ft_strrchr(map_path, '.');
	if (last_dot == NULL)
		return (double_err(map_path, ": invalid map format",
			false), -1);
	if (ft_strcmp(last_dot, ".cub") != 0)
		return (double_err(map_path, ": invalid map format", false), -1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (print_err("open_map: open: ", true), -1);
	return (fd);
}

int	check_if_closed(char **map, int j, int i)
{
	if (i == 0 || i + 1 == (int)ft_strlen(map[j]))
		return (EXIT_FAILURE);
	if (j == 0 || j + 1 == (int)ft_strlen_2d(map))
		return (EXIT_FAILURE);
	if ((int)ft_strlen(map[j - 1]) <= i || (int)ft_strlen(map[j + 1]) <= i)
		return (EXIT_FAILURE);
	if (map[j - 1][i] == ' ' || map[j + 1][i] == ' ')
		return (EXIT_FAILURE);
	// - check des diagonales
	// if (map[j - 1][i - 1] == ' ' || map[j - 1][i + 1] == ' ')
	// 	return (EXIT_FAILURE);
	// if (map[j + 1][i - 1] == ' ' || map[j + 1][i + 1] == ' ')
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map_char(char c, t_map *map)
{
	if (c == 'N')
		return (add_initial_direction('N', map));
	else if (c == 'S')
		return (add_initial_direction('S', map));
	else if (c == 'E')
		return (add_initial_direction('E', map));
	else if (c == 'W')
		return (add_initial_direction('W', map));
	else if (c == '1' || c == ' ')
		return (EXIT_SUCCESS);
	else
	{
		ft_putstr_fd("Error\n'", STDERR_FILENO);
		if (c == '\n')
			ft_putstr_fd("\\n", STDERR_FILENO);
		else
			ft_putchar_fd(c, STDERR_FILENO);
		ft_putendl_fd("': unexpected char detected", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
}

int	add_initial_direction(char direction, t_map *map)
{
	if (map->player_direction != 0)
		return (print_err("duplicate player detected", false), EXIT_FAILURE);
	map->player_direction = direction;
	return (EXIT_SUCCESS);
}

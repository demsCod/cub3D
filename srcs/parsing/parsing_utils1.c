/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:02:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/17 11:59:42 by ibaby            ###   ########.fr       */
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
		return (-1);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (print_err("open_map: open: ", true), -1);
	return (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:58:30 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/06 13:23:19 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "../../includes/struct.h"

# include "../../includes/cub3D.h"
# include <stdbool.h>

void	print_err(char *err, bool erno);
char	*replace_newline(char *str);
void	double_err(char *err1, char *err2, bool erno);
void	free_and_exit(int status, t_map *map);
void	free_all_exit(int status, t_all *all);

#endif
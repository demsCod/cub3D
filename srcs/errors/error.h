/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:58:30 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 21:03:09 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../../includes/cub3D.h"

void	print_err(char *err, bool erno);
char	*replace_newline(char *str);
void	double_err(char *err1, char *err2, bool erno);
void	free_and_exit(int status, t_map *map);

#endif
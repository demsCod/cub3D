/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:58:09 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/17 11:48:55 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	print_err(char *err, bool erno)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	replace_newline(err);
	if (erno == true)
	{
		perror(err);
	}
	else if (err != NULL)
	{
		ft_putendl_fd(err, STDERR_FILENO);
	}
}

void	double_err(char *err1, char *err2, bool erno)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	replace_newline(err1);
	replace_newline(err2);
	if (err1 != NULL)
		ft_putstr_fd(err1, STDERR_FILENO);
	if (erno == true)
	{
		perror(err2);
	}
	else if (err2 != NULL)
	{
		ft_putendl_fd(err2, STDERR_FILENO);
	}
}

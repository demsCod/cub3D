/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:22:13 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/17 11:50:50 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/*
replace newlines with '\n'
*/
char	*replace_newline(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (str == NULL || count_char(str, '\n') == 0)
		return (str);
	res = ft_malloc(sizeof(char)
			* (ft_strlen(str) + count_char(str, '\n') + 1));
	if (res == NULL)
		return (str);
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
		{
			res[++j] = '\\';
			res[++j] = 'n';
		}
		else
			res[++j] = str[i];
	}
	res[++j] = '\0';
	return (res);
}

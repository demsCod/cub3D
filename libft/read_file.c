/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:12:18 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/16 17:01:38 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd)
{
	char	*temp;
	char	*str;

	temp = get_next_line(fd);
	if (temp == NULL)
		return (NULL);
	str = NULL;
	while (temp != NULL)
	{
		str = ft_re_strjoin(str, temp);
		ft_free(temp);
		if (str == NULL)
			return (NULL);
		temp = get_next_line(fd);
	}
	return (str);
}

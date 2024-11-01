/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:42:20 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/07 22:20:30 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	if (s)
	{
		uc = (unsigned char)c;
		while (*s)
		{
			if (*s == uc)
				return ((char *)s);
			s++;
		}
		if (uc == '\0')
			return ((char *)s);
	}
	return (NULL);
}

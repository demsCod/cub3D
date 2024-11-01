/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:56:21 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/08 19:47:18 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;
	size_t	total;

	if (s1 && s2)
	{
		i = ft_str_len(s1, '\0');
		j = ft_str_len(s2, '\0');
		total = i + j + 1;
		strjoin = malloc(sizeof(char) * total);
		if (!(strjoin))
			return (free((char *)s1), NULL);
		ft_strlcpy(strjoin, s1, i + 1);
		ft_strlcpy(strjoin + i, (char *)s2, j + 1);
		free((char *)s1);
		return (strjoin);
	}
	return (NULL);
}

void	ft_cpynl(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_split_strdup(const char *s)
{
	char	*tab;

	if (s)
	{
		tab = malloc(sizeof(char) * (ft_str_len(s, '\0') + 1));
		if (tab == NULL)
			return (NULL);
		ft_strlcpy(tab, s, ft_str_len(s, '\0') + 1);
		return (tab);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:00:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/02 18:59:55 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_cpynl(char *dest, char *src);
char	*get_next_line(int fd);
char	*ft_split_strjoin(const char *s1, const char *s2);
char	*ft_split_strdup(const char *s);
size_t	ft_str_len(const char *str, char c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_close(int *fd);
void	ft_free(void **str);
void	ft_free_2d(void ***str);
void	ft_dup2(int fd1, int fd2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_printabln(char **str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_re_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *str, char set);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlen_tab(char **str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:32:32 by ibaby             #+#    #+#             */
/*   Updated: 2024/10/25 15:34:44 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../srcs/errors/error.h"
# include "../srcs/libft/libft.h"
# include "../srcs/raycasting/raycasting.h"
# include "struct.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846

# define KEYPRESS 2
# define KEYRELEASE 3

# define WALL '1'
# define GROUND '0'
# define PLAYER 'P'

# define MALLOC_FAIL "Error\nMalloc failed"
# define OPEN_FAIL "Error\nOpen failed"
# define MAP_KO "Error\nThe map is not correct"
# define WINDOWSFAIL "Error\nWindows initiation failed"

#endif
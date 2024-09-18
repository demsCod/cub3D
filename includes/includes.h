/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:32:32 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/17 10:00:16 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../srcs/libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "struct.h"
# include "../srcs/errors/error.h"

# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:32:32 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/16 18:33:24 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "struct.h"
# include "../libft/libft.h"
# include <errno.h>
# include <stdbool.h>

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
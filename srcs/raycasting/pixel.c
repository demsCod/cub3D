#include "raycasting.h"


int	ft_create_pixel_map(t_all *all)
{
	int	i;

	i = -1;
	while (++i < S_H)
	{
		all->dt->pixel_map[i] = ft_calloc(sizeof(int), S_W);
		if (!all-> dt->pixel_map[i])
		    return (-1);
	}
	return (i);
}
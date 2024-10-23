#include "raycasting.h"


int	ft_create_pixel_map(t_player *player)
{
	int	i;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		player->pixel_map[i] = ft_calloc(sizeof(int), WIN_WIDHT);
		if (!player->pixel_map[i])
		    return (-1);
	}
	return (i);
}
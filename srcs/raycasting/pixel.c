#include "raycasting.h"


int	ft_create_pixel_map(t_player *player)
{
	int	i;

	i = -1;
	player->pixel_map = ft_calloc(sizeof(int *), WIN_HEIGHT + 1);
	if (!player->pixel_map)
		return (i);
	while (++i < WIN_HEIGHT)
	{
		player->pixel_map[i] = ft_calloc(sizeof(int), WIN_WIDHT);
		if (!player->pixel_map[i])
		    return (-1);
	}
	return (i);
}
#include "raycasting.h"


bool	ft_create_pixel_map(t_player *player)
{
	int	i;
	int j = -1;

	player->pixel_map = ft_calloc(sizeof(int *), WIN_HEIGHT );
	if (!player->pixel_map)
		return (false);
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		player->pixel_map[i] = ft_calloc(sizeof(int), WIN_WIDHT );
		if (!player->pixel_map[i])
		    return (false);
	}
	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = 0;
		while (++j < WIN_WIDHT)
			player->pixel_map[i][j] = 0xFFFFFF;
	}
	return (true);
}
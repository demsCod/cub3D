#include "../../includes/cub3D.h"

int	init_player_data(t_all *mlx);

int	set_map(t_all *all, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'O' || map[y][x] == 'E'
				|| map[y][x] == 'S')
			{
				all->dt->p_x = x;
				all->dt->p_y = y;
				printf ("%d\n", all->dt->p_x);
				return (EXIT_SUCCESS);
			}
			x++;
		}
		++y;
	}
	return (EXIT_FAILURE);
}

int	init_game_data(t_all *all, t_map *map)
{
	all = ft_calloc(1, sizeof(t_all));
	all->dt = map;
	all->ply =  malloc(sizeof(t_player));
	if (set_map(all, map->map) == 1)
		return (EXIT_FAILURE);
	if (init_player_data(all) == 1)
		return (EXIT_FAILURE);
	open_windows(all, map);
	return (EXIT_SUCCESS);
}
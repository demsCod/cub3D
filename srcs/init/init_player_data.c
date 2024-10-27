
#include "../raycasting/raycasting.h"

int	init_player_data(t_all *mlx)
{
	mlx->ply->plyr_x = mlx->dt->p_x * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->plyr_y = mlx->dt->p_y * TILE_SIZE + TILE_SIZE / 2;
	mlx->ply->angle = M_PI;
	mlx->ply->fov_rd = (FOV * M_PI) / 180;
	return (EXIT_SUCCESS);
}

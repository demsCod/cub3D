#include "../includes/cub3D.h"


int	main(int ac, char **av)
{
	int fd;
	t_map_data *data;

	if (ac == 2)
	{
		if (ft_strlen(av[1]) < 5)
			return (ft_putstr_fd("Error\nextension not valid\n", 2), 1);
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			return (ft_putstr_fd("Error\nextension not valid\n", 2), 1);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr_fd("Error\npermission denied\n", 2), 1);
		data = malloc(sizeof(t_map_data));
		data->fd = fd;
		if (create_map(data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_game(data);
		draw_background(data);
		mlx_hook(data->mlx_win, 02, (1L << 0), keyfonction, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
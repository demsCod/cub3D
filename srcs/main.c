#include "../includes/cub3D.h"


void	ft_render(t_map_data *data)
{

	if (!ft_create_pixel_map(data))
		return ;
	init_camera(data);
	// draw_camera(data);
	// ft_free_void_array((void **)data->pixels, WIN_HEIGHT);
	// ft_draw_pixel_map(data);
}


int	ft_on_loop(t_map_data *data)
{
	if (data->mlx_win == NULL || data->start == false)
		return (0);
	//ft_move_player(data);
	ft_render(data);
	data->start = false;
	return (0);
}

int	ft_on_loop_minimap(t_map_data *data)
{
	if (data->mlx_win2 == NULL || data->start == false)
		return (0);
	//ft_move_player(data);
	draw_background(data);
	data->start = false;
	return (0);
}

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
		data->mlx_ptr = mlx_init();
		if (data->mlx_ptr == NULL)
			exit(162);
		data->mlx_win = mlx_new_window(data->mlx_ptr, SCREEN_HEIGHT_SIZE , SCREEN_WIDHT_SIZE, "CUBE 3D");
		if (data->mlx_win == NULL)
			exit(163);
		mlx_hook(data->mlx_win, 02, (1L << 0), keyfonction, data);
		mlx_loop_hook(data->mlx_ptr, ft_on_loop, data);
		mlx_loop(data->mlx_ptr);
		//mlx_loop_hook(data->mlx_ptr, ft_on_loop_minimap, data);
	}
	return (0);
}
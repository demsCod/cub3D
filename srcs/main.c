#include "../includes/cub3D.h"

int	keyfonction(int keycode, t_map_data *data)
{
	if (keycode == XK_Escape)
	{
		exit(0);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		data->r_play->x += 4.60;
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		data->r_play->y -= 4.60;
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		data->r_play->y += 4.60;
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		data->r_play->x -= 4.60;
	}
	draw_background(data);
	return (0);
}

int	check_item(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != '1' && str[j][i] != '0' && str[j][i] != 'N'
				&& str[j][i] != 'P')
				return (EXIT_FAILURE);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
int	parse_map_error(t_map_data *data)
{
	char	*str;
	char	*temp;

	str = ft_strdup("");
	temp = ft_strdup("");
	while (1)
	{
		str = get_next_line(data->fd);
		if (str == NULL)
			break ;
		temp = ft_re_strjoin(temp, str);
	}
	data->map = ft_split(temp, '\n');
	if (check_item(data->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (0);
}

void	init_game(t_map_data *data)
{
	data->r_play = malloc(sizeof(t_rect_player));
	data->background_img = malloc(sizeof(t_img_data));
	data->player_img = malloc(sizeof(t_img_data));
	data->r_play->x = 0.0;
	data->r_play->y = 0.0;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, 1920, 1080, "CUBE 3D");
	data->background_img->mlx_img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->player_img->mlx_img = mlx_new_image(data->mlx_ptr, 30, 30);
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
		if (parse_map_error(data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_game(data);
		mlx_hook(data->mlx_win, 02, (1L << 0), keyfonction, data);
		mlx_loop(data->mlx_ptr);
	}
	return (0);
}
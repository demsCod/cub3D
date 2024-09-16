#include "../includes/cub3D.h"

int check_item(char **str)
{
	int i;
	int j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] != '1' && str[j][i] != '0' 
				&& str[j][i] != 'N' && str[j][i] != 'P')
				return(EXIT_FAILURE);
			i++;
		}
		j++;	
	}
	return (EXIT_SUCCESS);
	
}
int parse_map_error(t_map_data *data)
{
    char *str;
    char *temp;

    str = ft_strdup("");
    temp = ft_strdup("");

    while (1)
    {
       str = get_next_line(data->fd);
       if (str == NULL)
            break;
       temp = ft_re_strjoin(temp, str);
    }
    data->map = ft_split(temp, '\n');
    if (check_item(data->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
    return(0);
    
}

int     main(int ac, char **av)
{
    int fd;
    t_map_data *data;
	void *mlx_ptr;
	void *mlx_win;

    if(ac == 2)
    {
		mlx_win = NULL;

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
        ft_printabln(data->map, 2);
        mlx_ptr = mlx_init();
		mlx_win = mlx_new_window(mlx_ptr, 1920, 1980, "CUBE 3D");
		mlx_loop(mlx_ptr);
    }
    return (0);
}
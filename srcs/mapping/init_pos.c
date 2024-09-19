#include "../../includes/cub3D.h"

int	create_map(t_map_data *data)
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
	return (0);
}
int find_player(t_map_data *data, char option)
{
	int x;
	int y;

	y =0;
	x = 0;
	while ((data->map[y]))
	{
		x = 0;
		while (data->map[y][x])
		{
			if(data->map[y][x] == PLAYER)
			{
				if (option == 'y')
					return (y);
				return (x);
			}
			x++;
		}
		y++;	
	}
	return (0);
}
void	init_game(t_map_data *data)
{
	data->r_play = malloc(sizeof(t_ray_player));
	data->background_img = malloc(sizeof(t_img_data));
	data->player_img = malloc(sizeof(t_img_data));	
	data->r_play->y =  find_player(data, 'y') * RECT_WALL_SIZE ;
	data->r_play->x = find_player(data, 'x') * RECT_WALL_SIZE ;
	data->r_play->a = 0;
	data->r_play->d_x = 0;
	data->r_play->d_y = 0;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, SCREEN_WIDHT_SIZE, SCREEN_HEIGHT_SIZE, "CUBE 3D");
	data->background_img->mlx_img = mlx_new_image(data->mlx_ptr, SCREEN_WIDHT_SIZE, SCREEN_HEIGHT_SIZE);
}
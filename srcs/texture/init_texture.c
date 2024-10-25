/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:50:22 by mdembele          #+#    #+#             */
/*   Updated: 2024/10/25 15:50:34 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


bool	create_texture_from_img(t_img_data *img, t_map *map, t_cardinal_direction dir)
{
	int	*pixels;
	int	i;
	int	j;

	pixels = ft_calloc(sizeof(int), img->width * img->height);
	if (!pixels)
		return (false);
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			pixels[i * img->width + j] = img->addr[i * img->width + j];
	}
	map->texture_buffer[dir] = pixels;
	return (true);
}


void init_texture_buffer(t_map *map, t_player *player, t_windows *win)
{
	t_img_data	tmp;
	int		i;

	(void)player;
	//map->texture_buffer = malloc(sizeof(int ) * 5);
	map->path_texture[0] = ft_strdup (map->NO_texture);
	map->path_texture[1] = ft_strdup (map->SO_texture);
	map->path_texture[2] = ft_strdup (map->EA_texture);
	map->path_texture[3] = ft_strdup (map->WE_texture);
	i = -1;
	while (++i < 4)
	{
		tmp.img = mlx_xpm_file_to_image(win->mlx_ptr,
				map->path_texture[i], &tmp.width, &tmp.height);
		if (!tmp.img)
			exit(i);
		printf("%d | %d\n", tmp.height, tmp.width);
		tmp.addr = (int *)mlx_get_data_addr(tmp.img,
				&tmp.bpp, &tmp.line_len, &tmp.endian);
		create_texture_from_img(&tmp, map, i);
		mlx_destroy_image(win->mlx_ptr, tmp.img);
	}
}
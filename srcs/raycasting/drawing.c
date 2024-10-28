#include "raycasting.h"


// static t_cardinal_direction ft_get_cardinal_direction(t_player *ray)
// {
//     if (ray->side == 0)  // Collision sur un mur vertical (axe X)
//     {
//         // Si on touche le côté d'un mur (côté Est ou Ouest)
//         if (ray->step_x > 0)  // ⚠️ Utilisation de step_x au lieu de ray_dir_x
//             return (WEST);
//         return (EAST);
//     }
//     else  // Collision sur un mur horizontal (axe Y)
//     {
//         // Si on touche le haut ou le bas d'un mur (Nord ou Sud)
//         if (ray->step_y > 0)  // ⚠️ Utilisation de step_y au lieu de ray_dir_y
//             return (SOUTH);
//         return (NORTH);
//     }
// }


// void	ft_draw_pixel_map(t_player *player, t_map *m, t_all *all)
// {
// 	t_img_data	img;
// 	int		x;
// 	int		y;

//     (void)all;
//     //draw_gun(all);
// 	img.img = mlx_new_image(player->mlx_ptr, WIN_WIDHT,  WIN_HEIGHT);
// 	if (img.img == NULL)
// 		exit(0);
// 	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
// 			&img.line_len, &img.endian);
// 	y = -1;
// 	while (++y < WIN_HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIN_WIDHT)
// 		{ 
// 			if (player->pixel_map[y][x] > 0)
// 				img.addr[y * (img.line_len / 4) + x] = player->pixel_map[y][x];
// 			else if (y < WIN_HEIGHT / 2)
// 				img.addr[y * (img.line_len / 4) + x] = m->cei_texture; //map->cei_texture;
// 			else if (y < WIN_HEIGHT)
// 				img.addr[y * (img.line_len / 4) + x] = m->flo_texture; //map->flo_texture;
// 		}
// 	}
// 	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, img.img, 0, 0);
// 	mlx_destroy_image(player->mlx_ptr, img.img);
// }

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
float nor_angle(float angle) // normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

char 	*get_color(t_all *all, int flag)	// get the color of the wall
{
	all->ray->ray_ngl = nor_angle(all->ray->ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (all->ray->ray_ngl > M_PI / 2 && all->ray->ray_ngl < 3 * (M_PI / 2))
			return (all->dt->WE_texture); // west wall
		else
			return (all->dt->EA_texture); // east wall
	}
	else
	{
		if (all->ray->ray_ngl > 0 && all->ray->ray_ngl < M_PI)
			return (all->dt->SO_texture); // south wall
		else
			return (all->dt->NO_texture); // north wall
	}
}


void	draw_wall(t_all *all, int ray, int t_pix, int b_pix)	// draw the wall
{
	char *text;

	color = get_color(all, all->ray->flag);
	while (t_pix < b_pix)
    {

		my_mlx_pixel_put(all, ray, t_pix++, color);
    }
}

void set_pixel_map(t_all *all, int x)
{
    double	b_pix;
	double	t_pix;
    double wall_h;

    all->ray->distance *= cos(nor_angle(all->ray->ray_ngl - all->ply->angle)); // fix the fisheye
	wall_h = (TILE_SIZE / all->ray->distance) * ((S_W / 2) / tan(all->ply->fov_rd / 2)); // get the wall height
    b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
    if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
   draw_wall
}

void	ft_draw_pixel_map(t_player *player, t_map *m, t_all *all)
{
	t_img_data	img;
	int		x;
	int		y;

    (void)all;
    //draw_gun(all);
	img.img = mlx_new_image(player->mlx_ptr, WIN_WIDHT,  WIN_HEIGHT);
	if (img.img == NULL)
		exit(0);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bpp,
			&img.line_len, &img.endian);
	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDHT)
		{ 
			if (player->pixel_map[y][x] > 0)
				img.addr[y * (img.line_len / 4) + x] = player->pixel_map[y][x];
			else if (y < WIN_HEIGHT / 2)
				img.addr[y * (img.line_len / 4) + x] = m->cei_texture; //map->cei_texture;
			else if (y < WIN_HEIGHT)
				img.addr[y * (img.line_len / 4) + x] = m->flo_texture; //map->flo_texture;
		}
	}
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, img.img, 0, 0);
	mlx_destroy_image(player->mlx_ptr, img.img);
}

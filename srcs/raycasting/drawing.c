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

void set_pixel_map(t_player *player, t_map *map, int x)
{
    t_cardinal_direction dir;
    int tex_x;
	int tex_y;
    int color = 0;
    double pos = 0;
    double step = 0;

    dir = ft_get_cardinal_direction(player);
    tex_x = (int)(player->wall_x * (TEXTURE_SIZE));
    if (player->side == 0 && player->ray_dir_x > 0)
        tex_x = TEXTURE_SIZE - tex_x - 1;
    if (player->side == 1 && player->ray_dir_y < 0)
        tex_x = TEXTURE_SIZE - tex_x - 1;
    step = 1.0 * TEXTURE_SIZE / player->line_height;
    pos = (player->draw_start - WIN_HEIGHT / 2 + player->line_height / 2) * step;
    while (player->draw_start < player->draw_end)
    {
        tex_y = (int)pos & (TEXTURE_SIZE - 1);
        pos += step;
        // Ensure we're not accessing out-of-bounds memory
        if ( tex_x >= 0 && tex_x < TEXTURE_SIZE  && tex_y >= 0 && tex_y < TEXTURE_SIZE )
        {
            color = (map->texture_buffer)[dir][TEXTURE_SIZE * tex_y + tex_x];
            if (dir == NORTH || dir == SOUTH)
                color = (color >> 1) & 0x7F7F7F;
            if (color > 0 && player->draw_start >= 0 && player->draw_start < WIN_HEIGHT && x >= 0 && x < WIN_WIDHT)
                player->pixel_map[player->draw_start][x] = color;
        }
        player->draw_start++;
    }   
}

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

void set_pixel_map(t_all *all, int x)
{
    t_cardinal_direction dir;
    int tex_x;
	int tex_y;
    int color = 0;
    double pos = 0;
    double step = 0;
    double wall_h;
    double	b_pix;
	double	t_pix;

    dir = ft_get_cardinal_direction(player);

    all->ray->distance *= cos(nor_angle(all->ray->ray_ngl - all->ply->angle)); // fix the fisheye
	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->ply->fov_rd / 2)); // get the wall height
    b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
    if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
    while (t_pix < b_pix)
    {
        tex_y = (int)pos & (TILE_SIZE - 1);
        pos += step;
        // Ensure we're not accessing out-of-bounds memory
        if ( tex_x >= 0 && tex_x < TILE_SIZE  && tex_y >= 0 && tex_y < TILE_SIZE )
        {
            color = (map->texture_buffer)[dir][TILE_SIZE * tex_y + tex_x];
            if (dir == NORTH || dir == SOUTH)
                color = (color >> 1) & 0x7F7F7F;
            if (color > 0 && player->draw_start >= 0 && player->draw_start < WIN_HEIGHT && x >= 0 && x < WIN_WIDHT)
                player->pixel_map[player->draw_start][x] = color;
        }
        player->draw_start++;
    }   
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

#include "raycasting.h"


static t_cardinal_direction	ft_get_cardinal_direction(t_player *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->dir_x > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void set_pixel_map(t_player *player, t_map *map, int x)
{

    t_cardinal_direction dir;
    int tex_x;
    int color;
    double pos;
    double step;

    dir = ft_get_cardinal_direction(player);
    tex_x = (int)(player->wall_x * TEXTURE_SIZE);
    if ((player->side == 0 && player->ray_dir_x < 0) || (player->side == 1 && player->ray_dir_y > 0))
        tex_x = TEXTURE_SIZE - tex_x - 1;
    step = 1.0 * TEXTURE_SIZE / player->line_height;
    pos = (player->draw_start - WIN_HEIGHT / 2 + player->line_height / 2) * step;
    while (player->draw_start < player->draw_end)
    {
        pos += step;
        color = (map->texture_buffer)[dir][TEXTURE_SIZE * ((int)pos & (TEXTURE_SIZE - 1)) + tex_x];
        if (dir == NORTH || dir == SOUTH)
            color = (color >> 1) & 0x7F7F7F;
            // add some shading to the north and south walls
        if (color > 0)
            player->pixel_map[player->draw_start][x] = color;
            // your pixel map (int** in this case)
        player->draw_start++;
    }
}

void	ft_draw_pixel_map(t_player *player)
{
	t_img_data	img;
	int		x;
	int		y;

	img.img = mlx_new_image(player->mlx_ptr, WIN_WIDHT,  WIN_HEIGHT);
	if (img.img == NULL)
		return ;
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
				img.addr[y * (img.line_len / 4) + x] = 0x000000; //map->cei_texture;
			else if (y < WIN_HEIGHT -1)
				img.addr[y * (img.line_len / 4) + x] = 0xFFFFFF; //map->flo_texture;
		}
	}
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, img.img, 0, 0);
	mlx_destroy_image(player->mlx_ptr, img.img);
}

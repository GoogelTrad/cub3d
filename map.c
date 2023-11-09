/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:18:57 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/25 20:18:57 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	trace_line(t_data *data, int pos_x, int pos_y)
{
	int x;
	int y;

	y = pos_y;
	x = pos_x;
	while (y < pos_y + GRID)
		my_mlx_pixel_put(&data->img, pos_x, y++, 0x00000000);
	while (x < pos_x + GRID)
		my_mlx_pixel_put(&data->img, x++, pos_y, 0x00000000);
}

void	render_background(t_img *img, t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y] && y * GRID <= HEIGHT)
	{
		x = 0;
		while (data->map[y][x] && x * GRID <= WIDTH)
		{
			if (data->map[y][x] == '1')
				render_rect(img, &data->stock.wall, x * GRID, y * GRID);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'X' || data->map[y][x] == 'N' ||
				data->map[y][x] == 'E' || data->map[y][x] == 'W' || data->map[y][x] == 'S')
				render_rect(img, &data->stock.floor, x * GRID, y * GRID);
			trace_line(data, x * GRID, y * GRID);
			x++;
		}
		y++;
	}
	render_player(img, data, data->player.pos.x, data->player.pos.y);
}*/

void	render_background3d(t_img *img, t_data *data)
{
	int x;
	int y;
	int i;
	int color;

	i = 0;
	y = 0;
	color = 0x00FFFF;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
		if (y > (HEIGHT / 2))
			color = 0x00FF00;
	}
}

void final_draw(t_data *data, t_player *player, t_ray *ray, t_img *img)
{
	//mlx_clear_window(data->mlx, data->win);
	render_background3d(img, data);
	draw_rays(data, ray, player);
	mlx_put_image_to_window(data->mlx, data->win, img->ref, 0, 0);
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	if (data->win == NULL)
		return ;
	data->stock = init_stock();
	data->img.ref = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ref, &data->img.bpp,
		&data->img.lenght, &data->img.endian);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E' ||
				data->map[y][x] == 'W' || data->map[y][x] == 'S')
				init_player(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

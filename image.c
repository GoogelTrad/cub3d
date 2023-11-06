/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:19:23 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/25 20:19:23 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img init_img(int size_x, int size_y, int size_z, int color)
{
	t_img img;

	img.size.x = size_x;
	img.size.y = size_y;
	img.size.z = size_z;
	img.color = color;
	return (img);
}

t_stock init_stock(void)
{
	t_stock stock;

	stock.floor = init_img(GRID, GRID, 0, 0xFFFF00);
	stock.wall = init_img(GRID, GRID, 0, 0x00FF0000);
	stock.player = init_img(10, 10, 10, 0xFF000000);
	return (stock);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->lenght + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}


void render_player(t_img *img, t_data *data, int pos_x, int pos_y)
{
	int xf;
	float t;
	int yf;
	int x;
	int y;

	xf = (pos_x + data->stock.player.size.x / 2) - (data->stock.player.size.x * 2) * cos(data->player.angle);
	yf = (pos_y + data->stock.player.size.y / 2) - (data->stock.player.size.y * 2) * sin(data->player.angle);
	t = 0;
	render_rect(img, &data->stock.player, pos_x, pos_y);
	while (t <= 1)
	{
		y = t*(yf - (pos_y + data->stock.player.size.y / 2)) + (pos_y + data->stock.player.size.y / 2);
		x = t*(xf - (pos_x + data->stock.player.size.x / 2)) + (pos_x + data->stock.player.size.x / 2);
		my_mlx_pixel_put(img, x, y, data->stock.player.color);
		t += 0.005;
	}	
}

void render_rect(t_img *img, t_img *rect, int pos_x, int pos_y)
{
	int y;
	int x;

	y = pos_y;
	while (y < pos_y + rect->size.y)
	{
		x = pos_x;
		while (x < pos_x + rect->size.x)
			my_mlx_pixel_put(img, x++, y, rect->color);
		++y;
	}
}

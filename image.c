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

void	draw_square(t_img img, t_data *data, int pos_x, int pos_y)
{
	int x;
	int y;

	y = 0;
	while (y < img.size.y)
	{
		x = 0;
		while (x < img.size.x)
		{
			mlx_pixel_put(data->mlx, data->win, pos_x + x, pos_y + y, img.color);
			x++;
		}
		y++;
	}
}

t_stock init_img()
{
	t_stock stock;

	stock.floor.color = 0xFFFFFF00;
	stock.floor.size.x = 50;
	stock.floor.size.y = 50;
	stock.wall.color = 0x00FF0000;
	stock.wall.size.x = 50;
	stock.wall.size.y = 50;
	stock.player.color = 0xFF000000;
	stock.player.size.x = 25;
	stock.player.size.y = 25;
	return (stock);
}

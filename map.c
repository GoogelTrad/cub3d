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

void draw_map(t_data *data)
{
	int x;
	int color;
	int y;
	int i;
	int j;

	y = 0;
	j = 0;
	data->stock = init_img();
	while (y < HEIGHT)
	{
		x = 0;
		i = 0;
		while (x < WIDTH)
		{
			if (data->map[j] == NULL)
				return ;
			if (data->map[j][i] && data->map[j][i] == '1')
				draw_square(data->stock.wall, data, x, y);
			else if (data->map[j][i] && data->map[j][i] == '0')
				draw_square(data->stock.floor, data, x, y);
			else if (data->map[j][i] && data->map[j][i] == 'N')
			{
				draw_square(data->stock.floor, data, x, y);
				draw_square(data->stock.player, data, x, y);
				data->player.pos_x = x;
				data->player.pos_y = y;
			}
			i++;
			x += 50;
		}
		j++;
		y += 50;
	}
}
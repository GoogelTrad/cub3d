/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 01:46:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/26 01:46:11 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_up(t_data *data)
{
	draw_square(data->stock.floor, data, data->player.pos_x, data->player.pos_y);
	data->player.pos_y -= 10;
	draw_square(data->stock.player, data, data->player.pos_x, data->player.pos_y);
}

void move_down(t_data *data)
{
	draw_square(data->stock.floor, data, data->player.pos_x, data->player.pos_y);
	data->player.pos_y += 10;
	draw_square(data->stock.player, data, data->player.pos_x, data->player.pos_y);
}

void move_right(t_data *data)
{
	draw_square(data->stock.floor, data, data->player.pos_x, data->player.pos_y);
	data->player.pos_x += 10;
	draw_square(data->stock.player, data, data->player.pos_x, data->player.pos_y);
}

void move_left(t_data *data)
{
	draw_square(data->stock.floor, data, data->player.pos_x, data->player.pos_y);
	data->player.pos_x -= 10;
	draw_square(data->stock.player, data, data->player.pos_x, data->player.pos_y);
}
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

void	move_up(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x + data->ray.deltax * SPEED;
	tmp_y = data->player.pos.y + data->ray.deltay * SPEED;
	if (data->mapcopy[(int)tmp_y][(int)tmp_x] == 'X')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
		data->minimap.player.x += data->ray.deltax * SPEED;
		data->minimap.player.y += data->ray.deltay * SPEED;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void	move_down(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x - data->ray.deltax * SPEED;
	tmp_y = data->player.pos.y - data->ray.deltay * SPEED;
	if (data->mapcopy[(int)tmp_y][(int)tmp_x] == 'X')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
		data->minimap.player.x -= data->ray.deltax * SPEED;
		data->minimap.player.y -= data->ray.deltay * SPEED;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void	move_left(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x + data->ray.deltay * SPEED;
	tmp_y = data->player.pos.y - data->ray.deltax * SPEED;
	if (data->mapcopy[(int)tmp_y][(int)tmp_x] == 'X')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
		data->minimap.player.x += data->ray.deltay * SPEED;
		data->minimap.player.y -= data->ray.deltax * SPEED;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void	move_right(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x - data->ray.deltay * SPEED;
	tmp_y = data->player.pos.y + data->ray.deltax * SPEED;
	if (data->mapcopy[(int)tmp_y][(int)tmp_x] == 'X')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
		data->minimap.player.x -= data->ray.deltay * SPEED;
		data->minimap.player.y += data->ray.deltax * SPEED;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

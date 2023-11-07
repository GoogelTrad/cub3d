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

void init_player(t_data *data, int x, int y, char angle)
{
	data->player.pos.x = x;
	data->player.pos.y = y;
	if (angle == 'S')
	{
		data->ray.deltaX = 0;
		data->ray.deltaY = 1;
		data->ray.planeX = -0.66;
		data->ray.planeY = 0;
		data->player.angle = 1.5 * PI;
	}
	else if (angle == 'N')
	{
		data->ray.deltaX = 0;
		data->ray.deltaY = -1;
		data->ray.planeX = 0.66;
		data->ray.planeY = 0;
		data->player.angle = 0.5 * PI;
	}
	else if (angle == 'W')
	{
		data->ray.deltaX = -1;
		data->ray.deltaY = 0;
		data->ray.planeX = 0;
		data->ray.planeY = -0.66;
		data->player.angle = PI;
	}
	else if (angle == 'E')
	{
		data->ray.deltaX = 1;
		data->ray.deltaY = 0;
		data->ray.planeX = 0;
		data->ray.planeY = 0.66;
		data->player.angle = 0;
	}
	data->player.delta_x = cos(data->player.angle * 5);
	data->player.delta_y = sin(data->player.angle * 5);
}

void move_up(t_data *data)
{
	data->player.pos.x += data->ray.deltaX * SPEED;
	data->player.pos.y += data->ray.deltaY * SPEED;
	final_draw(data, &data->player, &data->ray, &data->img);
}

void move_down(t_data *data)
{
	data->player.pos.x -= data->ray.deltaX * SPEED;
	data->player.pos.y -= data->ray.deltaY * SPEED;
	final_draw(data, &data->player, &data->ray, &data->img);	
}

void move_right(t_data *data)
{
	float oldDirX;
	float oldPlaneX;

	oldDirX = data->ray.deltaX;
	data->ray.deltaX = data->ray.deltaX * cos(-SPEED) - data->ray.deltaY * sin(-SPEED);
	data->ray.deltaY = oldDirX * sin(-SPEED) + data->ray.deltaY * cos(-SPEED);
	oldPlaneX = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(-SPEED) - data->ray.planeY * sin(-SPEED);
	data->ray.planeY = oldPlaneX * sin(-SPEED) + data->ray.planeY * cos(-SPEED);
	final_draw(data, &data->player, &data->ray, &data->img);	
}

void move_left(t_data *data)
{
	float oldDirX;
	float oldPlaneX;

	oldDirX = data->ray.deltaX;
	data->ray.deltaX = data->ray.deltaX * cos(SPEED) - data->ray.deltaY * sin(SPEED);
	data->ray.deltaY = oldDirX * sin(SPEED) + data->ray.deltaY * cos(SPEED);
	oldPlaneX = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(SPEED) - data->ray.planeY * sin(SPEED);
	data->ray.planeY = oldPlaneX * sin(SPEED) + data->ray.planeY * cos(SPEED);
	final_draw(data, &data->player, &data->ray, &data->img);	
}
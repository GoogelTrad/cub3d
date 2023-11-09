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
	data->player.pos.x = (float)x + 0.25;
	data->player.pos.y = (float)y + 0.25;
	if (angle == 'S')
	{
		data->ray.deltaX = 0.0;
		data->ray.deltaY = 1.0;
		data->ray.planeX = -0.66;
		data->ray.planeY = 0.0;
		data->player.angle = 1.5 * PI;
	}
	else if (angle == 'N')
	{
		data->ray.deltaX = 0.0;
		data->ray.deltaY = -1.0;
		data->ray.planeX = 0.66;
		data->ray.planeY = 0.0;
		data->player.angle = 0.5 * PI;
	}
	else if (angle == 'W')
	{
		data->ray.deltaX = -1.0;
		data->ray.deltaY = 0.0;
		data->ray.planeX = 0.0;
		data->ray.planeY = -0.66;
		data->player.angle = PI;
	}
	else if (angle == 'E')
	{
		data->ray.deltaX = 1.0;
		data->ray.deltaY = 0.0;
		data->ray.planeX = 0.0;
		data->ray.planeY = 0.66;
		data->player.angle = 0;
	}
	data->player.delta_x = cos(data->player.angle * 5);
	data->player.delta_y = sin(data->player.angle * 5);
}

void move_up(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x + data->ray.deltaX * SPEED;
	tmp_y = data->player.pos.y + data->ray.deltaY * SPEED;
	if (data->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void move_down(t_data *data)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = data->player.pos.x - data->ray.deltaX * SPEED;
	tmp_y = data->player.pos.y - data->ray.deltaY * SPEED;
	if (data->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
	}
	final_draw(data, &data->player, &data->ray, &data->img);	
}

void move_left(t_data *data)
{
	float tmp_x;
	float tmp_y;

	tmp_x = data->player.pos.x + data->ray.deltaY * SPEED;
	tmp_y = data->player.pos.y - data->ray.deltaX * SPEED;
	if (data->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void move_right(t_data *data)
{
	float tmp_x;
	float tmp_y;

	tmp_x = data->player.pos.x - data->ray.deltaY * SPEED;
	tmp_y = data->player.pos.y + data->ray.deltaX * SPEED;
	if (data->map[(int)tmp_y][(int)tmp_x] != '1')
	{
		data->player.pos.x = tmp_x;
		data->player.pos.y = tmp_y;
	}
	final_draw(data, &data->player, &data->ray, &data->img);
}

void cam_right(t_data *data)
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

void cam_left(t_data *data)
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
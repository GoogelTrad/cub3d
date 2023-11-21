/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:20:51 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/17 10:20:51 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_delta(t_data *data, float x, float y, float angle)
{
	data->player.angle = angle;
	data->ray.deltax = x;
	data->ray.deltay = y;
}

void	player_plane(t_data *data, float x, float y)
{
	data->ray.planex = x;
	data->ray.planey = y;
}

void	init_player(t_data *data, int x, int y, char angle)
{
	data->player.pos.x = (float)x + 0.25;
	data->player.pos.y = (float)y + 0.25;
	data->mapcopy[y][x] = 'X';
	if (angle == 'S')
	{
		player_delta(data, 0.0, 1.0, 1.5 * PI);
		player_plane(data, -0.66, 0.0);
	}
	else if (angle == 'N')
	{
		player_delta(data, 0.0, -1.0, 0.5 * PI);
		player_plane(data, 0.66, 0.0);
	}
	else if (angle == 'W')
	{
		player_delta(data, -1.0, 0.0, 0);
		player_plane(data, 0.0, -0.66);
	}
	else if (angle == 'E')
	{
		player_delta(data, 1.0, 0.0, PI);
		player_plane(data, 0.0, 0.66);
	}
	data->player.delta_x = cos(data->player.angle * 5);
	data->player.delta_y = sin(data->player.angle * 5);
}

void	cam_right(t_data *data)
{
	float	olddirx;
	float	oldplanex;

	olddirx = data->ray.deltax;
	data->ray.deltax = data->ray.deltax * cos(-CAM_SPEED)
		- data->ray.deltay * sin(-CAM_SPEED);
	data->ray.deltay = olddirx * sin(-CAM_SPEED)
		+ data->ray.deltay * cos(-CAM_SPEED);
	oldplanex = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(-CAM_SPEED)
		- data->ray.planey * sin(-CAM_SPEED);
	data->ray.planey = oldplanex * sin(-CAM_SPEED)
		+ data->ray.planey * cos(-CAM_SPEED);
	final_draw(data, &data->player, &data->ray, &data->img);
}

void	cam_left(t_data *data)
{
	float	olddirx;
	float	oldplanex;

	olddirx = data->ray.deltax;
	data->ray.deltax = data->ray.deltax * cos(CAM_SPEED)
		- data->ray.deltay * sin(CAM_SPEED);
	data->ray.deltay = olddirx * sin(CAM_SPEED)
		+ data->ray.deltay * cos(CAM_SPEED);
	oldplanex = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(CAM_SPEED)
		- data->ray.planey * sin(CAM_SPEED);
	data->ray.planey = oldplanex * sin(CAM_SPEED)
		+ data->ray.planey * cos(CAM_SPEED);
	final_draw(data, &data->player, &data->ray, &data->img);
}

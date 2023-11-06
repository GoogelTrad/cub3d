/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:39:19 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/24 15:39:19 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_wall(t_data *data ,t_ray *ray, int pos_x)
{
	int y;

	y = ray->begin_wall;
	while (y < ray->end_wall)
	{
		my_mlx_pixel_put(&data->img, pos_x, y, data->stock.wall.color);
		y++;
	}
}

void draw_rays(t_data *data, t_ray *ray, t_player *player)
{
	int	x;
	float cameraX;

	x = 0;
	while (x < data->width)
	{
		ray->mapX = (int)player->pos.x;
		ray->mapY = (int)player->pos.y;
		cameraX = 2 * x / (float)data->width - 1;
		ray->ray_dirX = player->delta_x + ray->planeX * cameraX;
		ray->ray_dirY = player->delta_y + ray->planeY * cameraX;
		if (ray->ray_dirX == 0)
			ray->delta_distX = 1e30;
		else
			ray->delta_distX = fabs(1 / ray->ray_dirX);
		if (ray->ray_dirY == 0)
			ray->delta_distY = 1e30;
		else
			ray->delta_distY = fabs(1 / ray->ray_dirY);

		//calculate step and initial sideDist
		if (ray->ray_dirX < 0)
		{
			ray->stepX = -1;
			ray->sideDistX = (player->pos.x - ray->mapX) * ray->delta_distX;
		}
		else
		{
			ray->stepX = 1;
			ray->sideDistX = (ray->mapX + 1.0 - player->pos.x) * ray->delta_distX;
		}
		if (ray->ray_dirY < 0)
		{
			ray->stepY = -1;
			ray->sideDistY = (player->pos.y - ray->mapY) * ray->delta_distY;
		}
		else
		{
			ray->stepY = 1;
			ray->sideDistY = (ray->mapY + 1.0 - player->pos.y) * ray->delta_distY;
		}

		//detection d'un mur
		ray->wall = 0;
		while (ray->wall == 0)
		{
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->delta_distX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sideDistY += ray->delta_distY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			if (data->map[ray->mapY][ray->mapX] == '1')
				ray->wall = 1;
		}
		//Calculate distance projected on camera direction
		if (ray->side == 0)
			ray->wall_dist = (ray->sideDistX - ray->delta_distX);
		else
			ray->wall_dist = (ray->sideDistY - ray->delta_distY);

		//Calculate height of line to draw on screen for wall
		ray->hauteur_wall = (int)(data->height / ray->wall_dist);
		ray->begin_wall = -(ray->hauteur_wall) / 2 + data->height / 2;
		if (ray->begin_wall < 0)
			ray->begin_wall = 0;
		ray->end_wall = ray->hauteur_wall / 2 + data->height / 2;
		if (ray->end_wall >= data->height)
			ray->end_wall = data->height - 1;

		draw_wall(data, ray, x);
		x++;
	}
}
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

void	calc_dir(t_ray *ray)
{
	if (ray->ray_dirx == 0)
		ray->delta_distx = 1e30;
	else
		ray->delta_distx = fabs(1 / ray->ray_dirx);
	if (ray->ray_diry == 0)
		ray->delta_disty = 1e30;
	else
		ray->delta_disty = fabs(1 / ray->ray_diry);
}

void	calc_stepx(t_ray *ray, t_player *player)
{
	if (ray->ray_dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->pos.x - ray->mapx) * ray->delta_distx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->pos.x) * ray->delta_distx;
	}
	if (ray->ray_diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->pos.y - ray->mapy) * ray->delta_disty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->pos.y) * ray->delta_disty;
	}
}

void	wall_hit(t_ray *ray, t_data *data)
{
	int	wall;

	wall = 0;
	while (wall == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->delta_distx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->delta_disty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (data->mapcopy[ray->mapy][ray->mapx] == '1')
			wall = 1;
	}
}

void	calc_direction(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
	{
		if (ray->ray_dirx > 0)
			ray->direction = 3;
		else
			ray->direction = 2;
		ray->wall_dist = (ray->sidedistx - ray->delta_distx);
		ray->wallx = player->pos.y + ray->wall_dist * ray->ray_diry;
	}
	else
	{
		if (ray->ray_diry > 0)
			ray->direction = 0;
		else
			ray->direction = 1;
		ray->wall_dist = (ray->sidedisty - ray->delta_disty);
		ray->wallx = player->pos.x + ray->wall_dist * ray->ray_dirx;
	}
}

void	draw_rays(t_data *data, t_ray *ray, t_player *player, t_stock *stock)
{
	int		x;
	float	camerax;

	x = 0;
	while (x < data->width)
	{
		ray->mapx = (int)player->pos.x;
		ray->mapy = (int)player->pos.y;
		camerax = 2 * x / (float)data->width - 1;
		ray->ray_dirx = ray->deltax + ray->planex * camerax;
		ray->ray_diry = ray->deltay + ray->planey * camerax;
		calc_dir(ray);
		calc_stepx(ray, player);
		wall_hit(ray, data);
		calc_direction(ray, player);
		calc_wall(ray, data);
		texturing_ray(ray, data, stock, x);
		x++;
	}
}

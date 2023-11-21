/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:09:13 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/17 10:09:13 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	**init_wall(t_data *data)
{
	int		i;
	t_img	**wall;

	i = 0;
	wall = malloc(sizeof(t_img *) * 4);
	while (i < 4)
	{
		wall[i] = malloc(sizeof(t_img));
		wall[i]->ref = mlx_xpm_file_to_image(data->mlx, data->cub.txt[i],
				&wall[i]->size.x, &wall[i]->size.y);
		wall[i]->addr = mlx_get_data_addr(wall[i]->ref, &wall[i]->bpp,
				&wall[i]->lenght, &wall[i]->endian);
		i++;
	}
	return (wall);
}

void	texturing_ray(t_ray *ray, t_data *data, t_stock *stock, int x)
{
	float	step;
	float	texpos;

	step = 1.0 * TEX_WIDTH / ray->hauteur_wall;
	texpos = (ray->begin_wall - data->height / 2 + ray->hauteur_wall / 2)
		* step;
	while (ray->begin_wall < ray->end_wall)
	{
		ray->texy = (int)texpos & (TEX_WIDTH - 1);
		texpos += step;
		stock->wall.color = *(int *)(data->wall[ray->direction]->addr
				+ (ray->texy * data->wall[ray->direction]->lenght)
				+ (ray->texx * data->wall[ray->direction]->bpp / 8));
		if (ray->side == 1)
			stock->wall.color = (stock->wall.color >> 1) & 8355711;
		ray->begin_wall++;
		my_mlx_pixel_put(&data->img, x, ray->begin_wall, stock->wall.color);
	}
}

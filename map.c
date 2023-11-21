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

void	calc_wall(t_ray *ray, t_data *data)
{
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)(TEX_WIDTH));
	if (ray->side == 0 && ray->ray_dirx > 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
	else if (ray->side == 1 && ray->ray_diry < 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
	ray->hauteur_wall = (int)(data->height / ray->wall_dist);
	ray->begin_wall = -(ray->hauteur_wall) / 2 + data->height / 2;
	if (ray->begin_wall < 0)
		ray->begin_wall = 0;
	ray->end_wall = ray->hauteur_wall / 2 + data->height / 2;
	if (ray->end_wall >= data->height)
		ray->end_wall = data->height - 1;
}

void	render_background3d(t_img *img, t_data *data)
{
	int		x;
	int		y;
	int		color;

	y = 0;
	color = data->ceiling;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
		if (y > (HEIGHT / 2))
			color = data->floor;
	}
}

void	final_draw(t_data *data, t_player *player, t_ray *ray, t_img *img)
{
	render_background3d(img, data);
	draw_rays(data, ray, player, &data->stock);
	//minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, img->ref, 0, 0);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (data->win == NULL)
		return ;
	data->img.ref = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ref, &data->img.bpp,
			&data->img.lenght, &data->img.endian);
	data->stock = init_stock();
	data->wall = init_wall(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E' ||
				data->map[y][x] == 'W' || data->map[y][x] == 'S')
				init_player(data, x, y, data->map[y][x]);
			x++;
		}
		y++;
	}
	//data->minimap = init_minimap(data, 1);
	final_draw(data, &data->player, &data->ray, &data->img);
}

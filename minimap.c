/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:55:41 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/17 11:55:41 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**copymap(t_data *data, t_minimap *minimap)
{
	char	**map;
	int		y;
	int		i;

	y = minimap->min.y;
	i = 0;
	map = malloc(sizeof(char *) * 21);
	while (data->map[y] && y < (int)minimap->max.y)
		map[i++] = ft_strndup(data->map[y++], (int)minimap->max.x);
	map[i] = NULL;
	return (map);
}

t_minimap init_minimap(t_data *data, int verif)
{
	t_minimap minimap;
	int	i;

	i = 0;

	minimap.max.y = data->player.pos.y + 10;
	minimap.max.x = data->player.pos.x + 10;
	if (data->player.pos.x - 10 > 0)
		minimap.min.x = data->player.pos.x - 10;
	else
		minimap.min.x = 0;
	if (data->player.pos.y - 10 > 0)
		minimap.min.y = data->player.pos.y - 10;
	else
		minimap.min.y = 0;
	minimap.map = copymap(data, &minimap);
	while (i < (minimap.max.y - minimap.min.y) / 2)
		i++;
	minimap.player.y = i;
	if (minimap.min.y == 0 && verif == 1)
		minimap.player.y = data->minimap.player.y;
	else if (minimap.min.y == 0 && verif == 0)
		minimap.player.y = data->player.pos.y;
	if (minimap.player.y < 1.3)
		minimap.player.y = 1.3;
	minimap.player.x = ft_strlen(minimap.map[i]) / 2;
	if (minimap.min.x == 0 && verif == 1)
		minimap.player.x = data->minimap.player.x;
	else if (minimap.min.x == 0 && verif == 0)
		minimap.player.x = data->player.pos.x;
	if (minimap.player.x < 1.3)
		minimap.player.x = 1.3;
	return (minimap);
}

void	minimap(t_data *data)
{
	int	x;
	int	y;
	int	limit;

	y = 0;
	//printf("x = %f, y = %f\n", data->minimap.player.x, data->minimap.player.y);
	//printf("coucou\n");
	//printf("min x =  %f, max x = %f\n", data->minimap.min.x, data->minimap.max.x);
	//printf("min y =  %f, max y = %f\n", data->minimap.min.y, data->minimap.max.y);	
	data->minimap = init_minimap(data, 0);
	//printf("min x2 =  %f, max x = %f\n", data->minimap.min.x, data->minimap.max.x);
	//printf("min y2 =  %f, max y = %f\n", data->minimap.min.y, data->minimap.max.y);
	//printf("x2 = %f, y2 = %f\n", data->minimap.player.x, data->minimap.player.y);
	while (data->minimap.map[y])
	{
		x = 0;
		while (data->minimap.map[y][x])
		{
			if (data->minimap.map[y][x] == '1')
				render_rect(&data->img, &data->stock.wall, x * GRID, y * GRID);
			else if (data->minimap.map[y][x] == 'X' || data->minimap.map[y][x] == 'X'
				|| data->minimap.map[y][x] == 'N' || data->minimap.map[y][x] == 'E'
				|| data->minimap.map[y][x] == 'W' || data->minimap.map[y][x] == 'S'
				|| data->minimap.map[y][x] == '0')
				render_rect(&data->img, &data->stock.floor, x * GRID, y * GRID);
			x++;
		}
		y++;
	}
	//printf("coucou\n");
	//printf("x = %f, y = %f\n", data->minimap.player.x * GRID, data->minimap.player.y * GRID);
	render_player(&data->img, data, data->minimap.player.x * GRID,
		data->minimap.player.y * GRID);
	//printf("coucou2\n");
	free_map(data->minimap.map);
}

void	rotate_minimap(t_data *data, int sens)
{
	if (sens == 1)
	{
		data->player.angle += CAM_SPEED;
		if (data->player.angle > 2 * PI)
			data->player.angle -= 2 * PI;
		data->player.delta_x = cos(data->player.angle) * 5;
		data->player.delta_y = sin(data->player.angle) * 5;
	}
	else if (sens == 0)
	{
		data->player.angle -= CAM_SPEED;
		if (data->player.angle < 0)
			data->player.angle += 2 * PI;
		data->player.delta_x = cos(data->player.angle) * 5;
		data->player.delta_y = sin(data->player.angle) * 5;
	}
}

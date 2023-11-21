/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:05 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:05 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pos_player(t_p *begin, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'N' || data->mapcopy[i][j] == 'S'
				|| data->mapcopy[i][j] == 'W' || data->mapcopy[i][j] == 'E')
			{
				begin->pos_x = j;
				begin->pos_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_fill(t_p *begin, t_data *data)
{
	data->mapcopy[begin->pos_y][begin->pos_x] = 'X';
	if (data->mapcopy[begin->pos_y][begin->pos_x - 1] == '0')
		data->mapcopy[begin->pos_y][begin->pos_x - 1] = 'X';
	if (data->mapcopy[begin->pos_y][begin->pos_x + 1] == '0')
		data->mapcopy[begin->pos_y][begin->pos_x + 1] = 'X';
	if (data->mapcopy[begin->pos_y - 1][begin->pos_x] == '0')
		data->mapcopy[begin->pos_y - 1][begin->pos_x] = 'X';
	if (data->mapcopy[begin->pos_y + 1][begin->pos_x] == '0')
		data->mapcopy[begin->pos_y + 1][begin->pos_x] = 'X';
}

void	ft_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'X')
			{
				if (data->mapcopy[i][j - 1] == '0')
					data->mapcopy[i][j - 1] = 'X';
				if (data->mapcopy[i][j + 1] == '0')
					data->mapcopy[i][j + 1] = 'X';
				if (data->mapcopy[i - 1][j] == '0')
					data->mapcopy[i - 1][j] = 'X';
				if (data->mapcopy[i + 1][j] == '0')
					data->mapcopy[i + 1][j] = 'X';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:50:58 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:50:58 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_top_and_bot(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] == ' ' || map[i][j] == '\t'
		|| map[i][j] == '\v')
		j++;
	while (map[i][j] != 13 && map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t' && map[i][j] != '\v')
		{
			printf("Error\n Map not closed\n");
			exit(1);
		}
		j++;
	}
	return (0);
}

void	ft_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != 13 && map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'E'
			&& map[i][j] != 'S' && map[i][j] != 'W'
			&& map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != ' ' && map[i][j] != '\t')
			{
				printf("%s", "Error \nA Not recognized char in the map \n");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_leftside(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t' && map[i][j] != 13)
		{
			printf("Error \n map not closed \n");
			exit(1);
		}
		i++;
	}
}

void	ft_rightside(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 2;
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t')
		{
			printf("Error \n map not closed \n");
			exit(1);
		}
		i++;
	}
}

void	ft_parsing(int ac, char **av, t_data *data)
{
	ft_cub(ac, av);
	ft_args(av);
	ft_mapsave(av, data);
	data->map = initmap2(data->cubs);
	data->cub = ft_textures(data);
	ft_top_and_bot(data->map, 0);
	ft_leftside(data->map);
	ft_rightside(data->map);
	ft_top_and_bot(data->map, countmapline(data->cubs) - 1);
	ft_char(data->map);
	ft_map_parsing(data);
}

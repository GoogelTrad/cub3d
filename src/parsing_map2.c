/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:02 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:02 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_maperror(t_data *data, int i, int j)
{
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'X')
			{
				if (data->mapcopy[i][j - 1] != 'X'
					&& data->mapcopy[i][j - 1] != '1')
					return (1);
				if (data->mapcopy[i][j + 1] != 'X'
					&& data->mapcopy[i][j + 1] != '1')
					return (1);
				if (data->mapcopy[i - 1][j] != 'X'
					&& data->mapcopy[i - 1][j] != '1')
					return (1);
				if (data->mapcopy[i + 1][j] != 'X'
					&& data->mapcopy[i + 1][j] != '1')
					return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_conditions(t_data *data)
{
	int	imax;

	imax = 5000;
	while (imax > 0)
	{
		imax--;
		ft_path(data);
	}
	if (ft_maperror(data, 0, 0) == 1)
	{
		printf("%s \n", "Error\n Map error");
		exit(1);
	}
}

void	ft_p(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'N' || data->mapcopy[i][j] == 'S'
				|| data->mapcopy[i][j] == 'W' || data->mapcopy[i][j] == 'E')
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	if (k != 1)
	{
		printf("%s", "Error \nNo starting point or Too many starting point\n");
		exit(1);
	}
}

char	**ft_cpytab(char **tab)
{
	int		i;
	char	**ret;

	i = 0;
	ret = malloc(sizeof(char *) * (tabsize(tab) + 1));
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	ft_map_parsing(t_data *data)
{
	t_p	begin;

	data->mapcopy = ft_cpytab(data->map);
	ft_p(data);
	ft_pos_player(&begin, data);
	ft_fill(&begin, data);
	ft_conditions(data);
}

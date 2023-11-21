/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:50:28 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:50:28 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_args(char **av)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], '.');
	while (split[i] != NULL)
		i++;
	if (ft_strncmp(split[i - 1], "cub", 3) != 0)
	{
		printf("%s", "Error \nonly put a .cub argument \n");
		exit(1);
	}
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_cub(int ac, char **av)
{
	if (open(av[1], O_RDONLY) < 0)
	{
		printf("%s", "ERROR \nMap .cub file doesnt exist \n");
		exit(1);
	}
	if (ac > 2)
	{
		printf("%s", "Error \ntoo many args \n");
		exit(1);
	}
	else if (ac < 2)
	{
		printf("%s", "Error \nadd a .cub file as arg \n");
		exit(1);
	}
}

int	countmapline(char **cubs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (cubs[i])
	{
		while (cubs[i][j] == ' ')
			j++;
		if (ft_isdigit(cubs[i][j]) == 0)
			i++;
		else
		{
			k = i;
			while (cubs[i])
				i++;
			return (i - k);
		}
		j = 0;
	}
	return (i - k);
}

char	**initmap2(char **cubs)
{
	int		i;
	char	**map;
	int		sizemap;
	int		j;

	i = 0;
	j = 0;
	sizemap = countmapline(cubs);
	while (cubs[i])
		i++;
	map = malloc(sizeof(char *) * (sizemap + 1));
	i -= (sizemap);
	while (cubs[i])
	{
		if (cubs[i] == NULL)
			i++;
		else
			map[j] = ft_strdup(cubs[i]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

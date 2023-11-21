/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:16 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:16 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tabsize(char **cubs)
{
	int	i;

	i = 0;
	while (cubs[i])
		i++;
	return (i);
}

void	ft_cleartab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_missing_info_cub(void)
{
	printf("Error\n An info is missing in .cub");
	exit(1);
}

void	ft_error_rgb(void)
{
	printf("%s \n", "Error\n RGB Problem");
	exit(1);
}

int	longestlen(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

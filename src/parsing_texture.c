/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:08 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:08 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_all_texture(char **noemptyline, char c, char d)
{
	int	i;

	i = 0;
	if (d != 'X')
	{
		while (noemptyline[i])
		{
			if (noemptyline[i][0] == c && noemptyline[i][1] == d)
				return (0);
			i++;
		}
	}
	else
	{
		while (noemptyline[i])
		{
			if (noemptyline[i][0] == c)
				return (0);
			i++;
		}
	}
	return (1);
}

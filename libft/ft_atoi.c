/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 03:12:15 by haouni            #+#    #+#             */
/*   Updated: 2022/11/15 03:25:36 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == 45 || str[i] == 43)
		{
			if (str[i] == 45)
				j = -j;
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			k = k * 10 + str[i] - 48;
			i++;
		}
		return (k * j);
	}
	return (0);
}

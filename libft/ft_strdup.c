/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:50:19 by haouni            #+#    #+#             */
/*   Updated: 2023/11/04 03:17:34 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*y;
	int		i;

	i = 0;
	y = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!y)
		return (NULL);
	while (s1[i] != '\0')
	{
		y[i] = s1[i];
		i++;
	}
	y[i] = '\0';
	return (y);
}

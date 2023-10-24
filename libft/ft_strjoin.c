/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:42:52 by haouni            #+#    #+#             */
/*   Updated: 2022/11/26 05:45:53 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*y;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	y = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!y)
		return (NULL);
	while (s1[i])
	{
		y[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		y[j++] = s2[i++];
	}
	y[j] = '\0';
	return (y);
}

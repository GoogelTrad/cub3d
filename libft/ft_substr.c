/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:24:36 by haouni            #+#    #+#             */
/*   Updated: 2022/11/26 07:03:58 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpy(size_t len, unsigned int start, char *y, const char *s)
{
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(s);
	i = 0;
	while (i < len && j >= start + i)
	{
		y[i] = s[start + i];
		i++;
	}
	y[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*y;
	unsigned int	j;

	if (s == 0)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_strdup(""));
	if (len <= j)
		y = malloc(sizeof(*y) * (len + 1));
	else
	{
		y = malloc(sizeof(*y) * (j + 1));
		len = j;
	}
	if (!y)
		return (NULL);
	ft_cpy(len, start, y, s);
	return (y);
}

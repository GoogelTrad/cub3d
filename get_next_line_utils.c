/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:30:19 by haouni            #+#    #+#             */
/*   Updated: 2023/11/03 13:05:20 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*y;
	size_t	i;

	i = -1;
	if (!s[0])
	{
		free(s);
		return (0);
	}
	if (len > ft_strlen2(s))
		len = (ft_strlen2(s) - start);
	if (start > ft_strlen2(s))
		len = 0;
	y = malloc(sizeof(y) * (len + 1));
	if (!y)
	{
		free(s);
		return (NULL);
	}
	while (++i < len)
		y[i] = s[start + i];
	y[i] = '\0';
	free (s);
	return (y);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*y;
	int		i;
	int		j;

	i = 0;
	j = 0;
	y = malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!s1 || !s2)
		return (NULL);
	if (!y)
		return (NULL);
	while (s1[i])
		y[j++] = s1[i++];
	i = 0;
	while (s2[i])
		y[j++] = s2[i++];
	y[j] = '\0';
	free(s1);
	return (y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:07:25 by haouni            #+#    #+#             */
/*   Updated: 2023/11/04 02:05:00 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
			count ++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**g(char **ret, char const *s, char c)
{
	int	i;
	int	j;
	int	idx;

	idx = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		ret[idx] = ft_substr(s, j, i - j);
		idx++;
	}
	ret[idx] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**ret;

	if (!s)
		return (NULL);
	word = ft_count(s, c);
	ret = malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (NULL);
	return (g(ret, s, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:18:37 by haouni            #+#    #+#             */
/*   Updated: 2022/11/26 02:39:37 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*y;
	unsigned int	i;

	if (s == 0)
		return (NULL);
	i = 0;
	y = malloc(sizeof(*y) * ft_strlen(s) + 1);
	if (!y)
		return (NULL);
	while (s[i] != '\0')
	{
		y[i] = f(i, s[i]);
		i++;
	}
	y[i] = '\0';
	return (y);
}

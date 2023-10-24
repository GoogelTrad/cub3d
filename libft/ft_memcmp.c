/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:29:37 by haouni            #+#    #+#             */
/*   Updated: 2022/11/14 03:06:33 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*y;
	unsigned char	*z;
	size_t			i;

	i = 0;
	y = (unsigned char *)s1;
	z = (unsigned char *)s2;
	while (i < n)
	{
		if (y[i] != z[i])
			return (y[i] - z[i]);
		i++;
	}
	return (0);
}

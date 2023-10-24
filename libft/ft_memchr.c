/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:33:25 by haouni            #+#    #+#             */
/*   Updated: 2022/11/13 23:26:09 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*y;
	unsigned char	*z;

	z = NULL;
	y = (unsigned char *)s;
	while (n --)
	{
		if (*y != (unsigned char)c)
			y++;
		else
			z = y;
	}
	return (z);
}

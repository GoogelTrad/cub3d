/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:48:14 by haouni            #+#    #+#             */
/*   Updated: 2022/11/13 20:45:15 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*y;

	y = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n)
	{
		*(unsigned char *)y = *(unsigned char *)src;
		y++;
		src++;
		n--;
	}
	return (dst);
}

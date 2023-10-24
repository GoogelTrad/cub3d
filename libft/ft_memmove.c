/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:17:05 by haouni            #+#    #+#             */
/*   Updated: 2023/09/26 02:50:28 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*y;

	y = (unsigned char *)dst;
	i = 0;
	if ((dst == NULL && src == NULL) || len == 0)
		return (dst);
	if (src < dst)
	{
		i = len - 1;
		while (i > 0)
		{
			((unsigned char *)y)[i] = ((unsigned char *)src)[i];
			i--;
		}
		((unsigned char *)y)[0] = ((unsigned char *)src)[0];
		return (dst);
	}
	while (i < len)
	{
		((unsigned char *)y)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:48:42 by haouni            #+#    #+#             */
/*   Updated: 2022/11/26 04:34:22 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ss;
	size_t	sd;

	if (dst == 0 && dstsize == 0)
		return (0);
	i = 0;
	sd = ft_strlen(dst);
	ss = ft_strlen(src);
	j = ft_strlen(dst);
	if (dstsize <= sd)
		return (dstsize + ss);
	while (src[i] != '\0' && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (ss + sd);
}

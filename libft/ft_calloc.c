/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:38:27 by haouni            #+#    #+#             */
/*   Updated: 2022/11/19 04:26:20 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*y;
	size_t	z;
	size_t	i;

	i = 0;
	if (count != 0 && SIZE_MAX / count < size)
		return (NULL);
	z = (size * count);
	y = malloc(count * size);
	if (!y)
		return (NULL);
	while (i < z)
	{
		((unsigned char *)y)[i] = 0;
		i++;
	}
	return (y);
}

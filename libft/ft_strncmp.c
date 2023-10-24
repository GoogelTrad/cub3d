/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:56:38 by haouni            #+#    #+#             */
/*   Updated: 2022/11/12 03:38:56 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (((unsigned char *)s1)[i] > (((unsigned char *)s2)[i]))
			return (1);
		if (((unsigned char *)s1)[i] < (((unsigned char *)s2)[i]))
			return (-1);
		i++;
	}
	return (0);
}

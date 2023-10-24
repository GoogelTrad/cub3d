/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:31:41 by haouni            #+#    #+#             */
/*   Updated: 2022/11/18 23:28:12 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static char	*ft_nn(long int n, char *y, int digit)
{
	int	i;

	i = digit + 1;
	y[0] = 45;
	while (n != 0)
	{
		y[digit] = n % 10 + 48;
		n = n / 10;
		digit--;
	}
	y[i] = '\0';
	return (y);
}

static char	*ft_np(int n, char *y, int digit)
{
	int	i;

	i = digit;
	while (n != 0)
	{
		y[digit - 1] = n % 10 + 48;
		n = n / 10;
		digit--;
	}
	y[i] = '\0';
	return (y);
}

static char	*ft_ne(int n, char *y)
{
	y[0] = n + 48;
	y[1] = '\0';
	return (y);
}

char	*ft_itoa(int n)
{
	char			*y;
	int				digit;
	long int		i;

	digit = ft_digit(n);
	i = n;
	if (i < 0)
	{
		y = malloc(sizeof(*y) * (digit) + 2);
		if (!y)
			return (NULL);
		i = i * -1;
		ft_nn(i, y, digit);
	}
	else
	{
		y = malloc(sizeof(*y) * (digit) + 1);
		if (!y)
			return (NULL);
		if (i == 0)
			ft_ne(n, y);
		else
			ft_np(n, y, digit);
	}
	return (y);
}

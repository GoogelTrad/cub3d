/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:55 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:55 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_range_rgb(char **rgb)
	{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			ft_error_rgb();
		i++;
	}
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_couleur(t_data *data, char **rgb, int f_c)
{
	int		r;
	int		g;
	int		b;

	ft_check_range_rgb(rgb);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (f_c == 1)
		data->floor = encode_rgb(r, g, b);
	else
		data->ceiling = encode_rgb(r, g, b);
}

void	ft_format_color2(t_data *data, char *rgb, int f_c)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_split(rgb, ',');
	if (tabsize(tmp) != 3)
		ft_error_rgb();
	while (tmp[i])
	{
		while (tmp[i][j] && tmp[i][j] != 13)
		{
			if (ft_isdigit(tmp[i][j]) == 0)
				ft_error_rgb();
			j++;
		}
		j = 0;
		i++;
	}
	ft_couleur(data, tmp, f_c);
	ft_cleartab(tmp);
}

void	ft_format_color(t_data *data, char *lignecouleur, int f_c)
{
	char	**tmp;

	tmp = ft_split(lignecouleur, ' ');
	if (tabsize(tmp) != 2)
	{
		ft_cleartab(tmp);
		tmp = ft_split(lignecouleur, '\t');
		if (tabsize(tmp) != 2)
		{
			printf("%s \n", "Error\n problem in the .cub");
			free(tmp);
			exit(1);
		}
	}
	ft_format_color2(data, tmp[1], f_c);
	ft_cleartab(tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:50:41 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:50:41 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_c(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->noemptyline[i])
	{
		if (cub->noemptyline[i][0] == 'C')
			cub->c = ft_strdup(cub->noemptyline[i]);
		i++;
	}
}

void	ft_all_infos_cub(t_cub *cub, char **noemptyline)
{
	if (ft_check_all_texture(noemptyline, 'N', 'O') == 1)
		ft_missing_info_cub();
	if (ft_check_all_texture(noemptyline, 'S', 'O') == 1)
		ft_missing_info_cub();
	if (ft_check_all_texture(noemptyline, 'W', 'E') == 1)
		ft_missing_info_cub();
	if (ft_check_all_texture(noemptyline, 'E', 'A') == 1)
		ft_missing_info_cub();
	if (ft_check_all_texture(noemptyline, 'F', 'X') == 1)
		ft_missing_info_cub();
	if (ft_check_all_texture(noemptyline, 'C', 'X') == 1)
		ft_missing_info_cub();
	ft_fill_n(cub);
	ft_fill_s(cub);
	ft_fill_w(cub);
	ft_fill_e(cub);
	ft_fill_f(cub);
	ft_fill_c(cub);
}

int	noemptyline(char **cubs, t_cub *cub, int sizecub, int mapsize)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	while (i < sizecub - mapsize)
	{
		tmp = ft_strtrim(cubs[i], "\t ");
		if (ft_isalnum(tmp[0]) == 1)
			j++;
		i++;
		free(tmp);
	}
	if (j != 6)
	{
		printf("%s \n", "Error\n, problem in the .cub file");
		exit(1);
	}
	return (j);
}

void	noemptyline2(char **cubs, t_cub *cub, int sizecub, int mapsize)
{
	int		j;
	int		i;
	int		lines;
	char	*tmp;
	char	*tmp2;

	j = 0;
	i = 0;
	lines = noemptyline(cubs, cub, sizecub, mapsize);
	cub->noemptyline = malloc(sizeof(char *) * (lines + 1));
	while (i <= sizecub - mapsize)
	{
		tmp = ft_strtrim(cubs[i], " \t");
		if (ft_isalpha(tmp[0]) == 1)
		{
			cub->noemptyline[j] = ft_strdup(tmp);
			j++;
		}
		free(tmp);
		i++;
	}
	cub->noemptyline[j] = NULL;
}

t_cub	ft_textures(char **cubs, t_data *data)
{
	t_cub	cub;

	noemptyline2(data->cubs, &cub, tabsize(data->cubs), tabsize(data->map));
	ft_all_infos_cub(&cub, cub.noemptyline);
	ft_format_color(data, cub.f, 1);
	ft_format_color(data, cub.c, 2);
	ft_check_wall_dif(&cub);
	ft_check_dif_txt(cub.txt);
	ft_check_open_txt(cub.txt);
	return (cub);
}

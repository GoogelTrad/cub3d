/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cub3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:50:49 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:50:49 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_trim_to_txt(t_cub *cub, char **tmp)
{
	int	i;

	i = 0;
	cub->txt = malloc(sizeof(char *) * 5);
	while (tmp[i])
	{
		cub->txt[i] = ft_strtrim(tmp[i], "\n");
		i++;
	}
	cub->txt[i] = NULL;
}

void	ft_check_wall_dif(t_cub *cub)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = malloc(sizeof(char *) * 5);
	i = 2;
	while (cub->no[i] == ' ' || cub->no[i] == '\t')
		i++;
	tmp[0] = ft_substr(cub->no, i, ft_strlen(cub->no) - (i + 1));
	i = 2;
	while (cub->so[i] == ' ' || cub->so[i] == '\t')
		i++;
	tmp[1] = ft_substr(cub->so, i, ft_strlen(cub->so) - (i + 1));
	i = 2;
	while (cub->we[i] == ' ' || cub->we[i] == '\t')
		i++;
	tmp[2] = ft_substr(cub->we, i, ft_strlen(cub->we) - (i + 1));
	i = 2;
	while (cub->ea[i] == ' ' || cub->ea[i] == '\t')
		i++;
	tmp[3] = ft_substr(cub->ea, i, ft_strlen(cub->ea) - (i + 1));
	tmp[4] = NULL;
	ft_trim_to_txt(cub, tmp);
	ft_cleartab(tmp);
}

void	ft_check_dif_txt(char **txt)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (txt[i])
	{
		while (txt[j])
		{
			if (ft_strncmp(txt[i], txt[j], ft_strlen(txt[j])) == 0)
			{
				printf("%s\n", "Error\n, two texture are the same");
				exit(1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_check_open_txt(char **txt)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (access(txt[i], F_OK) == -1)
		{
			printf("%s\n", "Error\n File does not exist");
			exit(1);
		}
		if (access(txt[i], R_OK) == -1)
		{
			printf("%s\n", "Error\n File cannot be read");
			exit(1);
		}
		if (open(txt[i], O_RDONLY) < 0)
		{
			printf("%s\n", "Error\n Texture path wrong or missing");
			exit(1);
		}
		i++;
	}
}

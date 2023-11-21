/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:51:23 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:51:23 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_format_texture(char **noemptyline, int i, char c, char d)
{
	char	**tmp;

	tmp = ft_split(noemptyline[i], ' ');
	if (tabsize(tmp) != 2)
	{
		ft_cleartab(tmp);
		tmp = ft_split(noemptyline[i], '\t');
		if (tabsize(tmp) != 2)
		{
			printf("%s \n", "Error\n problem in the .cub");
			free(tmp);
			exit(1);
		}
	}
	if (tmp[0][0] != c || tmp[0][1] != d)
	{
		printf("%s \n", "Error\n problem in the .cub");
		free(tmp);
		exit(1);
	}
	ft_cleartab(tmp);
}

int	ft_beforemap(char **cubs, int sizecub, int mapsize)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < sizecub - mapsize)
	{
		if (cubs[i] == NULL || cubs[i][0] == '\0')
			i++;
		else
		{
			j++;
			i++;
		}
	}
	return (j);
}

void	ft_mapsave(char **av, t_data *data)
{
	int		fd;
	char	*str;
	char	*x;
	char	*temp;

	fd = open(av[1], O_RDONLY);
	str = ft_strdup("");
	while (1)
	{
		x = get_next_line(fd);
		if (x == NULL)
			break ;
		else
		{
			temp = str;
			str = ft_strjoin2(temp, x);
		}
        free(x);
	}
	data->cubs = ft_split(str, '\n');
	free(str);
}

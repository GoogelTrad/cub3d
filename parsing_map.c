/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouni <haouni@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:50:58 by haouni            #+#    #+#             */
/*   Updated: 2023/11/16 02:50:58 by haouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_top_and_bot(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] == ' ' || map[i][j] == '\t'
		|| map[i][j] == '\v')
		j++;
	while (map[i][j] != 13 && map[i][j] != '\0')
	{
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t' && map[i][j] != '\v')
		{
			printf("Error\n Map not closed\n");
			exit(1);
		}
		j++;
	}
	return (0);
}

/*
void    ft_closed_map(char **map)
{
    int i = 0;
    int j = 0;
    while (map[i])
    {
        while (map[i][j] == ' ')
            j++;
        if (ft_isdigit(map[i][j]) == 1)
        {
            printf("AAAAA \n \n");
            //exit(2);
        }
        else
        {
            printf("%s \n", "Error \n MAP PROBLEMS");
            exit(1);
        }
    }
    j = 0;
}
*/

void	ft_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != 13 && map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'E'
			&& map[i][j] != 'S' && map[i][j] != 'W'
			&& map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != ' ' && map[i][j] != '\t')
			{
				printf("%s", "Error \nA Not recognized char in the map \n");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
char    *ft_texture_no(char **cubs)
{
    int i;
    char *texture_no;
    char *tmp;

    i = 0;
    texture_no = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'N' && cubs[i][1] != 'O')
            i++;
        if (cubs[i][0] == 'N' && cubs[i][1] == 'O')
            texture_no = ft_strdup(cubs[i]);
        else
        {
            printf("%s \n", "Error\n missing North texture");
            exit(1);
        }
    }
    return(texture_no);
}

char    *ft_texture_so(char **cubs)
{
    int i;
    char *texture_so;
    char *tmp;

    i = 0;
    texture_so = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'S' && cubs[i][1] != 'O')
            i++;
        if (cubs[i][0] == 'S' && cubs[i][1] == 'O')
        {
            texture_so = ft_strdup(cubs[i]);
            return(texture_so);
        }
        else
        {
            printf("%s \n", "Error\n missing South texture");
            exit(1);
        }
    }
    return(texture_so);
}

char    *ft_texture_we(char **cubs)
{
    int i;
    char *texture_we;
    char *tmp;

    i = 0;
    texture_we = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'W' && cubs[i][1] != 'E')
            i++;
        if (cubs[i][0] == 'W' && cubs[i][1] == 'E')
        {
            texture_we = ft_strdup(cubs[i]);
            return(texture_we);
        }
        else
        {
            printf("%s \n", "Error\n missing West texture");
            exit(1);
        }
    }
    return(texture_we);
}

char    *ft_texture_ea(char **cubs)
{
    int i;
    char *texture_ea;
    char *tmp;

    i = 0;
    texture_ea = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'E' && cubs[i][1] != 'A')
            i++;
        if (cubs[i][0] == 'E' && cubs[i][1] == 'A')
        {
            texture_ea = ft_strdup(cubs[i]);
            return(texture_ea);
        }
        else
        {
            printf("%s \n", "Error\n missing East texture");
            exit(1);
        }
    }
    return(texture_ea);
}

char    *ft_floor_colors(char **cubs)
{
    int i;
    char *floor_co;
    char *tmp;

    i = 0;
    floor_co = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'F')
            i++;
        if (cubs[i][0] == 'F')
        {
            floor_co = ft_strdup(cubs[i]);
            return(floor_co);
        }
        else
        {
            printf("%s \n", "Error\n missing Floor color");
            exit(1);
        }
    }
    return(floor_co);
}

char    *ft_roof_colors(char **cubs)
{
    int i;
    char *roof_co;
    char *tmp;

    i = 0;
    roof_co = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'F')
            i++;
        if (cubs[i][0] == 'F')
        {
            roof_co = ft_strdup(cubs[i]);
            return(roof_co);
        }
        else
        {
            printf("%s \n", "Error\n missing roof color");
            exit(1);
        }
    }
    return(roof_co);
}
*/

void	ft_leftside(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t' && map[i][j] != 13)
		{
			printf("Error \n map not closed \n");
			exit(1);
		}
		i++;
	}
}

void	ft_rightside(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 2;
		if (map[i][j] != '1' && map[i][j] != ' '
			&& map[i][j] != '\t')
		{
			printf("Error \n map not closed \n");
			exit(1);
		}
		i++;
	}
}

void	ft_parsing(int ac, char **av, t_data *data)
{
	ft_cub(ac, av);
	ft_args(ac, av);
	ft_mapsave(ac, av, data);
	data->map = initmap2(data->cubs);
	data->cub = ft_textures(data->cubs, data);
	ft_top_and_bot(data->map, 0);
	ft_leftside(data->map);
	ft_rightside(data->map);
	ft_top_and_bot(data->map, countmapline(data->cubs) - 1);
	ft_char(data->map);
	ft_map_parsing(data);
}

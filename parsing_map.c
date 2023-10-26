#include "cub3d.h"

void	ft_args(int ac, char **av)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], '.');
	while (split[i] != NULL)
		i++;
	if (ft_strncmp(split[i - 1], "cub", 3) != 0)
	{
		printf("%s", "Error \nonly put a .cub argument \n");
		exit(1);
	}
	free(split[0]);
	free(split[1]);
	free(split[2]);
}

void	ft_cub(int ac, char **av)
{
	if (open(av[1], O_RDONLY) < 0)
	{
		printf("%s", "ERROR \nMap .cub file doesnt exist \n");
		exit(1);
	}
	if (ac > 2)
	{
		printf("%s", "Error \ntoo many args \n");
		exit(1);
	}
	else if (ac < 2)
	{
		printf("%s", "Error \nadd a .cub file as arg \n");
		exit(1);		
	}
}

char **init_map(char *pathname)
{
	char **map;
	int i;
	int fd;
	int count;

	i = 0;
	count = count_line(pathname);
	if (!count)
	{
		printf("%s", "Error \nempty file \n");
		exit(1);			
	}
	fd = open(pathname, O_RDONLY);
	map = malloc(sizeof(char *) * (count + 1));
	while(i < count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	printf("taille de ligne -1 : %d\n", ft_strlen(map[0]));
	map[i] = NULL;
	close(fd);
	return (map);
}

void    ft_parsing(int ac, char **av, t_data *data)
{
	int i;

	i = 0;
	ft_cub(ac, av);
    ft_args(ac, av);
	data->map = init_map(av[1]);
}

/*void	ft_char(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->strf[i])
	{
		while (img->strf[i][j])
		{
			if (img->strf[i][j] != 'N' && img->strf[i][j] != 'E'
			&& img->strf[i][j] != 'S' && img->strf[i][j] != 'W'
			&& img->strf[i][j] != '0' && img->strf[i][j] != '1')
			{
				ft_printf("%s", "Error \nA Not recognized char in the map");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
*/
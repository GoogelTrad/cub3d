#include "cub3d.h"

void    ft_pos_player(t_p *begin, t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->mapcopy[i])
    {
        while(data->mapcopy[i][j])
        {
            if (data->mapcopy[i][j] == 'N' || data->mapcopy[i][j] == 'S'
                || data->mapcopy[i][j] == 'W' || data->mapcopy[i][j] == 'E')
            {
                begin->pos_x = j;
                begin->pos_y = i;
            }
            j++;
        }
        i++;
        j = 0;
    }
}

void	ft_fill(t_p *begin, t_data *data)
{
    data->mapcopy[begin->pos_y][begin->pos_x] = 'X';
	if (data->mapcopy[begin->pos_y][begin->pos_x - 1] == '0')
		data->mapcopy[begin->pos_y][begin->pos_x - 1] = 'X';
	if (data->mapcopy[begin->pos_y][begin->pos_x + 1] == '0')
		data->mapcopy[begin->pos_y][begin->pos_x + 1] = 'X';
	if (data->mapcopy[begin->pos_y - 1][begin->pos_x] == '0')
		data->mapcopy[begin->pos_y - 1][begin->pos_x] = 'X';
	if (data->mapcopy[begin->pos_y + 1][begin->pos_x] == '0')
		data->mapcopy[begin->pos_y + 1][begin->pos_x] = 'X';
}

void	ft_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'X')
			{
				if (data->mapcopy[i][j - 1] == '0')
					data->mapcopy[i][j - 1] = 'X';
				if (data->mapcopy[i][j + 1] == '0')
					data->mapcopy[i][j + 1] = 'X';
				if (data->mapcopy[i - 1][j] == '0')
					data->mapcopy[i - 1][j] = 'X';
				if (data->mapcopy[i + 1][j] == '0')
					data->mapcopy[i + 1][j] = 'X';
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_maperror(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'X')
			{
				if (data->mapcopy[i][j - 1] != 'X' && data->mapcopy[i][j - 1] != '1')
					return(1);
				if (data->mapcopy[i][j + 1] != 'X' && data->mapcopy[i][j + 1] != '1')
					return(1);
				if (data->mapcopy[i - 1][j] != 'X' && data->mapcopy[i - 1][j] != '1')
					return(1);
				if (data->mapcopy[i + 1][j] != 'X' && data->mapcopy[i + 1][j] != '1')
					return(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
    return(0);
}


void	ft_conditions(t_data *data)
{
	int	imax;

	imax = 5000;
	
    while (imax > 0)
	{
		imax--;
		ft_path(data);
	}
    if (ft_maperror(data) == 1)
    {
        printf("%s \n", "Error\n Map error");
        exit(1);
    }
}

void	ft_p(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (data->mapcopy[i])
	{
		while (data->mapcopy[i][j])
		{
			if (data->mapcopy[i][j] == 'N' || data->mapcopy[i][j] == 'S'
                || data->mapcopy[i][j] == 'W' || data->mapcopy[i][j] == 'E')
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	if (k != 1)
	{
		printf("%s", "Error \nNo starting point or Too many starting point\n");
		exit(1);
	}
}

void    ft_map_parsing(t_data *data)
{
    t_p begin;
    int i = 0;
    int j = 0;
    data->mapcopy = data->map;
    ft_p(data);
    ft_pos_player(&begin, data);
    printf("22222 \n");
    ft_fill(&begin, data);
    ft_conditions(data);
    printf("33333 \n");
    /*
    while(data->mapcopy[i])
    {
        printf("%s\n", data->mapcopy[i]);
        i++;
    }
    */
}
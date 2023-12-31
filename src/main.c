/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:51:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/24 14:51:42 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fileok(char **av)
{
	if (access(av[1], F_OK) == -1)
	{
		printf("%s\n", "Error\n File does not exist");
		exit(1);
	}
	if (access(av[1], R_OK) == -1)
	{
		printf("%s\n", "Error\n File cannot be read");
		exit(1);
	}
	if (open(av[1], O_RDONLY) < 0)
	{
		printf("%s\n", "Error\n .cub file CHMOD problem");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_parsing(ac, av, &data);
	fileok(av);
	if (ac > 2 || ac == 1)
	{
		printf("%s \n", "Error\nPlease only .cub map as argument");
		return (0);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D !");
	data.height = HEIGHT;
	data.width = WIDTH;
	draw_map(&data);
	ft_binds(&data);
	mlx_loop(data.mlx);
	ft_cleartab(data.map);
}

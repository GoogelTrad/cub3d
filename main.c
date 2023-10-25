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

int	main(int ac, char **av)
{
    t_data data;

    ft_parsing(ac, av, &data);
    if (ac > 2 || ac == 1)
    {
        printf("%s \n", "Error\nPlease only .cub map as argument");
        return(0);
    }
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D !");
    ft_binds(data);
	mlx_loop(data.mlx);
}

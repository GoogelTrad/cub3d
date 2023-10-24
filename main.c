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
    t_vars var;
    //ft_parsing(ac, av);
    if (ac > 2 || ac == 1)
    {
        printf("%s \n", "Error\nPlease only .cub map as argument");
        return(0);
    }
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 1920, 1080, "Hello world!");
    ft_binds(var);
	mlx_loop(var.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:00:38 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/25 15:00:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	d_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	handle_key_press(int keycode, t_data *data)
{
    //printf("%d \n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 119) 
		move_up(data);
	else if (keycode == 115)
		move_down(data);
	else if (keycode == 100)
		move_right(data);
	else if (keycode == 97)
		move_left(data);
	else if (keycode == 65361)
		cam_right(data);
	else if (keycode == 65363)
		cam_left(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ref, 0, 0);
	return (0);
}

void ft_binds(t_data *data)
{
    mlx_hook(data->win, 2, 1L << 0, handle_key_press, data);
    mlx_hook(data->win, 17, 0L, d_close, data);
}
#include "cub3d.h"

int	d_close(t_vars *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}

int	handle_key_press(int keycode, t_vars *var)
{
    //printf("%d \n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	return (0);
}

void ft_binds(t_vars var)
{
    mlx_hook(var.win, 2, 1L << 0, handle_key_press, &var);
    mlx_hook(var.win, 17, 0L, d_close, &var);
}
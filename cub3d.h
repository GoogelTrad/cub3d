/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:38:37 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/24 15:38:37 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

# define WIDTH 1366
# define HEIGHT 768

# define BUFFER_SIZE 1
//# define space ' ', '\t', '\r', '\v'

typedef struct s_cub
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
    char **noemptyline;
}   t_cub;

typedef struct s_size
{
	int y;
	int x;
}	t_size;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_img
{
	void *ref;
	char *addr;
	int bpp;
	int lenght;
	int endian;
	int color;
	t_size size;
}	t_img;

typedef struct s_stock
{
	t_img wall;
	t_img floor;
	t_img test;
	t_img player;
} t_stock;

typedef struct s_data
{
	void	*mlx;
	void	*win;
    char    **cubs;
	char	**map;
    char    **mapcopy;
	t_player player;
	t_stock	stock;
	t_img	img;
}	t_data;


//parsing_map.c
void	ft_parsing(int ac, char **av, t_data *data);
void	ft_binds(t_data *data);


//parsing_map2.c
void    ft_map_parsing(t_data *data);

//utils.c
int		count_line(char *pathname);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strncat(char *dest, char *src, int n);
char	*ft_strjoin2(char *s1, char *s2);

//get_next_line.c
char    *get_next_line(int fd);

//image.c
void	draw_square(t_img img, t_data *data, int pos_x, int pos_y);
t_stock init_img();
void my_put_pixel(t_data *data);
void pixel(t_data *data, int x, int y, int color);
void coucou(t_data *data);

//map.c
void draw_map(t_data *data);

//player.c
void move_up(t_data *data);
void move_down(t_data *data);
void move_right(t_data *data);
void move_left(t_data *data);

#endif
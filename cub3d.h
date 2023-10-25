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

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
}				t_data;


//parsing_map.c
void	ft_parsing(int ac, char **av, t_data *data);
void	ft_binds(t_data data);

//utils.c
int		count_line(char *pathname);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

//get_next_line.c
char    *get_next_line(int fd);

#endif
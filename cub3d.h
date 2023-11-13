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
#include <math.h>
#include "libft/libft.h"

# define WIDTH 1366 // largeur // x
# define HEIGHT 768 // hauteur // y

# define SPEED 0.3
# define GRID 1
# define BUFFER_SIZE 1
//# define space ' ', '\t', '\r', '\v'
# define PI 3.141592653

typedef struct s_cub
{
    char *no;
    char *so;
    char *we;
    char *ea;
    char *f;
    char *c;
    char **noemptyline;
    char **txt;
}   t_cub;

typedef struct s_size
{
	int y;
	int x;
	int z;
}	t_size;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_ray
{
	float	deltaX;
	float	deltaY;
	float	planeY;
	float	planeX;
	float	ray_dirX;
	float	ray_dirY;
	float	delta_distX;
	float	delta_distY;
	int		stepX;
	int		stepY;
	float	sideDistX;
	float	sideDistY;
	float	wall_dist;
	int		mapX;
	int		mapY;
	int		wall;
	int		side;
	int		hauteur_wall;
	int		begin_wall;
	int		end_wall;
}	t_ray;

typedef struct s_player
{
	t_pos	pos;
	float delta_x;
	float delta_y;
	float angle;
}	t_player;

typedef struct s_p
{
    int        pos_x;
    int        pos_y;
}    t_p;

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
	int		width;
	int		height;
    char    *floor;
    char    *ceiling;
	t_player player;
	t_ray	ray;
	t_stock	stock;
	t_img	img;
    t_cub   cub;
}	t_data;

//parsing_map.c
void	ft_parsing(int ac, char **av, t_data *data);
void	ft_binds(t_data *data);
int     tabsize(char **cubs);


//parsing_map2.c
void    ft_map_parsing(t_data *data);

//utils.c
int		count_line(char *pathname);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strncat(char *dest, char *src, int n);
char	*ft_strjoin2(char *s1, char *s2);

//utils2.c
int     tabsize(char **cubs);
void    ft_cleartab(char **tab);
void    ft_missing_info_cub();
void    ft_error_rgb();
int     longestlen(char **map);

//get_next_line.c
char    *get_next_line(int fd);

//image.c
t_stock init_stock();
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void render_rect(t_img *img, t_img *rect, int pos_x, int pos_y);
void render_player(t_img  *img, t_data *data, int pos_x, int pos_y);

//map.c
void	draw_map(t_data *data);
void	render_background(t_img *img, t_data *data);
int		wall_collision(t_data *data);
void	final_draw(t_data *data, t_player *player, t_ray *ray, t_img *img);

//player.c
void	init_player(t_data *data, int x, int y, char angle);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void 	cam_left(t_data *data);
void 	cam_right(t_data *data);

//cub3d.c
void draw_rays(t_data *data, t_ray *ray, t_player *player);

//colors.c
void    ft_format_color(t_data *data, char *lignecouleur, int f_c);

//parsing_cub.c
void    ft_fill_f(t_cub *cub);
void    ft_fill_w(t_cub *cub);
void    ft_fill_e(t_cub *cub);
void    ft_fill_s(t_cub *cub);
void    ft_fill_n(t_cub *cub);

//parsing_cub2.c
void    ft_all_infos_cub(t_cub *cub, char **noemptyline);
t_cub   ft_textures(char **cubs, t_data *data);

//parsing_cub3.c
void    ft_check_wall_dif(t_cub *cub);
void    ft_check_dif_txt(char **txt);
void    ft_check_open_txt(char **txt);

//parsing_texture.c
int    ft_check_all_texture(char **noemptyline, char c, char d);

#endif
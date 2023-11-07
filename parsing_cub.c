#include "cub3d.h"

void    ft_fill_n(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->noemptyline[i])
    {
        if (cub->noemptyline[i][0] == 'N')
            cub->no = ft_strdup(cub->noemptyline[i]);
        i++;
    }
}

void    ft_fill_s(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->noemptyline[i])
    {
        if (cub->noemptyline[i][0] == 'S')
            cub->so = ft_strdup(cub->noemptyline[i]);
        i++;
    }
}

void    ft_fill_e(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->noemptyline[i])
    {
        if (cub->noemptyline[i][0] == 'E')
            cub->ea = ft_strdup(cub->noemptyline[i]);
        i++;
    }
}

void    ft_fill_w(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->noemptyline[i])
    {
        if (cub->noemptyline[i][0] == 'W')
            cub->we = ft_strdup(cub->noemptyline[i]);
        i++;
    }
}

void    ft_fill_f(t_cub *cub)
{
    int i;
    
    i = 0;
    while (cub->noemptyline[i])
    {
        if (cub->noemptyline[i][0] == 'F')
            cub->f = ft_strdup(cub->noemptyline[i]);
        i++;
    }
}
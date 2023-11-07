#include "cub3d.h"

void    ft_check_range_rgb(char **rgb)
{
    int i;

    i = 0;
    while (rgb[i])
    {
        if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
            ft_error_rgb();
        i++;
    }
}

void    to_hexa(int rgb, int color, char *hexa, int j)
{
    char *tmp;
    int hold;
    int i;

    i = 0;
    tmp = "0123456789ABCDEF";
    if (rgb < 16)
    {
        while (rgb > 0)
        {
            rgb--;
            i++;
        }
        hexa[j] = '0';
        hexa[j + 1] = tmp[i]; 
    }
    else
    {
        hold = rgb % 16;
        while (hold > 0)
        {
            i++;
            hold--;
        }
        hexa[j + 1] = tmp[i];
        rgb = rgb / 16;
        i = 0;
        while (rgb > 0)
        {
            rgb--;
            i++;
        }
        hexa[j] = tmp[i];
    }
}

void    ft_couleur(t_data *data, char **rgb, int f_c)
{
    int r;
    int g;
    int b;
    char *hexa;

    hexa = malloc(sizeof(char) * 9);
    hexa[0] = '0';
    hexa[1] = 'x';
    ft_check_range_rgb(rgb);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    to_hexa(r, 1, hexa, 2);
    to_hexa(g, 2, hexa, 4);
    to_hexa(b, 3, hexa, 6);
    hexa[8] = '\0';
    if (f_c == 1)
        data->floor = ft_strdup(hexa);
    else
        data->ceiling = ft_strdup(hexa);
    free(hexa);
}



void    ft_format_color2(t_data *data, char *rgb, int f_c)
{
    char **tmp;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = ft_split(rgb, ',');
    if (tabsize(tmp) != 3)
        ft_error_rgb();
    while(tmp[i])
    {
        while (tmp[i][j] && tmp[i][j] != 13)
        {
            if (ft_isdigit(tmp[i][j]) == 0)
                ft_error_rgb();
            j++;
        }
        j = 0;
        i++;
    }
    ft_couleur(data, tmp, f_c);
}

void    ft_format_color(t_data *data, char *lignecouleur, int f_c)
{
    char **tmp;
    
    tmp = ft_split(lignecouleur, ' ');
    if (tabsize(tmp) != 2)
    {
        ft_cleartab(tmp);
        tmp = ft_split(lignecouleur, '\t');
        if (tabsize(tmp) != 2)
        {
            printf("%s \n", "Error\n problem in the .cub");
            free(tmp);
            exit(1);
        }
    }
    ft_format_color2(data, tmp[1], f_c);
    ft_cleartab(tmp);
}
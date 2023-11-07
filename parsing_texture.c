#include "cub3d.h"

int    ft_check_all_texture(char **noemptyline, char c, char d)
{
    int i;

    i = 0;
    if (d != 'X')
    {
        while (noemptyline[i])
        {
            if (noemptyline[i][0] == c && noemptyline[i][1] == d)
                return(0);
            i++;
        }
    }
    else
    {
        while (noemptyline[i])
        {
            if (noemptyline[i][0] == c)
                return(0);
            i++;
        }
    }
    return(1);
}
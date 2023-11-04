#include "cub3d.h"

void	ft_args(int ac, char **av)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], '.');
	while (split[i] != NULL)
		i++;
	if (ft_strncmp(split[i - 1], "cub", 3) != 0)
	{
		printf("%s", "Error \nonly put a .cub argument \n");
		exit(1);
	}
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}   

void	ft_cub(int ac, char **av)
{
	if (open(av[1], O_RDONLY) < 0)
	{
		printf("%s", "ERROR \nMap .cub file doesnt exist \n");
		exit(1);
	}
	if (ac > 2)
	{
		printf("%s", "Error \ntoo many args \n");
		exit(1);
	}
	else if (ac < 2)
	{
		printf("%s", "Error \nadd a .cub file as arg \n");
		exit(1);		
	}
}

int    ft_top_and_bot(char **map, int i)
{
    int j;
    j = 0;

    while (map[i][j] == ' ' || map[i][j] == '\t' 
        || map[i][j] == '\v')
        j++;
    while (map[i][j] != 13 && map[i][j] != '\0')
    {
        if (map[i][j] != '1' && map[i][j] != ' '
            && map[i][j] != '\t' && map[i][j] != '\v')
        {
            printf("Error\n Map not closed\n");
            exit(1);
        }
        j++;
    }
    return(0);
}

/*
void    ft_closed_map(char **map)
{
    int i = 0;
    int j = 0;
    while (map[i])
    {
        while (map[i][j] == ' ')
            j++;
        if (ft_isdigit(map[i][j]) == 1)
        {
            printf("AAAAA \n \n");
            //exit(2);
        }
        else
        {
            printf("%s \n", "Error \n MAP PROBLEMS");
            exit(1);
        }
    }
    j = 0;
}
*/

int     countmapline(char **cubs)
{
    int lines;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;

    while (cubs[i])
    {
        while(cubs[i][j] == ' ')
            j++;
        if (ft_isdigit(cubs[i][j]) == 0)
            i++;
        else
        {
            k = i;
            while(cubs[i])
                i++;
            return(i - k);
        }
        j = 0;
    }
    return(i - k);
}

char **initmap2(char **cubs)
{
    int i;
    char **map;
    int sizemap;
    int j;

    i = 0;
    j = 0;
    sizemap = countmapline(cubs);
    while (cubs[i])
        i++;
    map = malloc(sizeof(char *) * (sizemap + 1));
    i -= (sizemap);
    while (cubs[i])
    {
        if (cubs[i] == NULL)
            i++;
        else
            map[j] = ft_strdup(cubs[i]);
        i++;
        j++;
    }
    map[j] = NULL;
    return(map);
}

void	ft_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != 13 && map[i][j] != '\0')
		{
			if (map[i][j] != 'N' && map[i][j] != 'E'
			&& map[i][j] != 'S' && map[i][j] != 'W'
			&& map[i][j] != '0' && map[i][j] != '1'
            && map[i][j] != ' ' && map[i][j] != '\t')
			{
				printf("%s", "Error \nA Not recognized char in the map \n");
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
char    *ft_texture_no(char **cubs)
{
    int i;
    char *texture_no;
    char *tmp;

    i = 0;
    texture_no = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'N' && cubs[i][1] != 'O')
            i++;
        if (cubs[i][0] == 'N' && cubs[i][1] == 'O')
            texture_no = ft_strdup(cubs[i]);
        else
        {
            printf("%s \n", "Error\n missing North texture");
            exit(1);
        }
    }
    return(texture_no);
}

char    *ft_texture_so(char **cubs)
{
    int i;
    char *texture_so;
    char *tmp;

    i = 0;
    texture_so = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'S' && cubs[i][1] != 'O')
            i++;
        if (cubs[i][0] == 'S' && cubs[i][1] == 'O')
        {
            texture_so = ft_strdup(cubs[i]);
            return(texture_so);
        }
        else
        {
            printf("%s \n", "Error\n missing South texture");
            exit(1);
        }
    }
    return(texture_so);
}

char    *ft_texture_we(char **cubs)
{
    int i;
    char *texture_we;
    char *tmp;

    i = 0;
    texture_we = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'W' && cubs[i][1] != 'E')
            i++;
        if (cubs[i][0] == 'W' && cubs[i][1] == 'E')
        {
            texture_we = ft_strdup(cubs[i]);
            return(texture_we);
        }
        else
        {
            printf("%s \n", "Error\n missing West texture");
            exit(1);
        }
    }
    return(texture_we);
}

char    *ft_texture_ea(char **cubs)
{
    int i;
    char *texture_ea;
    char *tmp;

    i = 0;
    texture_ea = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'E' && cubs[i][1] != 'A')
            i++;
        if (cubs[i][0] == 'E' && cubs[i][1] == 'A')
        {
            texture_ea = ft_strdup(cubs[i]);
            return(texture_ea);
        }
        else
        {
            printf("%s \n", "Error\n missing East texture");
            exit(1);
        }
    }
    return(texture_ea);
}

char    *ft_floor_colors(char **cubs)
{
    int i;
    char *floor_co;
    char *tmp;

    i = 0;
    floor_co = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'F')
            i++;
        if (cubs[i][0] == 'F')
        {
            floor_co = ft_strdup(cubs[i]);
            return(floor_co);
        }
        else
        {
            printf("%s \n", "Error\n missing Floor color");
            exit(1);
        }
    }
    return(floor_co);
}

char    *ft_roof_colors(char **cubs)
{
    int i;
    char *roof_co;
    char *tmp;

    i = 0;
    roof_co = ft_strdup("");
    while (cubs[i])
    {
        while(cubs[i][0] != 'F')
            i++;
        if (cubs[i][0] == 'F')
        {
            roof_co = ft_strdup(cubs[i]);
            return(roof_co);
        }
        else
        {
            printf("%s \n", "Error\n missing roof color");
            exit(1);
        }
    }
    return(roof_co);
}
*/

int     ft_beforemap(char **cubs, int sizecub, int mapsize)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < sizecub - mapsize)
    {
        if (cubs[i] == NULL || cubs[i][0] == '\0')
            i++;
        else
        {
            j++;
            i++;
        }
    }
    return(j);
}

char    **parscub(char **cubs, int mapsize, int sizecub)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < sizecub - mapsize)
    {
        if (cubs[i] == NULL)
            i++;
        j++;
        i++;
    }
}

void	ft_mapsave(int ac, char **av, t_data *data)
{
	int		fd;
	char	*str;
	char	*x;
	char	*temp;

	fd = open(av[1], O_RDONLY);
	str = ft_strdup("");
	while (1)
	{
		x = get_next_line(fd);
		if (x == NULL)
			break ;
		else
		{	
			temp = str;
			str = ft_strjoin2(temp, x);
		}
	}
	data->cubs = ft_split(str, '\n');
    free(str);
}

void    ft_leftside(char **map)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[i])
    {
        if (map[i][j] != '1' && map[i][j] != ' '
            && map[i][j] != '\t' && map[i][j] != 13)
        {
            printf("Error \n map not closed \n");
            exit(1);
        }
        i++;
    }
}

void    ft_rightside(char **map)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(map[i])
    {
        
        j = ft_strlen(map[i]) - 2;
        if (map[i][j] != '1' && map[i][j] != ' '
            && map[i][j] != '\t')
        {
            printf("Error \n map not closed \n");
            exit(1);
        }
        i++;
    }
}

int     tabsize(char **cubs)
{
    int i;

    i = 0;
    while(cubs[i])
        i++;
    return(i);
}


int   noemptyline(char **cubs, t_cub *cub, int sizecub, int mapsize)
{
    int i;
    char *tmp;
    int j;

    i = 0;
    j = 0;
    while (i < sizecub - mapsize)
    {
        tmp = ft_strtrim(cubs[i], "\t ");
        if (ft_isalnum(tmp[0]) == 1)
            j++;
        i++;
        free(tmp);
    }
    if (j != 6)
    {
        printf("%s \n", "Error\n, problem in the .cub file");
        exit(1);
    }
    return(j);
}

void    noemptyline2(char **cubs, t_cub *cub, int sizecub, int mapsize)
{
    int j;
    int i;
    int lines;
    char *tmp;
    char *tmp2;

    j = 0;
    i = 0;
    lines = noemptyline(cubs, cub, sizecub, mapsize);
    cub->noemptyline = malloc(sizeof(char *) * (lines + 1));
    //printf("%s\n", cub->noemptyline[0]);
    while (i <= sizecub - mapsize)
    {
        tmp = ft_strtrim(cubs[i], " \t");
        if (ft_isalpha(tmp[0]) == 1)
        {
            cub->noemptyline[j] = ft_strdup(tmp);
            j++;
        }
        free(tmp);
        i++;
    }
   // printf("%d \n", lines);
   // printf("%d \n", j);
    cub->noemptyline[j] = NULL;
}

void    ft_cleartab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void    ft_format_texture(char **noemptyline, int i, char c, char d)
{
    char **tmp;
    
    tmp = ft_split(noemptyline[i], ' ');
    if (tabsize(tmp) != 2)
    {
        ft_cleartab(tmp);
        tmp = ft_split(noemptyline[i], '\t');
        if (tabsize(tmp) != 2)
        {
            printf("%s \n", "Error\n problem in the .cub");
            free(tmp);
            exit(1);
        }
    }
    if (tmp[0][0] != c || tmp[0][1] != d)
    {
            printf("%s \n", "Error\n problem in the .cub");
            free(tmp);
            exit(1);
    }
    ft_cleartab(tmp);
}

void    ft_format_color(char **noemptyline, int i, char c)
{
    char **tmp;
    
    tmp = ft_split(noemptyline[i], ' ');
    if (tabsize(tmp) != 2)
    {
        ft_cleartab(tmp);
        tmp = ft_split(noemptyline[i], '\t');
        if (tabsize(tmp) != 2)
        {
            printf("%s \n", "Error\n problem in the .cub");
            free(tmp);
            exit(1);
        }
    }
    if (tmp[0][0] != c)
    {
        printf("%s \n", "Error\n problem in the .cub");
        free(tmp);
        exit(1);
    }
    ft_cleartab(tmp);
}

t_cub   ft_textures(char **cubs, t_data *data)
{
    //check order in .cub
    int i = 0;
    t_cub cub;
    
    noemptyline2(data->cubs, &cub, tabsize(data->cubs), tabsize(data->map));
    //ft_order(cub.noemptyline, 0, 'N', 'O');
    //ft_order(cub.noemptyline, 1, 'S', 'O');
    //printf("%p\n", &cub);
    while (cub.noemptyline[i])
    {
        //printf("%s\n", cub.noemptyline[i]);
        i++;
    }
    //printf("0\n");
    ft_format_texture(cub.noemptyline, 0, 'N', 'O');
    //printf("1\n");
    ft_format_texture(cub.noemptyline, 1, 'S', 'O');
    ft_format_texture(cub.noemptyline, 2, 'W', 'E');
    ft_format_texture(cub.noemptyline, 3, 'E', 'A');
    ft_format_color(cub.noemptyline, 4, 'F');
    ft_format_color(cub.noemptyline, 5, 'C');
    /*
    A reutiliser lorsqu'on aura les textures a initialiser
    modif les fonction pour check si open texture
    cub.no = ft_texture_no(cubs);
    cub.so = ft_texture_so(cubs);
    cub.we = ft_texture_we(cubs);
    cub.ea = ft_texture_ea(cubs);
    cub.f = ft_floor_colors(cubs);
    cub.c = ft_roof_colors(cubs);
    */
    //check if value (post Identifiant) is correct
    return(cub);
}

int     longestlen(char **map)
{
    int i;
    int len;
    
    i = 0;
    len = 0;
    while (map[i])
    {
        if (ft_strlen(map[i]) < len)
            len = ft_strlen(map[i]);
        i++;
    }
    return(len);
}



void    ft_parsing(int ac, char **av, t_data *data)
{
	int i;
    int j;
	i = 0;
    int y = 0;
	ft_cub(ac, av);
    ft_args(ac, av);
    ft_mapsave(ac, av, data);
    data->map = initmap2(data->cubs);
    ft_textures(data->cubs, data);
    ft_top_and_bot(data->map, 0);
    ft_leftside(data->map);
    ft_rightside(data->map);
    ft_top_and_bot(data->map, countmapline(data->cubs) - 1);
    ft_char(data->map);
    ft_map_parsing(data);
}


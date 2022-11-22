/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:54 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/22 15:02:15 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool  check_cub(char *file)
{
    int len;

    len = ft_strlen(file) - 1;
    if (file[len] == 'b')
        if (file[--len] == 'u')
            if (file[--len] == 'c')
                if (file[--len] == '.')
                    if (file[--len] != '.')
                        return (true);
    write(2, "Please, provide .cub file\n", 27);
    return (false);
}

int check_line(char *line)
{
    int i;

    i = -1;
    while(line[++i])
    {
        if (ft_strchr("NSEWFC", line[i]))
            return (1);
        if (!line[i])
            break ;
    }
    return (0);
}

char    *create_map_from_file(t_data *data, int fd, char *line)
{
    char    *tmp;

    tmp = NULL;
    while (line != NULL)
    {
        tmp = gc_strjoin(&data->track, tmp, line);
        line = gc_get_next_line(&data->track, fd);
    }
    return (tmp);
}

char	*get_map_from_file(t_data *data, char *filename)
{
	int     i;
    int     fd;
    int     count;
    char    *line;
    char    *map;

    i = 0;
    count = 0;
    fd = open_file(filename);
    if (fd == -1)
        return (NULL);
    line = gc_get_next_line(&data->track, fd);
    while (line != NULL)
    {
        if (count == 6)
            map = create_map_from_file(data, fd, line);
        if (check_line(line) && count != 6)
            count++;
        line = gc_get_next_line(&data->track, fd);
    }
    close(fd);
    return (map);
}

char    *_get_file(t_data *data, int fd)
{
    char    *file;
    char    *line;

    line = gc_get_next_line(&data->track, fd);
    file = NULL;
    while (line != NULL)
    {
        file = gc_strjoin(&data->track, file, line);
        line = gc_get_next_line(&data->track, fd);
    }
    return (file);
}

char    **get_cub_file(t_data *data, char *filename)
{
    char    **file;
    char    *get_file;
    int     fd;
    
    fd = 0;
    file = NULL;
    if (check_cub(filename) == false)
        return (NULL);
    fd = open_file(filename);
    if (fd == -1)
        return (NULL);
    get_file = _get_file(data, fd);
    file = gc_split(&data->track, get_file, '\n');
    close(fd);
    return (file);
}

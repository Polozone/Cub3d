/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:54 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/21 11:35:06 by tdeville         ###   ########lyon.fr   */
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
        if (ft_strchr("NSEW", line[i]))
            return (1);
        if (ft_strchr("FC", line[i]))
            return (1);
    }
    return (0);
}

char    *create_map_from_file(int fd, char *line)
{
    char    *tmp;
    char    *tmp1;

    tmp = NULL;
    tmp1 = NULL;
    while (line != NULL)
    {
        if (tmp)
            tmp1 = tmp;
        tmp = ft_strjoin(tmp, line);
        if (tmp1)
            free(tmp1);
        line = get_next_line(fd);
    }
    return (tmp);
}

char	*get_map_from_file(char *filename)
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
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (count == 6)
            map = create_map_from_file(fd, line);
        if (check_line(line) && count != 6)
            count++;
        line = get_next_line(fd);
    }
    close(fd);
    return (map);
}

char    *_get_file(int fd)
{
    char    *file;
    char    *line;
    char    *tmp;

    line = get_next_line(fd);
    file = NULL;
    tmp = NULL;
    while (line != NULL)
    {
        if (!file)
            file = ft_strdup(line);
        else
        {
            tmp = file;
            file = ft_strjoin(file, line);
            free(tmp);
        }
        free(line);
        line = get_next_line(fd);
    }
    if (line)
        free(line);
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
    get_file = _get_file(fd);
    file = ft_split(get_file, '\n');
    free(get_file);
    close(fd);
    get_map_from_file(filename);
    return (file);
}

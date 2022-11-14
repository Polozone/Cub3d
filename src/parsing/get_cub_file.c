/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:54 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/14 09:49:31 by pmulin           ###   ########.fr       */
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
    fd = open(filename, O_DIRECTORY);
    if (fd != -1)
    {
        close(fd);
        write(2, "Please, provide .cub FILE\n", 27);
        return (NULL);
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror(filename);
        return (NULL);
    }
    get_file = _get_file(fd);
    file = ft_split(get_file, '\n');
    free(get_file);
    return (file);
}

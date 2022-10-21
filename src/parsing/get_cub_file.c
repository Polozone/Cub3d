/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:54 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 13:05:18 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

char    **get_cub_file(char *filename)
{
    char    **file;
    char    *get_file;
    int     fd;
    
    file = NULL;
    fd = open(filename, O_RDONLY);
    get_file = _get_file(fd);
    file = ft_split(get_file, '\n');
    free(get_file);
    return (file);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:46:54 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 09:37:23 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("NSEWFC", line[i]))
			return (1);
	}
	return (0);
}

char	*create_map_from_file(t_data *data, int fd, char *line)
{
	char	*tmp;

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
	int		fd;
	int		count;
	char	*line;
	char	*map;

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

char	*_get_file(t_data *data, int fd)
{
	char	*file;
	char	*line;

	line = gc_get_next_line(&data->track, fd);
	file = NULL;
	while (line != NULL)
	{
		file = gc_strjoin(&data->track, file, line);
		line = gc_get_next_line(&data->track, fd);
	}
	return (file);
}

char	**get_cub_file(t_data *data, char *filename)
{
	char	**file;
	char	*get_file;
	int		fd;

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

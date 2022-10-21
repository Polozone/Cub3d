/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/21 16:19:17 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		convert_to_map(t_data *data, char *line, int longest_line, int nbr_line)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	j = 0;
	x = 0;
	while (++i < nbr_line)
		data->maps->map[i] = malloc(sizeof(char) * (longest_line + 1));
	data->maps->map[i] = 0;
	i = -1;
	while (++i < nbr_line)
	{
		x = 0;
		while (line[j] && line[j] != '\n')
		{
			data->maps->map[i][x++] = line[j];
			j++;
		}
		while (x < longest_line)
			data->maps->map[i][x++] = ' ';
		data->maps->map[i][x] = 0;
		j++;
	}
	free(line);
}

t_bool			check_charmap(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (is_charmap(line[i] == false))
		{
			write(2, "Invalid char in the map\n", 24);
			return (false);
		}
		i++;
	}
	return (true);
}

static void		str_to_map(t_data *data, int fd, char *tmp)
{
	int		nbr_line;
	char	*line_clear;

	tmp = data->map_line;
	data->map_line = ft_strtrim(data->map_line, "\n");
	free(tmp);
	line_clear = clear_endmap(data->map_line);
	data->maps->longest_line = get_longest_line(line_clear);
	nbr_line = count_nl(line_clear);
	data->maps->map = malloc(sizeof(char *) * (nbr_line + 1));
	convert_to_map(data, line_clear, data->maps->longest_line, nbr_line);
	close(fd);
}

int		init_parsing_map(t_data *data, t_map *map, char *argv)
{
	int		fd;
	char	*tmp;

	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		write(2, "Error opening map\n", 18);
		return (-1);
	}
	data->maps = map;
	data->maps->map = NULL;
	if (check_charmap(data->map_line) == false)
		return (-1);
	str_to_map(data, fd, tmp);
	if (is_valid_map(data) == false)
		return (-1);
	// print_map(data->maps->map);
	return (0);
}
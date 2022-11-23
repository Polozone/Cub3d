/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 13:37:32 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	convert_to_map(t_data *data, char *line,
			int longest_line, int nbr_line)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	j = 0;
	x = 0;
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
	data->maps->map[i] = 0;
	free(line);
}

t_bool	check_charmap(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (is_charmap(line[i]) == false)
		{
			write(2, "Error\nInvalid char in the map", 29);
			return (false);
		}
		i++;
	}
	return (true);
}

static t_bool	check_nl(char *map)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	while (map[i] == '\n' || map[i] == ' ' || map[i] == '	')
	{
		if (map[i] == '\n')
			cmpt++;
		if (cmpt > 1)
			return (true);
		i++;
	}
	return (false);
}

static t_bool	is_consecutive_nl(char *map)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (check_nl(&map[i]) == true)
			{
				write(2, "Error\nInvalid map", 17);
				exit (-1);
			}
		}
		i++;
	}
	return (true);
}

void	str_to_map(t_data *data, int fd, char *tmp, int i)
{
	int		nbr_line;
	char	*line_clear;

	tmp = data->map_line;
	data->map_line = ft_strtrim_lastnl(data->map_line, "\n 	", 0);
	is_consecutive_nl(data->map_line);
	line_clear = clear_endmap(data->map_line);
	data->maps->longest_line = get_longest_line(line_clear);
	nbr_line = count_nl(line_clear);
	data->maps->map = malloc(sizeof(char *) * (nbr_line + 1));
	if (data->maps->map == NULL)
		exit (1);
	while (++i < nbr_line)
		data->maps->map[i] = malloc(sizeof(char)
				* (data->maps->longest_line + 1));
	if (data->maps->map[i] == NULL)
	{
		data->maps->map[i] = malloc(sizeof(char)
				* (data->maps->longest_line + 1));
		if (data->maps->map[i] == NULL)
			free_arr_from_end(data, data->maps->map, i);
	}
	convert_to_map(data, line_clear, data->maps->longest_line, nbr_line);
	close(fd);
}

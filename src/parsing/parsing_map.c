/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/20 16:28:42 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		convert_to_map(t_data *data, char *line, int longest_line, int nbr_line)
{
	int		i;
	int		j;
	int		x;
	int		len_array;

	i = 0;
	j = 0;
	x = 0;
	len_array = count_nl(line);
	while (i < len_array)
	{
		data->maps->map[i] = malloc(sizeof(char) * (longest_line + 1));
		i++;
	}
	data->maps->map[i] = 0;
	i = 0;
	while (i < nbr_line)
	{
		x = 0;
		while (line[j] != '\n')
		{
			data->maps->map[i][x] = line[j];
			j++;
			x++;
		}
		while (x < longest_line)
		{
			data->maps->map[i][x] = ' ';
			x++;
		}
		data->maps->map[i][x] = 0;
		j++;
		i++;
	}
	// print_map(data->maps->map);
}

static void		str_to_map(t_data *data, char *argv)
{
	int		fd;
	char	*line;
	int		longest_line;
	int		nbr_line;

	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		write(2, "Error opening map\n", 18);
		return ;
	}
	line = _get_file(fd);
	line = ft_strtrim(line, "\n");
	clear_endmap(line);
	longest_line = get_longest_line(line);
	nbr_line = count_nl(line);
	data->maps->map = malloc(sizeof(char *) * (nbr_line + 1));
	convert_to_map(data, line, longest_line, nbr_line);
	close(fd);
}


int		init_parsing_map(t_data *data, t_map *map, char *argv)
{
	data->maps = map;
	str_to_map(data, argv);
	// get_longest_line(data);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/20 13:59:12 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		str_to_map(t_map *map, char *argv)
{
	int		fd;
	char	*line;

	(void)map;
	fd = open(argv, O_RDWR);
	line = _get_file(fd);
	printf("%s", line);
}

// int		get_longest_line(t_data *data)
// {
// 	return (0);
// }

int		init_parsing_map(t_data *data, t_map *map, char *argv)
{
	data->maps = map;
	str_to_map(map, argv);
	// get_longest_line(data);
	return (0);
}
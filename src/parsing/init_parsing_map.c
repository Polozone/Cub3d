/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:13:38 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 13:37:39 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_data_parse(t_data *data, t_render *render, t_map *map)
{
	data->col->h = 900;
	data->render = render;
	data->maps = map;
	data->maps->map = NULL;
	return ;
}

int	init_parsing_map(t_data *data, t_map *map, t_render *render, char *argv)
{
	int		fd;
	char	*tmp;

	tmp = NULL;
	fd = open(argv, O_RDWR);
	if (fd < 0)
		write(2, "Error opening map\n", 18);
	if (fd < 0)
		exit (1);
	init_data_parse(data, render, map);
	if (check_charmap(data->map_line) == false
		|| is_one_player(data->map_line) == false)
	{
		gc_free_all(&data->track);
		exit (-1);
	}
	str_to_map(data, fd, tmp, -1);
	if (is_valid_map(data->maps->map) == false)
	{
		free_2d_array(data->maps->map);
		write(2, "Error\nInvalid map", 17);
		return (-1);
	}
	data->maps->height = len_2d_array(data->maps->map);
	return (0);
}

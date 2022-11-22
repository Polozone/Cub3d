/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:13:38 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 14:44:32 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_parsing_map(t_data *data, t_map *map, t_render *render, char *argv)
{
	int		fd;
	char	*tmp;

	fd = open(argv, O_RDWR);
	if (fd < 0)
	{
		write(2, "Error opening map\n", 18);
		return (-1);
	}
	data->render = render;
	data->maps = map;
	data->maps->map = NULL;
	if (check_charmap(data->map_line) == false)
		exit (-1);
	if (is_one_player(data->map_line) == false)
		exit (-1);
	str_to_map(data, fd, tmp);
	if (is_valid_map(data->maps->map) == false)
	{
		write(2, "Error\nInvalid map", 17);
		return (-1);
	}
	data->maps->height = len_2d_array(data->maps->map);
	return (0);
}
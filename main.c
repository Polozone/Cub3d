/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/09 12:39:16 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_math(t_data *data)
{
	data->math->H_PI = M_PI / 180;
}


int main(int argc, char **argv)
{
    t_data  	data;
    t_map		map;
	t_render	render;
	t_prg		prg;
	t_math		math;
	// t_rad		rad;

    (void)argc;
	data.prg = &prg;
	data.math = &math;
	init_math(&data);
	// data.rad = &rad;
    // parse_map_params(&data, argv[1]);
    parse_map_params(&data, argv[1]);
	if (init_parsing_map(&data, &map, &render, argv[1]) == -1)
	{
		// free
		return (-1);
	}
	init_mlx(&data);
	free_2d_array(map.map);
    // get_cub_file(&data, argv[1]);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/08 09:55:22 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
    t_data  	data;
    t_map		map;
	t_render	render;
	t_prg		prg;
	t_rad		rad;

    (void)argc;
	// init_parsing_map(&data, &map, argv[1]);
	// free_2d_array(map.map);
    if (parse_map_params(&data, argv[1]) == true)
    {
        free(data.map_line);
        free_param_struct(&data);
    }
	data.prg = &prg;
	data.rad = &rad;
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

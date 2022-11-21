/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/21 12:16:57 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	loops_and_hooks(t_data *data)
{
	mlx_hook(data->render->mlx_win, 2, (1L << 0), deal_key, data);
	mlx_hook(data->render->mlx_win, 3, (1L << 1), key_release, data);
	mlx_loop_hook(data->render->mlx, update, data);
	mlx_loop(data->render->mlx);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_render	render;
	t_img		img;

    if (argc != 2)
		write(2, "Program need exactly two arguments\n", 35);
	data.ceil_color = 0;
	data.floor_color = 0;
    if (parse_map_params(&data, argv[1]) == false)
    {
        free(data.map_line);
        free_param_struct(&data);
    }
	data.wall = &img;
	if (init_parsing_map(&data, &map, &render, argv[1]) == -1)
	{
		// free
		return (-1);
	}
	init_mlx(&data);
	loops_and_hooks(&data);
	free_2d_array(map.map);
    return (0);
}

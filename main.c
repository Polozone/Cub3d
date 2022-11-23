/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 11:31:14 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	loops_and_hooks(t_data *data)
{
	mlx_hook(data->render->mlx_win, 2, (1L << 0), deal_key, data);
	mlx_hook(data->render->mlx_win, 3, (1L << 1), key_release, data);
	mlx_hook(data->render->mlx_win, 17, 0, exit_program, &data);
	mlx_loop_hook(data->render->mlx, update, data);
	mlx_loop(data->render->mlx);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_map		map;
	t_render	render;
	t_col		col;

	if (argc != 2)
	{
		write(2, "Program need exactly two arguments\n", 35);
		exit (-1);
	}
	data.col = &col;
	data.ceil_color = 0;
	data.floor_color = 0;
	if (parse_map_params(&data, argv[1]) == false)
		return (1);
	if (init_parsing_map(&data, &map, &render, argv[1]) == -1)
	{
		gc_free_all(&data.track);
		free(data.params);
		return (-1);
	}
	init_mlx(&data);
	loops_and_hooks(&data);
	return (0);
}

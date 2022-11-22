/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:47:45 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 14:07:07 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_win(t_data *data)
{
	void	*mlx;
	void	*mlx_window;

	data->render->cell_size = 40;
	data->render->mlx = mlx_init();
	if (data->render->mlx == NULL)
	{
		write(2, "Error\nduring initialization instance of mlx", 43);
		exit (-1);
	}
	data->render->mlx_win = mlx_new_window
		(data->render->mlx, WIDTH, HEIGHT, "CUB3D");
	data->render->img = mlx_new_image(data->render->mlx, WIDTH, HEIGHT);
	data->render->addr = mlx_get_data_addr
		(data->render->img,
			&data->render->bits_per_pixel,
			&data->render->line_length,
			&data->render->endian);
}

int	exit_program(t_data *data)
{
	gc_free_all(&data->track);
	mlx_destroy_window(data->render->mlx, data->render->mlx_win);
	exit(0);
}

int	update(t_data *data)
{
	player_input(data);
	clear_img(data);
	mlx_put_image_to_window(
		data->render->mlx,
		data->render->mlx_win,
		data->render->img, 0, 0);
	dda(data);
	mlx_put_image_to_window(data->render->mlx,
		data->render->mlx_win,
		data->render->img, 0, 0);
	return (0);
}

void	init_mlx(t_data *data)
{
	init_win(data);
	init_data(data);
	init_imgs(data);
	data->render->precompute_bits_p_px = data->render->bits_per_pixel >> 3;
	data->render->nbr_px = WIDTH * HEIGHT;
}

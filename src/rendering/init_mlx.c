/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:27:48 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/24 13:31:13 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int render_next_frame(void *program_struct)
{
	return (0);
}

int key_press(int keycode, t_render *program_struct)
{
	printf("Key pressed : %d\n", keycode);
	return (0);
}

void	init_mlx(t_data *data)
{
	void	*mlx;
	void	*mlx_window;
	mlx = mlx_init();
	if (mlx == NULL)
	{
		write(2, "Error during initialization instance of mlx\n", 44);
		exit (-1);
	}
	mlx_window = mlx_new_window(mlx, 1920, 1080, "My window");
	data->render->img = mlx_new_image(mlx, 1920, 1080);
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
	my_mlx_pixel_put(data->render, 350, 150, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_window, data->render->img, 0, 0);
	mlx_hook(mlx_window, 2, 0, key_press, data->render);
	mlx_loop_hook(mlx, render_next_frame, data->render);
	mlx_loop(mlx);
}
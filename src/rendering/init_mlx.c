/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:27:48 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/24 16:38:46 by pmulin           ###   ########.fr       */
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

void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right)
{
	int		tmp;

	tmp = top_left.y++;
	while (top_left.x < bottom_right.x)
	{
		top_left.x = tmp;
		while (top_left.y < bottom_right.y)
		{
			top_left.y++;
			my_mlx_pixel_put(render, top_left.x, top_left.y, 0x00FF0000);
		}
	}
	// my_mlx_pixel_put(render, top_left.x, top_left.y, 0x00FF0000);
	mlx_put_image_to_window(render->mlx, render->mlx_win, render->img, 0, 0);
}

void	print_grid(t_render *data)
{
	for (int y = 0; y < data->tab_height; y++)
	{
		for (int x = 0; x < data->tab_width; x++)
		{
			t_vector2_d top_left;
			t_vector2_d bottom_right;
			top_left.x = x * data->cell_size;
			top_left.y = y * data->cell_size;
			bottom_right.x = top_left.x + data->cell_size;
			bottom_right.y = top_left.y + data->cell_size;
			if (data->tab[y][x] == 1) // If the cell is a wall
			{
				draw_rect_color(data, top_left, bottom_right);
				// my_mlx_pixel_put(data, x * 50, y * 40, 0x00FF0000);
			}
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
		}
	}
}

int	init_tab(t_render *data)
{
	// Setting initial tab dimensions
	data->tab_height = 15;
	data->tab_width = 20;

	// Allocating tab
	data->tab = malloc(sizeof(int *) * data->tab_height);
	if (data->tab == NULL) // Checking allocation error
		return (1);
	for (int y = 0; y < data->tab_height; y++)
	{
		data->tab[y] = malloc(sizeof(int) * data->tab_width);
		if (data->tab[y] == NULL) // Checking allocation error
			return (1);
		for (int x = 0; x < data->tab_width; x++)
		{
			data->tab[y][x] = (y % 2 + x) % 2;
		}
	}
	return (0);
}

void	init_mlx(t_data *data)
{
	void	*mlx;
	void	*mlx_window;

	data->render->mlx = mlx_init();
	if (mlx == NULL)
	{
		write(2, "Error during initialization instance of mlx\n", 44);
		exit (-1);
	}
	data->render->mlx_win = mlx_new_window(data->render->mlx, 1000, 600, "My window");
	data->render->img = mlx_new_image(data->render->mlx, 1000, 600);
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
	my_mlx_pixel_put(data->render, 350, 150, 0x00FF0000);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	data->render->cell_size = 40;
	init_tab(data->render);
	print_grid(data->render);
	// mlx_hook(mlx_window, 2, 0, key_press, data->render);
	// mlx_loop_hook(mlx, render_next_frame, data->render);
	mlx_loop(data->render->mlx);
}
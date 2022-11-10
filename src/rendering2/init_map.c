/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:47:45 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/10 10:32:09 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right, int color)
{
	int		tmp;

	tmp = top_left.x;
	while (top_left.y < bottom_right.y)
	{
		top_left.x = tmp;
		while (top_left.x < bottom_right.x)
		{
			my_mlx_pixel_put(render, top_left.x, top_left.y, color);
			top_left.x++;
		}
		top_left.y++;
	}
}
void	print_grid(t_data *dt, t_render *data)
{
	int		x;
	int		y;

	y = 0;
	while (dt->maps->map[y])
	{
		x = 0;
		while (dt->maps->map[y][x])
		{
			t_vector2_d top_left;
	 		t_vector2_d bottom_right;
	 		top_left.x = x * data->cell_size;
	 		top_left.y = y * data->cell_size;
	 		bottom_right.x = top_left.x + data->cell_size;
	 		bottom_right.y = top_left.y + data->cell_size;
			if (dt->maps->map[y][x] == '1') // If the cell is a wall
	 			draw_rect_color(data, top_left, bottom_right, 16711680);
			else if (ft_strchr("NSWE0", dt->maps->map[y][x]))
				draw_rect_color(data, top_left, bottom_right, 0);
			x++;
		}
		y++;
	}
}
void	init_win(t_data *data)
{
	void	*mlx;
	void	*mlx_window;

	data->render->cell_size = 40;
	data->render->mlx = mlx_init();
	if (data->render->mlx == NULL)
	{
		write(2, "Error during initialization instance of mlx\n", 44);
		exit (-1);
	}
	// data->render->mlx_win = mlx_new_window(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size), "My window");
	data->render->mlx_win = mlx_new_window(data->render->mlx, 1200, 900, "My window");
	data->render->img = mlx_new_image(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size));
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
}

int	deal_key(int key, t_data *data)
{
	print_grid(data, data->render);
	if (key == 13)
		move_up(data);
	if (key == 0)
		move_left(data);
	if (key == 1)
		move_down(data);
	if (key == 2)
		move_right(data);
	return (0);
}

int _bresenham_test(t_render *data, int x0, int y0, int x1, int y1);

void	init_mlx(t_data *data)
{
	init_win(data);
	init_data(data);
	print_grid(data, data->render);
	//_bresenham_test(data->render, data->render->origin.x, data->render->origin.y, data->render->dir.x, data->render->dir.y);
	// _bresenham_c(data->render, data->render->origin, vect_f_to_d(data->render->dest), 152152152);
	dda(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	mlx_hook(data->render->mlx_win, 2, 0, deal_key, data);
	mlx_loop(data->render->mlx);
}

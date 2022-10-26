/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:27:48 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/26 15:44:29 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right)
{
	int		tmp;

	tmp = top_left.x;
	while (top_left.y < bottom_right.y)
	{
		top_left.x = tmp;
		while (top_left.x < bottom_right.x)
		{
			my_mlx_pixel_put(render, top_left.x, top_left.y, 0x00FF0000);
			top_left.x++;
		}
		top_left.y++;
	}
	mlx_put_image_to_window(render->mlx, render->mlx_win, render->img, 0, 0);
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
	 		{
	 			draw_rect_color(data, top_left, bottom_right);
	 		}
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
	if (mlx == NULL)
	{
		write(2, "Error during initialization instance of mlx\n", 44);
		exit (-1);
	}
	data->render->mlx_win = mlx_new_window(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size), "My window");
	data->render->img = mlx_new_image(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size));
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
	print_grid(data, data->render);
}


void	display_radius(t_data *data, unsigned int px, unsigned int py, unsigned int ox, unsigned int oy)
{
	px = 1200;
	py = 280;
	ox = 840;
	oy = 280;
	int dx;
	int dy;

	if (data->rad->rad > 360)
		data->rad->rad = 0;
	float radi = data->rad->rad * M_PI / 180;
	dx =  (cos(radi) * (px - ox)) - (sin(radi) * (py - oy)) + ox;
	dy =  (sin(radi) * (px - ox)) + (cos(radi) * (py - oy)) + oy;
	dprintf(2, "rad = %d\n", data->rad->rad);
	_bresenham(data->render, data->rad->center_x, data->rad->center_y, dx, dy);
}

int		move_up(t_data *data)
{
	printf("up\n");
	return (0);
}

int		move_left(t_data *data)
{
	printf("left\n");
	return (0);
}

int		move_right(t_data *data)
{
	dda_init_values(data, data->render->dest);
	data->render->dest.y += 5;
	printf("right\n");
	return (0);
}

int		move_down(t_data *data)
{
	printf("down\n");
	return (0);
}

int	deal_key(int key, t_data *data)
{
	// print_grid(data, data->render);
	// mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
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

void	init_rad(t_data *data)
{
	data->rad->center_x = data->maps->longest_line * data->render->cell_size / 2;
	data->rad->center_y = data->maps->height * data->render->cell_size / 2;
}

void	init_mlx(t_data *data)
{
	init_win(data);
	init_rad(data);
	data->rad->degree = 0;
	data->rad->rad = 0;
	data->render->dest.x = (get_x_player(data) + 20) * data->render->cell_size;
	data->render->dest.y = get_x_player(data) * data->render->cell_size;
	// data->render->origin.x = get_x_player(data) * data->render->cell_size;
	// data->render->origin.y = get_y_player(data) * data->render->cell_size;	
	// data->render->map.x = data->render->origin.x;
	// data->render->map.y = data->render->origin.y;
	mlx_hook(data->render->mlx_win, 2, 0, deal_key, data);
	mlx_loop(data->render->mlx);
}
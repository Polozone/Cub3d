/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:47:45 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/16 16:26:24 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	clear_img(t_data *data)
{
	int		i;
	int		total = 1200 * 900;
	int		size = data->render->bits_per_pixel / 8;

	i = 0;
	while (i < total)
	{
		char *dst = data->render->addr + (i * size);
		*(unsigned int*)dst = 0x000000;
		i++;
	}
	return ;
}

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
	 		top_left.x = x * (dt->render->cell_size / 5);
	 		top_left.y = y * (dt->render->cell_size / 5);
	 		bottom_right.x = top_left.x + (dt->render->cell_size / 5);
	 		bottom_right.y = top_left.y + (dt->render->cell_size / 5);
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
	data->render->img = mlx_new_image(data->render->mlx, 1200, 900);
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
}

int	exit_program_from_escape(t_data *data)
{
	mlx_destroy_window(data->render->mlx, data->render->mlx_win);
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 1;
	return (0);
}

int	key_release(int	key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 0;
	return (0);
}

void	player_input(t_data *data)
{
	if (data->keytab[KEY_ESC])
		exit_program_from_escape(data);
	if (data->keytab[KEY_W])
		move_up(data);
	if (data->keytab[KEY_Q] || data->keytab[KEY_LEFT])
		rotate_left(data);
	if (data->keytab[KEY_S])
		move_down(data);
	if (data->keytab[KEY_E] || data->keytab[KEY_RIGHT])
		rotate_right(data);
	if (data->keytab[KEY_D])
		move_right(data);
	if (data->keytab[KEY_A])
		move_left(data);
}

int	update(t_data *data)
{
	player_input(data);

	clear_img(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	print_minimap(data);
	dda(data);
	return (0);
}

int		init_imgs(t_data *data)
{	
	data->east.img = mlx_xpm_file_to_image(data->render->mlx, "path_to_the_east_texture.xpm", &data->east.width, &data->east.height);
	data->east.addr = mlx_get_data_addr(data->east.img, &data->east.bits_per_pixel, &data->east.size_line, &data->east.endian);
	
	data->west.img = mlx_xpm_file_to_image(data->render->mlx, "path_to_the_west_texture.xpm", &data->west.width, &data->west.height);
	data->west.addr = mlx_get_data_addr(data->west.img, &data->west.bits_per_pixel, &data->west.size_line, &data->west.endian);
	
	data->north.img = mlx_xpm_file_to_image(data->render->mlx, "path_to_the_north_texture.xpm", &data->north.width, &data->north.height);
	data->north.addr = mlx_get_data_addr(data->north.img, &data->north.bits_per_pixel, &data->north.size_line, &data->east.endian);
	
	data->south.img = mlx_xpm_file_to_image(data->render->mlx, "path_to_the_south_texture.xpm", &data->south.width, &data->south.height);
	data->south.addr = mlx_get_data_addr(data->south.img, &data->south.bits_per_pixel, &data->south.size_line, &data->south.endian);

	return (0);
}

void	init_mlx(t_data *data)
{
	init_win(data);
	init_data(data);
	init_imgs(data);
	// printf("%f et %f\n",  data->render->origin.x, data->render->origin.y);
	
	// dda(data);
	// mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
}

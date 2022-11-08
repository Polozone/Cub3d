/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:27:48 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/08 13:07:40 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/cub3d.h"

// void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right, int color)
// {
// 	int		tmp;

// 	tmp = top_left.x;
// 	while (top_left.y < bottom_right.y)
// 	{
// 		top_left.x = tmp;
// 		while (top_left.x < bottom_right.x)
// 		{
// 			my_mlx_pixel_put(render, top_left.x, top_left.y, color);
// 			top_left.x++;
// 		}
// 		top_left.y++;
// 	}
// }

// void	print_grid(t_data *dt, t_render *data)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (dt->maps->map[y])
// 	{
// 		x = 0;
// 		while (dt->maps->map[y][x])
// 		{
// 			t_vector2_d top_left;
// 	 		t_vector2_d bottom_right;
// 	 		top_left.x = x * data->cell_size;
// 	 		top_left.y = y * data->cell_size;
// 	 		bottom_right.x = top_left.x + data->cell_size;
// 	 		bottom_right.y = top_left.y + data->cell_size;
// 			if (dt->maps->map[y][x] == '1') // If the cell is a wall
// 	 			draw_rect_color(data, top_left, bottom_right, 16711680);
// 			else if (ft_strchr("NSWE0", dt->maps->map[y][x]))
// 				draw_rect_color(data, top_left, bottom_right, 0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	// mlx_put_image_to_window(dt->render->mlx, dt->render->mlx_win, dt->render->img, 0, 0);
// }

// void	init_win(t_data *data)
// {
// 	void	*mlx;
// 	void	*mlx_window;

// 	data->render->cell_size = 40;
// 	data->render->mlx = mlx_init();
// 	if (mlx == NULL)
// 	{
// 		write(2, "Error during initialization instance of mlx\n", 44);
// 		exit (-1);
// 	}
// 	data->render->mlx_win = mlx_new_window(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size), "My window");
// 	data->render->img = mlx_new_image(data->render->mlx, (data->maps->longest_line * data->render->cell_size), (data->maps->height * data->render->cell_size));
// 	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
// 	print_grid(data, data->render);
// }

// void	display_radius(t_data *data, unsigned int px, unsigned int py, unsigned int ox, unsigned int oy)
// {
// 	px = data->render->origin.x + 40;
// 	py = data->render->origin.x + 40;
// 	ox = data->render->origin.x;
// 	oy = data->render->origin.y;
// 	int dx;
// 	int dy;

// 	if (data->rad->rad > 360)
// 		data->rad->rad = 0;
// 	float radi = data->rad->rad * M_PI / 180;
// 	dx =  (cos(radi) * (px - ox)) - (sin(radi) * (py - oy)) + ox;
// 	dy =  (sin(radi) * (px - ox)) + (cos(radi) * (py - oy)) + oy;
// 	dprintf(2, "rad = %d\n %d\n", data->rad->center_x, data->rad->center_y);
// 	_bresenham(data->render, data->rad->center_x, data->rad->center_y, dx, dy);
// }

// int		move_up(t_data *data)
// {
// 	// display_radius(data, 400, 400, data->render->origin.x, data->render->origin.y);
// 	printf("up\n");
// 	return (0);
// }

// void	print_fov(t_data *data)
// {
// 	double angle = get_angle(data->render->origin, vector_f_to_d(data->render->dest));
// 	t_vector2_d view_dst_pos = create_vect_d_from_origin(data->render->origin, angle, data->render->view_dst);
// 	int opposite_length = tan(degree_to_radian(data->render->fov / 2)) * data->render->view_dst;
// 	t_vector2_f opposite_vect[2] = {
// 		create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle + M_PI / 2, opposite_length),
// 		create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle - M_PI / 2, opposite_length)
// 	};
// 	_bresenham_c(data->render, opposite_vect[0].x, opposite_vect[0].y, opposite_vect[1].x, opposite_vect[1].y, 125125);
// 	double increment = 1.0f / (data->render->rays_nbr - 1.0f);
// 	for (int i = 0; i < data->render->rays_nbr; i++)
// 	{
// 		t_vector2_f vector = vector_f_lerp(opposite_vect[0], opposite_vect[1], increment * i);
// 		_bresenham_c(data->render, data->render->origin.x, data->render->origin.y, vector.x, vector.y, 554455);
// 		//dda_init_values(data, vector);
// 		data->render->rays[i].angle = get_angle_f(vector_d_to_f(data->render->origin), vector); // Set ray angle
// 		data->render->rays[i].hit_point = vector; // Set ray direction
// 	}
// }

// int		move_left(t_data *data)
// {
// 	data->render->dest.y -= 5;
// 	print_fov(data);
// 	dda_init_values(data, data->render->dest);
// 	// _bresenham_c(data->render, data->render->origin.x, data->render->origin.y, data->render->dest.x, data->render->dest.y, 9910101);
// 	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
// 	printf("left\n");
// 	return (0);
// }

// int		move_right(t_data *data)
// {
// 	printf("right\n");
// 	data->render->dest.y += 5;
// 	print_fov(data);
// 	dda_init_values(data, data->render->dest);
// 	// _bresenham_c(data->render, data->render->origin.x, data->render->origin.y, data->render->dest.x, data->render->dest.y, 9910101);
// 	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
// 	return (0);
// }

// int		move_down(t_data *data)
// {
// 	printf("down\n");
// 	return (0);
// }

// // int	deal_key(int key, t_data *data)
// // {
// // 	print_grid(data, data->render);
// // 	if (key == 13)
// // 		move_up(data);
// // 	if (key == 0)
// // 		move_left(data);
// // 	if (key == 1)
// // 		move_down(data);
// // 	if (key == 2)
// // 		move_right(data);
// // 	return (0);
// // }

// void	init_rad(t_data *data)
// {
// 	data->rad->center_x = data->maps->longest_line * data->render->cell_size / 2;
// 	data->rad->center_y = data->maps->height * data->render->cell_size / 2;
// }

// void	init_mlx(t_data *data)
// {
// 	init_win(data);
// 	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
// 	init_rad(data);
// 	data->rad->degree = 0;
// 	data->rad->rad = 0;
// 	data->render->view_dst = 120;
// 	data->render->fov = 90;
// 	data->render->rays_nbr = 50;
// 	data->render->origin.x = get_x_player(data) * data->render->cell_size;
// 	data->render->origin.y = get_y_player(data) * data->render->cell_size;
// 	data->render->dest.x = (get_x_player(data) + 3) * data->render->cell_size;
// 	data->render->dest.y = (get_y_player(data) + 3) * data->render->cell_size;
// 	data->render->rays = malloc(sizeof(t_ray) * data->render->rays_nbr);
// 	// _bresenham_c(data->render, data->render->origin.x, data->render->origin.y, data->render->dest.x, data->render->dest.y, 9910101);
// 	// mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
// 	// double angle = get_angle(data->render->origin, vector_f_to_d(data->render->dest));
// 	// t_vector2_d view_dst_pos = create_vect_d_from_origin(data->render->origin, angle, data->render->view_dst);
// 	// int opposite_length = tan(degree_to_radian(data->render->fov / 2)) * data->render->view_dst;
// 	// t_vector2_f opposite_vect[2] = {
// 	// 	create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle + 3.141592 / 2, opposite_length),
// 	// 	create_vect_f_from_origin(vector_d_to_f(view_dst_pos), angle - 3.141592 / 2, opposite_length)
// 	// };
// 	// my_mlx_pixel_put(data->render, opposite_vect[0].x, opposite_vect[0].y, 125125);
// 	// my_mlx_pixel_put(data->render, opposite_vect[1].x, opposite_vect[1].y, 125125);
// 	// mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
// 	mlx_hook(data->render->mlx_win, 2, 0, deal_key, data);
// 	mlx_loop(data->render->mlx);
// }
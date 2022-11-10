/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:53:50 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/10 11:53:50 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void rotate_left(t_data *data)
{
	data->render->angle += 4;
	t_vector2_f center;

	center.x = cos(data->render->angle * (data->math->H_PI));
	center.y = -sin(data->render->angle * (data->math->H_PI));
	data->render->dir.x = center.x;
	data->render->dir.y = center.y;
	dda(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
}

void rotate_right(t_data *data)
{
	data->render->angle -= 4;
	t_vector2_f center;

	center.x = cos(data->render->angle * (data->math->H_PI));
	center.y = -sin(data->render->angle * (data->math->H_PI));
	data->render->dir.x = center.x;
	data->render->dir.y = center.y;
	dda(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
}

int move_left(t_data *data)
{
	rotate_left(data);
	return (0);
}

int move_right(t_data *data)
{
	rotate_right(data);
	return (0);
}

int move_up(t_data *data)
{
	t_vector2_f center;


	data->render->origin.x += cos(data->render->angle * (data->math->H_PI)) * 15;
	data->render->origin.y += -sin(data->render->angle * (data->math->H_PI)) * 15;

	center.x = data->render->origin.x;
	center.y = data->render->origin.y;
	draw_circle(data, vect_f_to_d(center), 14518459);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	printf("up\n");
	return (0);
}

int move_down(t_data *data)
{
	t_vector2_f center;
	data->render->origin.x -= cos(data->render->angle * (data->math->H_PI)) * 15;
	data->render->origin.y -= -sin(data->render->angle * (data->math->H_PI)) * 15;
	center.x = data->render->origin.x;
	center.y = data->render->origin.y;
	draw_circle(data, vect_f_to_d(center), 14518459);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	printf("down\n");
	return (0);
}

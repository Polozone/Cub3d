/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:41:21 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/26 15:43:11 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_dir_X(double dirX, double planeX, double w, int x)
{
	double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
    double rayDirX = dirX + planeX * cameraX;
	return (rayDirX);
}

double	get_dir_Y(double dirY, double planeY, double w, int x)
{
	double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
    double rayDirY = dirY + planeY * cameraX;
	return (rayDirY);
}

// void	dda_init_values(t_data *data)
// {
//   	double dirX = -1, dirY = 0; //initial direction vector
//   	double planeX = 0, planeY = 0.66;
// 	double w = data->render->cell_size * data->maps->longest_line;

// 	t_vector2_d pos;
// 	t_vector2_d map;

// 	pos.x = get_x_player(data);
// 	pos.y = get_y_player(data);
// 	map.x = pos.x;
// 	map.y = pos.y;

// 	double sideDistX;
//     double sideDistY;
// 	//double deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
//     //double deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
//     double perpWallDist;
// 	printf("return == %f\n", get_dir_Y(dirY, planeY, w, 420));
//  	int stepX;
//     int stepY;

//     int hit = 0; //was there a wall hit?
//     int side; //was a NS or a EW wall hit?
// }

float	ft_abs(float number)
{
	if (number < 0)
		return (number * -1);
	else
		return (number);
}

t_vector2_f		vector_d_to_f(t_vector2_d vector)
{
	t_vector2_f		cast;

	cast.x = (float)vector.x;
	cast.y = (float)vector.y;
	return (cast);
}

t_vector2_d		vector_f_to_d(t_vector2_f vector)
{
	t_vector2_d		cast;

	cast.x = (int)vector.x;
	cast.y = (int)vector.y;
	return (cast);
}

t_vector2_f	dda_init_values(t_data *data, t_vector2_f dest)
{
	t_vector2_d origin;
	origin.x = get_x_player(data) * data->render->cell_size;
	origin.y = get_y_player(data) * data->render->cell_size;

	t_vector2_d map;
	map.x = get_x_player(data) * data->render->cell_size;
	map.y = get_y_player(data) * data->render->cell_size;

	t_vector2_f dir = {dest.x - origin.x, dest.y - origin.y};

	t_vector2_f side_dist; // Origin point offset to the nearest int positon
	t_vector2_f delta_dist; // Length of the hyptenuse

	delta_dist.x = (dir.x == 0) ? 1e30 : ft_abs(1.0f / dir.x); // 1e30 is a large value
	delta_dist.y = (dir.y == 0) ? 1e30 : ft_abs(1.0f / dir.y);

	t_vector2_d step;
	if (dir.x < 0)
	{
		step.x = -1; // Calculating X step (depending on the direction)
		side_dist.x = (origin.x - map.x) * delta_dist.x; // Calculating X gap to the nearest integer coordinate
	}
	else
	{
		step.x = 1;
		side_dist.x = (map.x + 1.0f - origin.x) * delta_dist.x;
	}

	if (dir.y < 0)
	{
		step.y = -1; // Calculating Y step (depending on the direction)
		side_dist.y = (origin.y - map.y) * delta_dist.y; // Calculating Y gap to the nearest integer coordinate
	}
	else
	{
		step.y = 1;
		side_dist.y = (map.y + 1.0f - origin.y) * delta_dist.y;
	}
	while (1)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map.x += step.x;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map.y += step.y;
		}

		// Converting pixel coordinates to tab coordinates
		t_vector2_d cell = {
			map.x / data->render->cell_size,
			map.y / data->render->cell_size
		};
		if (data->maps->map[cell.y][cell.x] == '1') // Is a wall
		{
			_bresenham(data->render, origin.x, origin.y, map.x, map.y);
			mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
			return (vector_d_to_f(map));
		}
	}
}


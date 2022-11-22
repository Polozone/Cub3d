/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 08:38:29 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_camera_x(int width, int x)
{
	double	resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

static void	loop_get_coll(t_data *data, t_col *col, int i)
{
	while (col->hit == 0)
	{
		if (col->sideDistX < col->sideDistY)
		{
			col->sideDistX += col->deltaDistX;
			col->mapX += col->stepX;
			col->side = 0;
		}
		else
		{
			col->sideDistY += col->deltaDistY;
			col->mapY += col->stepY;
			col->side = 1;
		}
		if (data->maps->map[col->mapY / data->render->cell_size]
							[col->mapX / data->render->cell_size] == '1')
		{
			render_wall(data, col->sideDistX, col->sideDistY, col->side, col->deltaDistX, col->deltaDistY, col->mapX, col->mapY, i, col->stepX, col->stepY);
			col->hit = 1;
		}
	}
}

static void	init_loop_get_coll(t_data *data, t_col *col, int i)
{
	if (col->rayDirX < 0)
	{
		col->stepX = -1;
		col->sideDistX = (data->render->origin.x - col->mapX) * col->deltaDistX;
	}
	else
	{
		col->stepX = 1;
		col->sideDistX = (col->mapX + 1.0 - data->render->origin.x) * col->deltaDistX;
	}
	if (col->rayDirY < 0)
	{
		col->stepY = -1;
		col->sideDistY = (data->render->origin.y - col->mapY) * col->deltaDistY;
	}
	else
	{
		col->stepY = 1;
		col->sideDistY = (col->mapY + 1.0 - data->render->origin.y) *
			col->deltaDistY;
	}
	loop_get_coll(data, col, i);
}

int dda(t_data *data)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		data->col->delta = get_camera_x(WIDTH, i);
		data->col->rayDirX = data->render->dir.x
			+ (data->render->plane.x * data->col->delta);
		data->col->rayDirY = data->render->dir.y
			+ (data->render->plane.y * data->col->delta);
		data->col->deltaDistX = (data->col->rayDirX == 0) ? 1e30 : ft_abs(1.0f / data->col->rayDirX);
		data->col->deltaDistY = (data->col->rayDirY == 0) ? 1e30 : ft_abs(1.0f / data->col->rayDirY);
		data->col->hit = 0;
		data->col->mapX = (int)data->render->origin.x;
		data->col->mapY = (int)data->render->origin.y;
		init_loop_get_coll(data, data->col, i);
		i++;
	}
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	return (0);
}

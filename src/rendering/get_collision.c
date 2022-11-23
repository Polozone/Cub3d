/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 13:48:01 by pmulin           ###   ########.fr       */
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
		if (col->sidedistx < col->sidedisty)
		{
			col->sidedistx += col->deltadistx;
			col->mapx += col->stepx;
			col->side = 0;
		}
		else
		{
			col->sidedisty += col->deltadisty;
			col->mapy += col->stepy;
			col->side = 1;
		}
		if (data->maps->map[col->mapy / data->render->cell_size]
			[col->mapx / data->render->cell_size] == '1')
		{
			render_wall(data, col, i);
			col->hit = 1;
		}
	}
}

static void	init_loop_get_coll(t_data *data, t_col *col, int i)
{
	if (col->raydirx < 0)
	{
		col->stepx = -1;
		col->sidedistx = (data->render->origin.x - col->mapx)
			* col->deltadistx;
	}
	else
	{
		col->stepx = 1;
		col->sidedistx = (col->mapx + 1.0 - data->render->origin.x)
			* col->deltadistx;
	}
	if (col->raydiry < 0)
	{
		col->stepy = -1;
		col->sidedisty = (data->render->origin.y - col->mapy)
			* col->deltadisty;
	}
	else
	{
		col->stepy = 1;
		col->sidedisty = (col->mapy + 1.0 - data->render->origin.y)
			* col->deltadisty;
	}
	loop_get_coll(data, col, i);
}

int	dda(t_data *data, int i)
{
	while (++i < WIDTH)
	{
		data->col->delta = get_camera_x(WIDTH, i);
		data->col->raydirx = data->render->dir.x
			+ (data->render->plane.x * data->col->delta);
		data->col->raydiry = data->render->dir.y
			+ (data->render->plane.y * data->col->delta);
		if (data->col->raydirx == 0)
			data->col->deltadistx = 1e30;
		else
			data->col->deltadistx = ft_abs(1.0f / data->col->raydirx);
		if (data->col->raydiry == 0)
			data->col->deltadisty = 1e30;
		else
			data->col->deltadisty = ft_abs(1.0f / data->col->raydiry);
		data->col->hit = 0;
		data->col->mapx = (int)data->render->origin.x;
		data->col->mapy = (int)data->render->origin.y;
		init_loop_get_coll(data, data->col, i);
	}
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win,
		data->render->img, 0, 0);
	return (0);
}

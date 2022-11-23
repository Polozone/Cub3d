/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:57 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 13:47:48 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	orientation_checker_we_ea(t_data *data, int x, t_col *col)
{
	if (col->stepx == 1)
	{
		render_line(data, x, &data->west, col);
		return ;
	}
	else if (col->stepx == -1)
	{
		render_line(data, x, &data->east, col);
		return ;
	}
}

void	orientation_checker_no_so(t_data *data, int x, t_col *col)
{
	if (col->stepy == 1)
	{
		render_line(data, x, &data->north, col);
		return ;
	}
	else if (col->stepy == -1)
	{
		render_line(data, x, &data->south, col);
		return ;
	}
}

void	render_wall(t_data *data, t_col *col, int x)
{
	if (col->side == 0)
		col->perpwalldist = (col->sidedistx - col->deltadistx);
	else
		col->perpwalldist = (col->sidedisty - col->deltadisty);
	if (col->perpwalldist == 0)
		col->perpwalldist = 1;
	col->lineheight = (col->h / col->perpwalldist) * 40;
	col->drawstart = (-col->lineheight >> 1) + (col->h >> 1);
	col->drawend = (col->lineheight >> 1) + (col->h >> 1);
	if (col->side == 0)
		orientation_checker_we_ea(data, x, col);
	else
		orientation_checker_no_so(data, x, col);
	return ;
}

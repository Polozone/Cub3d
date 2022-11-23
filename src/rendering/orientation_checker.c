/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:57 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 09:27:52 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	orientation_checker_we_ea(t_data *data, int x, t_col *col)
{
	if (col->stepX == 1)
	{
		render_line(data, x, &data->west, col);
		return ;
	}
	else if (col->stepX == -1)
	{
		render_line(data, x, &data->east, col);
		return ;
	}
}

void	orientation_checker_no_so(t_data *data, int x, t_col *col)
{
	if (col->stepY == 1)
	{
		render_line(data, x, &data->north, col);
		return ;
	}
	else if (col->stepY == -1)
	{
		render_line(data, x, &data->south, col);
		return ;
	}
}

void	render_wall(t_data *data, t_col *col, int x)
{
	if (col->side == 0)
		col->perpWallDist = (col->sideDistX - col->deltaDistX);
	else
		col->perpWallDist = (col->sideDistY - col->deltaDistY);
	if (col->perpWallDist == 0)
		col->perpWallDist = 1;
	col->lineHeight = (col->h / col->perpWallDist) * 40;
	col->drawStart = (-col->lineHeight >> 1) + (col->h >> 1);
	col->drawEnd = (col->lineHeight >> 1) + (col->h >> 1);
	if (col->side == 0)
		orientation_checker_we_ea(data, x, col);
	else
		orientation_checker_no_so(data, x, col);
	return ;
}

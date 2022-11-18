/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:53:50 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/18 11:15:31 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void rotate_left(t_data *data)
{
	double PRE_COMPUTE_COS_ROT_SPD;
	double PRE_COMPUTE_SIN_ROT_SPD;

	PRE_COMPUTE_COS_ROT_SPD = cos(-ROT_SPD);
	PRE_COMPUTE_SIN_ROT_SPD = sin(-ROT_SPD);
	double oldDirX = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * PRE_COMPUTE_COS_ROT_SPD - data->render->dir.y * PRE_COMPUTE_SIN_ROT_SPD;
	data->render->dir.y = oldDirX * PRE_COMPUTE_SIN_ROT_SPD + data->render->dir.y * PRE_COMPUTE_COS_ROT_SPD;
	double oldPlaneX = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * PRE_COMPUTE_COS_ROT_SPD - data->render->plane.y * PRE_COMPUTE_SIN_ROT_SPD;
	data->render->plane.y = oldPlaneX * PRE_COMPUTE_SIN_ROT_SPD + data->render->plane.y * PRE_COMPUTE_COS_ROT_SPD;
	return ;
}

void rotate_right(t_data *data)
{
	double PRE_COMPUTE_COS_ROT_SPD;
	double PRE_COMPUTE_SIN_ROT_SPD;

	PRE_COMPUTE_COS_ROT_SPD = cos(ROT_SPD);
	PRE_COMPUTE_SIN_ROT_SPD = sin(ROT_SPD);
	double oldDirX = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * PRE_COMPUTE_COS_ROT_SPD - data->render->dir.y * PRE_COMPUTE_SIN_ROT_SPD;
	data->render->dir.y = oldDirX * PRE_COMPUTE_SIN_ROT_SPD + data->render->dir.y * PRE_COMPUTE_COS_ROT_SPD;
	double oldPlaneX = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * PRE_COMPUTE_COS_ROT_SPD - data->render->plane.y * PRE_COMPUTE_SIN_ROT_SPD;
	data->render->plane.y = oldPlaneX * PRE_COMPUTE_SIN_ROT_SPD + data->render->plane.y * PRE_COMPUTE_COS_ROT_SPD;
	return ;
}

int		move_left(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->plane.y * (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->plane.x * (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	data->render->origin.x -= data->render->plane.x * MOV_SPD;
	data->render->origin.y -= data->render->plane.y * MOV_SPD;
	return (0);
}

int move_right(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->plane.y * (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->plane.x * (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	data->render->origin.x += data->render->plane.x * MOV_SPD;
	data->render->origin.y += data->render->plane.y * MOV_SPD;
	return (0);
}

int move_up(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->dir.y * (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->dir.x * (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	data->render->origin.x += data->render->dir.x * MOV_SPD;
	data->render->origin.y += data->render->dir.y * MOV_SPD;
	return (0);
}

int move_down(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->dir.y * (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->dir.x * (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	data->render->origin.x -= data->render->dir.x * MOV_SPD;
	data->render->origin.y -= data->render->dir.y * MOV_SPD;
	return (0);
}

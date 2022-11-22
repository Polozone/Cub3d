/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:53:50 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 14:37:42 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move_left(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->plane.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->plane.x
			* (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->plane.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->plane.x
			* (MOV_SPD << 2)) / 40)] == ' ')
		return (1);
	data->render->origin.x -= data->render->plane.x * MOV_SPD;
	data->render->origin.y -= data->render->plane.y * MOV_SPD;
	return (0);
}

int	move_right(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->plane.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->plane.x
			* (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->plane.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->plane.x
			* (MOV_SPD << 2)) / 40)] == ' ')
		return (1);
	data->render->origin.x += data->render->plane.x * MOV_SPD;
	data->render->origin.y += data->render->plane.y * MOV_SPD;
	return (0);
}

int	move_up(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->dir.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->dir.x
			* (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	if (data->maps->map
		[(int)((data->render->origin.y + data->render->dir.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x + data->render->dir.x
			* (MOV_SPD << 2)) / 40)] == ' ')
		return (1);
	data->render->origin.x += data->render->dir.x * MOV_SPD;
	data->render->origin.y += data->render->dir.y * MOV_SPD;
	return (0);
}

int	move_down(t_data *data)
{
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->dir.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->dir.x
			* (MOV_SPD << 2)) / 40)] == '1')
		return (1);
	if (data->maps->map
		[(int)((data->render->origin.y - data->render->dir.y
				* (MOV_SPD << 2)) / 40)]
		[(int)((data->render->origin.x - data->render->dir.x
			* (MOV_SPD << 2)) / 40)] == ' ')
		return (1);
	data->render->origin.x -= data->render->dir.x * MOV_SPD;
	data->render->origin.y -= data->render->dir.y * MOV_SPD;
	return (0);
}

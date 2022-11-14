/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:53:50 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/14 13:19:35 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void rotate_left(t_data *data)
{
	double oldDirX = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * cos(-ROT_SPD) - data->render->dir.y * sin(-ROT_SPD);
	data->render->dir.y = oldDirX * sin(-ROT_SPD) + data->render->dir.y * cos(-ROT_SPD);
	double oldPlaneX = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * cos(-ROT_SPD) - data->render->plane.y * sin(-ROT_SPD);
	data->render->plane.y = oldPlaneX * sin(-ROT_SPD) + data->render->plane.y * cos(-ROT_SPD);
	return ;
}

void rotate_right(t_data *data)
{
	double oldDirX = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * cos(ROT_SPD) - data->render->dir.y * sin(ROT_SPD);
	data->render->dir.y = oldDirX * sin(ROT_SPD) + data->render->dir.y * cos(ROT_SPD);
	double oldPlaneX = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * cos(ROT_SPD) - data->render->plane.y * sin(ROT_SPD);
	data->render->plane.y = oldPlaneX * sin(ROT_SPD) + data->render->plane.y * cos(ROT_SPD);
	return ;
}


int		move_left(t_data *data)
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
	data->render->origin.x += data->render->dir.x * MOV_SPD;
	data->render->origin.y += data->render->dir.y * MOV_SPD;
	return (0);
}

int move_down(t_data *data)
{
	data->render->origin.x -= data->render->dir.x * MOV_SPD;
	data->render->origin.y -= data->render->dir.y * MOV_SPD;
	return (0);
}

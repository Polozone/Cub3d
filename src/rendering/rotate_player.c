/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:53 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 15:19:27 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double	pre_compute_cos_rot_speed;
	double	pre_compute_sin_rot_speed;
	double	olddirx;
	double	oldplanex;

	pre_compute_cos_rot_speed = cos(-ROT_SPD);
	pre_compute_sin_rot_speed = sin(-ROT_SPD);
	olddirx = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * pre_compute_cos_rot_speed
		- data->render->dir.y * pre_compute_sin_rot_speed;
	data->render->dir.y = olddirx * pre_compute_sin_rot_speed
		+ data->render->dir.y * pre_compute_cos_rot_speed;
	oldplanex = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * pre_compute_cos_rot_speed
		- data->render->plane.y * pre_compute_sin_rot_speed;
	data->render->plane.y = oldplanex * pre_compute_sin_rot_speed
		+ data->render->plane.y * pre_compute_cos_rot_speed;
	return ;
}

void	rotate_right(t_data *data)
{
	double	pre_compute_cos_rot_speed;
	double	pre_compute_sin_rot_speed;
	double	olddirx;
	double	oldplanex;

	pre_compute_cos_rot_speed = cos(ROT_SPD);
	pre_compute_sin_rot_speed = sin(ROT_SPD);
	olddirx = data->render->dir.x;
	data->render->dir.x = data->render->dir.x * pre_compute_cos_rot_speed
		- data->render->dir.y * pre_compute_sin_rot_speed;
	data->render->dir.y = olddirx * pre_compute_sin_rot_speed
		+ data->render->dir.y * pre_compute_cos_rot_speed;
	oldplanex = data->render->plane.x;
	data->render->plane.x = data->render->plane.x * pre_compute_cos_rot_speed
		- data->render->plane.y * pre_compute_sin_rot_speed;
	data->render->plane.y = oldplanex * pre_compute_sin_rot_speed
		+ data->render->plane.y * pre_compute_cos_rot_speed;
	return ;
}

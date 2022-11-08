/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_rendering.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:27:42 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/08 15:09:21 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->render->cell_size = 40;
	data->render->origin.x = 22;
	data->render->origin.y = 12;
	data->render->dir.x = data->render->origin.x + (2);
	data->render->dir.y = data->render->origin.y + (0);
	data->render->plane.x = data->render->dir.x + (0);
	data->render->plane.y = data->render->dir.y + (0.66);
	// data->render->dir.x = (23);
	// data->render->dir.y = (13);
	// data->render->plane.x = (23);
	// data->render->plane.y = (13.66);
	// printf("%f\n", data->render->origin.x);
	// printf("%f\n", data->render->origin.y);
	// printf("%f\n", data->render->dir.x);
	// printf("%f\n", data->render->dir.y);
	// printf("%f\n", data->render->plane.x);
	// printf("%f\n", data->render->plane.y);
	return;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_rendering.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:27:42 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/10 13:33:15 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->render->cell_size = 40;
	data->render->origin.x = get_x_player(data) * 40;
	data->render->origin.y = get_y_player(data) * 40;
	data->render->dir.x = (1);
	data->render->dir.y = (0);
	data->render->plane.x = (0);
	data->render->plane.y = (0.66);
	data->render->angle = 0;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/08 15:44:35 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_camera_X(int width, int x)
{
	double resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

int dda(t_data *data, t_vector2_f origin, t_vector2_f dir)
{
	double rayDirX = data->render->dir.x + (data->render->plane.x * 0); /* this 0 is normally get_camera_X*/
    double rayDirY = data->render->dir.y + (data->render->plane.y * 0); /* this 0 is normally get_camera_X*/

	// t_vector2_f dir = {data->render->dest.x - data->render->origin.x, data->render->dest.y - data->render->origin.y};

	double diffX = data->render->dir.x - data->render->origin.x;
	double diffY = data->render->dir.y - data->render->origin.y;

	double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1.0f / diffX);
    double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1.0f / diffY);

	printf("%f\n", deltaDistX);
	printf("%f\n", deltaDistY);
	return (0);
}

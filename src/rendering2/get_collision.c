/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/08 09:38:23 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_camera_X(int width, int x)
{
	double resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

int dda(t_data *data, t_vector2_d origin, t_vector2_f dir)
{
	// double rayDirX = dirX + planeX * 1 /* this 1 is normally get_camera_X*/;
    // double rayDirY = dirY + planeY * 1 /* this 1 is normally get_camera_X*/;

	double rayDirX = dir.x + data->render->plane.x * 0 /* this 0 is normally get_camera_X*/;
    double rayDirY = dir.y + data->render->plane.y * 0 /* this 0 is normally get_camera_X*/;

	double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
    double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

	// double deltaDistX = fabs(1 / rayDirX);
	// double deltaDistY = fabs(1 / rayDirY);
	printf("%f\n", deltaDistX);
	printf("%f\n", deltaDistY);

	return (0);
}
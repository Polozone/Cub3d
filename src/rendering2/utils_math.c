/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:07:45 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/09 11:31:48 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	ft_abs(float number)
{
	if (number < 0)
		return (number * -1);
	else
		return (number);
}

void draw_circle(t_data *data, t_vector2_d center, int color)
{
	t_vector2_d pos;
	int radius = 2;

	for (int y = center.y - radius; y < center.y + radius; y++)
	{
		for (int x = center.x - radius; x < center.x + radius; x++)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			if ((float)(pos.x + pos.y) - (radius * radius) < 0.1f)
				my_mlx_pixel_put(data->render, x, y, color);
		}
	}
}
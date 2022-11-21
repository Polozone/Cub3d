/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breshenam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:02:05 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 09:46:43 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_render *render, int x, int y, int color)
{
	char *dst;

	dst = render->addr + (y * render->line_length + x * (render->bits_per_pixel >> 3));
	*(unsigned int*)dst = color;
}

int _bresenham(t_render *data, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
		my_mlx_pixel_put(data, x0, y0, 125125);
        if ((x0 == x1) && (y0 == y1))
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
    return (0);
}

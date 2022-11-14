/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breshenam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:02:05 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/14 13:18:40 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_render *render, int x, int y, int color)
{
	char *dst;

	dst = render->addr + (y * render->line_length + x * (render->bits_per_pixel / 8));
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

int _bresenham_test(t_render *data, int x0, int y0, int x1, int y1)
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

int _bresenham_c(t_render *render, t_vector2_d start, t_vector2_d end, int color)
{
	int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
		my_mlx_pixel_put(render, start.x, start.y, color);
        if ((start.x == end.x) && (start.y == end.y))
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            end.y += sy;
        }
    }
    return (0);
}
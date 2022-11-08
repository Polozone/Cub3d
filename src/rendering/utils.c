/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:11:12 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/08 13:07:35 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/cub3d.h"

// void my_mlx_pixel_put(t_render *render, int x, int y, int color)
// {
// 	char *dst;

// 	dst = render->addr + (y * render->ƒh + x * (render->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// double	get_angle_f(t_vector2_f start, t_vector2_f end)
// {
// 	double	dx;
// 	double	dy;

// 	dx = (double)(end.x - start.x);
// 	dy = (double)(end.y - start.y);
// 	if (dx >= 0 && dy < 0)
// 		return (atan(-dy / dx));
// 	else if (dx < 0 && dy < 0)
// 		return (atan(dx / dy) + 3.14f / 2.0f);
// 	else if (dx < 0 && dy > 0)
// 		return (atan(-dy / dx) + 3.14f);
// 	else
// 		return (atan(dx / dy) + 3.14 + 1.57f);
// }

// t_vector2_f		vector_f_lerp(t_vector2_f start, t_vector2_f end, float timestamp)
// {
// 	t_vector2_f		vector;
// 	float			dx;
// 	float			dy;

// 	dx = end.x - start.x;
// 	dy = end.y - start.y;
// 	vector.x = start.x + dx * timestamp;
// 	vector.y = start.y + dy * timestamp;
// 	return (vector);
// }

// int _bresenham(t_render *data, int x0, int y0, int x1, int y1)
// {
// 	int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         // mlx_pixel_put(data->mlx, data->mlx_win, x0, y0, 125125);
// 		my_mlx_pixel_put(data, x0, y0, 125125);
//         if ((x0 == x1) && (y0 == y1))
//             break;
//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
//     return (0);
// }

// int _bresenham_c(t_render *data, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         // mlx_pixel_put(data->mlx, data->mlx_win, x0, y0, 125125);
// 		my_mlx_pixel_put(data, x0, y0, color);
//         if ((x0 == x1) && (y0 == y1))
//             break;
//         int e2 = 2 * err;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
//     return (0);
// }
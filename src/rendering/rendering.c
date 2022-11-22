/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 14:37:36 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_ceil(t_data *data, int drawStart, int x)
{
	int		i;

	i = 0;
	while (i < drawStart)
	{
		my_mlx_pixel_put(data->render, x, i, data->ceil_color);
		i++;
	}
}

int get_color_from_xpm(t_img *img, int x, int y)
{
	if (y == 64)
		y = 63;
	char *color = (img->addr + (x * img->precompute_bits_p_px) + (y * img->size_line));
	return (*(unsigned int *)color);
}

void	render_walls(t_data *data, t_img *img, int drawStart, int drawEnd, int x, int mapX, int mapY, int side)
{
	int color2;

	int sizeWall = drawEnd - drawStart;
	float ratio = 64 / (float)sizeWall;
	float hitX = (float)mapX / data->render->cell_size;
	float ratioX = (hitX - (int)hitX);
	float hitY = (float)mapY / data->render->cell_size;
	float ratioY = (hitY - (int)hitY);
	int	index_X = ratioX * 64;
	int	index_Y = ratioY * 64;
	while (drawStart < drawEnd)
	{
		if ((drawStart > 0 && drawStart < 900) || (drawEnd > 0 && drawEnd < 900))
		{
			if (side == 2)
				color2 = get_color_from_xpm(img, index_X, (drawEnd - drawStart) * ratio);
			if (side == 1)
				color2 = get_color_from_xpm(img, index_Y, (drawEnd - drawStart) * ratio);
			my_mlx_pixel_put(data->render, x, drawStart, color2);
		}
		drawStart++;
	}
}

void	render_floor(t_data *data, int drawEnd, int x, int color, int h)
{
	while (drawEnd < 900)
	{
		my_mlx_pixel_put(data->render, x, drawEnd, color);
		drawEnd++;
	}
}

void	render_line(t_data *data, int drawStart, int drawEnd, int x, t_img *img, int mapX, int mapY, int side, int h)
{
	render_ceil(data, drawStart, x);
	render_walls(data, img, drawStart, drawEnd, x, mapX, mapY, side);
	render_floor(data, drawEnd, x, data->floor_color, h);
	return ;
}

void	render_wall(t_data *data, double sideDistX, double sideDistY, int side, double deltaDistX, double deltaDistY, int mapX, int mapY, int x, int stepX, int stepY)
{
	double	perpWallDist;
	int		lineHeight;
	int		h = 900;
	int		drawStart;
	int		drawEnd;

	if (side == 0)
		perpWallDist = (sideDistX - deltaDistX);
	else
		perpWallDist = (sideDistY - deltaDistY);
	if (perpWallDist == 0)
		perpWallDist = 1;
	lineHeight = (h / perpWallDist) * 40;
	drawStart = (-lineHeight >> 1) + (h >> 1);
    drawEnd = (lineHeight >> 1) + (h >> 1);
	if (side == 0)
	{
		if (stepX == 1)
		{
			render_line(data, drawStart, drawEnd, x, &data->west, mapX, mapY, 1, h);
			return ;
		}
		else if (stepX == -1)
		{
			render_line(data, drawStart, drawEnd, x, &data->east, mapX, mapY, 1, h);
			return ;
		}
	}
	else
	{
		if (stepY == 1)
		{
			render_line(data, drawStart, drawEnd, x, &data->north, mapX, mapY, 2, h);
			return ;
		}
		else if (stepY == -1)
		{
			render_line(data, drawStart, drawEnd, x, &data->south, mapX, mapY, 2, h);
			return ;
		}
	}
	return ;
}
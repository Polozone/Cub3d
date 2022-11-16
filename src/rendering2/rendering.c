/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/16 16:34:53 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_ceil(t_data *data, int drawStart, int x)
{
	int		i;

	i = 0;
	while (i < drawStart)
	{
		if (x <= data->maps->longest_line * (data->render->cell_size / 5)
			&& i <= (data->maps->height * data->render->cell_size / 5))
			;
		else
			my_mlx_pixel_put(data->render, x, i, data->ceil_color);
		i++;
	}
}

int get_color_from_xpm(t_img *img, int x, int y)
{
	if (y == 64)
		y = 63;
	char *color = (img->addr + (x * img->bits_per_pixel / 8) + (y * img->size_line));
	return (*(unsigned int *)color);
}

void	render_walls(t_data *data, t_img *img, int drawStart, int drawEnd, int x, int color, int mapX, int mapY, int side)
{
	int color2;

	int sizeWall = drawEnd - drawStart;
	float ratio = 64 / (float)sizeWall;
	float hitX = (float)mapX / 40;
	float ratioX = (hitX - (int)hitX);
	float hitY = (float)mapY / 40;
	float ratioY = (hitY - (int)hitY);
	while (drawStart < drawEnd)
	{
		if (drawStart <= (data->maps->height * data->render->cell_size / 5)
			&& x <= data->maps->longest_line * (data->render->cell_size / 5))
			drawStart = (data->maps->height * data->render->cell_size / 5);
		if (side == 2)
			color2 = get_color_from_xpm(img, ratioX * 64, (drawEnd - drawStart) * ratio);
		if (side == 1)
			color2 = get_color_from_xpm(img, ratioY * 64, (drawEnd - drawStart) * ratio);
		my_mlx_pixel_put(data->render, x, drawStart, color2);
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

void	render_line(t_data *data, int color, int drawStart, int drawEnd, int x, t_img *img, int mapX, int mapY, int side, int h)
{
	render_ceil(data, drawStart, x);
	render_walls(data, img, drawStart, drawEnd, x, color, mapX, mapY, side);
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
	// printf("%f\n", perpWallDist);
	drawStart = (-lineHeight >> 1) + (h >> 1);
    if(drawStart < 0)
		drawStart = 0;
    drawEnd = (lineHeight >> 1) + (h >> 1);
    if(drawEnd >= h)
		drawEnd = h - 1;
	if (side == 0) // E/W
	{
		if (stepX == 1)
		{
			render_line(data, 0xFFFF00, drawStart, drawEnd, x, &data->west, mapX, mapY, 1, h);
			return ;
		}
		else if (stepX == -1)
		{
			render_line(data, 0xFFFFFF, drawStart, drawEnd, x, &data->east, mapX, mapY, 1, h);
			return ;
		}
	}
	else // N/S
	{
		if (stepY == 1)
		{
			render_line(data, 0x000000, drawStart, drawEnd, x, &data->north, mapX, mapY, 2, h);
			return ;
		}
		else if (stepY == -1)
		{
			render_line(data, 0x009911, drawStart, drawEnd, x, &data->south, mapX, mapY, 2, h);
			return ;
		}
	}
	return ;
}
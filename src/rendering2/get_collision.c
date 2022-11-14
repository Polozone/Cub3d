/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/14 09:38:39 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_camera_X(int width, int x)
{
	double resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

void	render_line(t_data *data, int color, int drawStart, int drawEnd, int x)
{
	int i = 0;

	while (i < drawStart)
	{
		my_mlx_pixel_put(data->render, x, i, 458963);
		i++;
	}
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(data->render, x, drawStart, color);
		drawStart++;
	}
	while (drawEnd < 900)
	{
		my_mlx_pixel_put(data->render, x, drawEnd, 147852);
		drawEnd++;
	}
	return ;
}

void	render_wall(t_data *data, double sideDistX, double sideDistY, int side, double deltaDistX, double deltaDistY, int mapX, int mapY, int x)
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
	lineHeight = (h / perpWallDist) * 40;
	drawStart = -lineHeight * 0.5 + h * 0.5;
    if(drawStart < 0)
		drawStart = 0;
    drawEnd = lineHeight * 0.5 + h * 0.5;
    if(drawEnd >= h)
		drawEnd = h - 1;
	if (side == 0)
		render_line(data, 125125, drawStart, drawEnd, x);
	else
		render_line(data, 654564654, drawStart, drawEnd, x);
	return ;
}

int dda(t_data *data)
{
	for (int x = 0; x < 1200 ; x += 1)
	{
		double	delta = get_camera_X(1200, x);
		double rayDirX = data->render->dir.x + (data->render->plane.x * delta); /* this 0 is normally get_camera_X*/
		double rayDirY = data->render->dir.y + (data->render->plane.y * delta); /* this 0 is normally get_camera_X*/

		double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1.0f / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1.0f / rayDirY);

		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		int mapX = (int)data->render->origin.x;
		int mapY = (int)data->render->origin.y;
		double sideDistX;
		double sideDistY;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->render->origin.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->render->origin.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->render->origin.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->render->origin.y) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->maps->map[mapY / 40][mapX / 40] == '1')
			{
				render_wall(data, sideDistX, sideDistY, side, deltaDistX, deltaDistY, mapX, mapY, x);
				hit = 1;
			}
		}
	}
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	return (0);
}

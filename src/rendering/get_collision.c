/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 10:13:21 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_camera_X(int width, int x)
{
	double resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

int dda(t_data *data)
{
	for (int x = 0; x < WIDTH ; x++)
	{
		double delta = get_camera_X(WIDTH, x);
		double rayDirX = data->render->dir.x + (data->render->plane.x * delta);
		double rayDirY = data->render->dir.y + (data->render->plane.y * delta);

		double deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1.0f / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1.0f / rayDirY);
                        
		int stepX;       
		int stepY;     
					  
		int hit = 0;
		int side;

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
			if (data->maps->map[mapY / data->render->cell_size][mapX / data->render->cell_size] == '1')
			{
				render_wall(data, sideDistX, sideDistY, side, deltaDistX, deltaDistY, mapX, mapY, x, stepX, stepY);
				hit = 1;
			}
		}
	}
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	return (0);
}
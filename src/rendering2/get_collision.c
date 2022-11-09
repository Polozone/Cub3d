/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/09 15:22:55 by pmulin           ###   ########.fr       */
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
	double rayDirX = data->render->dir.x + (data->render->plane.x * 0); /* this 0 is normally get_camera_X*/
    double rayDirY = data->render->dir.y + (data->render->plane.y * 0); /* this 0 is normally get_camera_X*/

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
        //jump to next map square, either in x-direction, or in y-direction
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
			_bresenham(data->render, data->render->origin.x, data->render->origin.y, mapX, mapY);
			mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
			hit = 1;
		}
    } 
	return (0);
}

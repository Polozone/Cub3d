/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:34:41 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/10 10:49:25 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_camera_X(int width, int x)
{
	double resultat;

	resultat = (2 * x / (double)width) - 1;
	return (resultat);
}

void	render_line(t_data *data, int color, int drawStart, int drawEnd)
{
	return ;
}

void	render_wall(t_data *data, double sideDistX, double sideDistY, int side, double deltaDistX, double deltaDistY, int mapX, int mapY)
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
	{
		render_line(data, 125125, drawStart, drawEnd);
		printf("EW");
	}
	else
	{
		render_line(data, 654564654, drawStart, drawEnd);
		printf("NS");
	}
	printf("(1080 / %f)lH == %d -> from %d to %d\n", perpWallDist, lineHeight, drawStart, drawEnd); 
	return ;
}

int dda(t_data *data)
{
	for (int x = 0; x < 1200 ; x = x + 2)
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
			render_wall(data, sideDistX, sideDistY, side, deltaDistX, deltaDistY, mapX, mapY);
			// printf("dist = %f\n", perpWallDist);
			_bresenham(data->render, data->render->origin.x, data->render->origin.y, mapX, mapY);
			hit = 1;
		}
    } 
	}
	return (0);
}

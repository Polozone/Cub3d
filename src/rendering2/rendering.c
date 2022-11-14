/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/14 14:00:16 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_floor(t_data *data, int drawStart, int x, char *name)
{
	int		i;

	i = 0;
	while (i < drawStart)
	{
		if (x <= data->maps->longest_line * (data->render->cell_size / 5)
			&& i <= (data->maps->height * data->render->cell_size / 5))
			;
		else
			my_mlx_pixel_put(data->render, x, i, 0xb3bcf5);
		i++;
	}
}

void	render_walls(t_data *data, int drawStart, int drawEnd, int x, int color, char *name)
{
	// void	*img;
	// int width;
	// int height;

	// img = mlx_xpm_file_to_image(data->render->mlx, name, &width, &height);
	// mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, img, x, drawEnd);
	while (drawStart < drawEnd)
	{
		if (drawStart <= (data->maps->height * data->render->cell_size / 5)
			&& x <= data->maps->longest_line * (data->render->cell_size / 5))
			drawStart = (data->maps->height * data->render->cell_size / 5);
		my_mlx_pixel_put(data->render, x, drawStart, color);
		drawStart++;
	}
}

void	render_ceil(t_data *data, int drawEnd, int x, int color, char *name)
{
	while (drawEnd < 900)
	{	
		my_mlx_pixel_put(data->render, x, drawEnd, 0x242222);
		drawEnd++;
	}
}

void	render_line(t_data *data, int color, int drawStart, int drawEnd, int x, char *name)
{
	render_floor(data, drawStart, x, name);
	render_walls(data, drawStart, drawEnd, x, color, name);
	render_ceil(data, drawEnd, x, 0x242222, name);
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
	lineHeight = (h / perpWallDist) * 40;
	drawStart = -lineHeight * 0.5 + h * 0.5;
    if(drawStart < 0)
		drawStart = 0;
    drawEnd = lineHeight * 0.5 + h * 0.5;
    if(drawEnd >= h)
		drawEnd = h - 1;
	if (side == 0) // E/W
	{
		if (stepX == 1)
		{
			render_line(data, 0xFFFF00, drawStart, drawEnd, x, "path_to_the_west_texture.xpm");
			return ;
		}
		else if (stepX == -1)
		{
			render_line(data, 0xFFFFFF, drawStart, drawEnd, x, "path_to_the_east_texture.xpm");
			return ;
		}
	}
	else // N/S
	{
		if (stepY == 1)
		{
			render_line(data, 0x000000, drawStart, drawEnd, x, "path_to_the_north_texture.xpm");
			return ;
		}
		else if (stepY == -1)
		{
			render_line(data, 0x009911, drawStart, drawEnd, x, "path_to_the_south_texture.xpm");
			return ;
		}
	}
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/14 16:13:42 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_ceil(t_data *data, int drawStart, int x, char *name)
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

int get_color_from_xpm(t_data *data, int x, int y)
{
	// int		size = data->wall->bits_per_pixel / 8;

	// int pos = (y * data->wall->size_line + x * (data->wall->bits_per_pixel / 8));
	// char *dst = data->wall->addr + (pos);
	// return ((unsigned int*)dst);
	//printf("%d %d\n", x, y);
	return (*(unsigned int *)(data->wall->addr
        + (y * data->wall->size_line + x * data->wall->bits_per_pixel / 8))
    );
}

void	render_walls(t_data *data, int drawStart, int drawEnd, int x, int color, char *name)
{
	int sizeWall = drawEnd - drawStart;
	float ratio = 64 / (float)sizeWall;
	// printf("wall = %f\n", ratio);
	while (drawStart < drawEnd)
	{
		if (drawStart <= (data->maps->height * data->render->cell_size / 5)
			&& x <= data->maps->longest_line * (data->render->cell_size / 5))
			drawStart = (data->maps->height * data->render->cell_size / 5);
		my_mlx_pixel_put(data->render, x, drawStart, color);
		int color2;
		// printf("%f %f\n", x * ratio, (drawEnd - drawStart) * ratio);
		color2 = get_color_from_xpm(data, x * ratio, (drawEnd - drawStart) * ratio);
		my_mlx_pixel_put(data->render, x, drawStart, color2);
		drawStart++;
	}
}

void	render_floor(t_data *data, int drawEnd, int x, int color, char *name)
{
	while (drawEnd < 900)
	{	
		my_mlx_pixel_put(data->render, x, drawEnd, 0x242222);
		drawEnd++;
	}
}

void	render_line(t_data *data, int color, int drawStart, int drawEnd, int x, char *name)
{
	// render_ceil(data, drawStart, x, name);
	render_walls(data, drawStart, drawEnd, x, color, name);
	render_floor(data, drawEnd, x, 0x242222, name);
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
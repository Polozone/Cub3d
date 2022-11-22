/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 17:19:27 by pmulin           ###   ########.fr       */
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

void	render_walls(t_data *data, t_img *img, int drawStart, int drawEnd, int x, int mapX, int mapY, int side, t_col *col)
{
	int color2;

	col->sizeWall = col->drawEnd - col->drawStart;
	float ratio = 64 / (float)col->sizeWall;
	float hitX = (float)col->mapX / data->render->cell_size;
	float hitY = (float)col->mapY / data->render->cell_size;
	int	index_X = ((hitX - (int)hitX)) * 64;
	int	index_Y = ((hitY - (int)hitY)) * 64;
	while (col->drawStart < col->drawEnd)
	{
		if ((col->drawStart > 0 && col->drawStart < 900) || (col->drawEnd > 0 && col->drawEnd < 900))
		{
			if (col->side == 0)
				color2 = get_color_from_xpm(img, index_Y, (col->drawEnd - col->drawStart) * ratio);
			if (col->side == 1)
				color2 = get_color_from_xpm(img, index_X, (col->drawEnd - col->drawStart) * ratio);
			my_mlx_pixel_put(data->render, x, col->drawStart, color2);
		}
		col->drawStart++;
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

void	render_line(t_data *data, int x, t_img *img, t_col *col)
{
	// printf("start = %d end = %d\n", col->drawStart, col->drawEnd);
	render_ceil(data, col->drawStart, x);
	render_walls(data, img, col->drawStart, col->drawEnd, x, col->mapX, col->mapY, col->side, col);
	render_floor(data, col->drawEnd, x, data->floor_color, col->h);
	return ;
}

void	render_wall(t_data *data, t_col *col, int x)
{
	if (col->side == 0)
		col->perpWallDist = (col->sideDistX - col->deltaDistX);
	else
		col->perpWallDist = (col->sideDistY - col->deltaDistY);
	if (col->perpWallDist == 0)
		col->perpWallDist = 1;
	col->lineHeight = (col->h / col->perpWallDist) * 40;
	col->drawStart = (-col->lineHeight >> 1) + (col->h >> 1);
    col->drawEnd = (col->lineHeight >> 1) + (col->h >> 1);
	if (col->side == 0)
	{
		if (col->stepX == 1)
		{
			render_line(data, x, &data->west, col);
			return ;
		}
		else if (col->stepX == -1)
		{
			render_line(data, x, &data->east, col);
			return ;
		}
	}
	else
	{
		if (col->stepY == 1)
		{
			render_line(data, x, &data->north, col);
			return ;
		}
		else if (col->stepY == -1)
		{
			render_line(data, x, &data->south, col);
			return ;
		}
	}
	return ;
}
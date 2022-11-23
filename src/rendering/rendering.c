/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 09:24:55 by pmulin           ###   ########.fr       */
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

int	get_color_from_xpm(t_img *img, int x, int y)
{
	char	*color;

	if (y == 64)
		y = 63;
	color = (img->addr + (x * img->precompute_bits_p_px)
			+ (y * img->size_line));
	return (*(unsigned int *)color);
}

void	render_walls(t_data *data, t_img *img, int x, t_col *col)
{
	int		color2;
	float	hitx;
	float	hity;

	col->sizeWall = col->drawEnd - col->drawStart;
	hitx = (float)col->mapX / data->render->cell_size;
	hity = (float)col->mapY / data->render->cell_size;
	while (col->drawStart < col->drawEnd)
	{
		if ((col->drawStart > 0 && col->drawStart < 900)
			|| (col->drawEnd > 0 && col->drawEnd < 900))
		{
			if (col->side == 0)
				color2 = get_color_from_xpm(img, ((hity - (int)hity)) * 64,
						((col->drawEnd - col->drawStart) << 6)
						/ (float)col->sizeWall);
			else
				color2 = get_color_from_xpm(img, ((hitx - (int)hitx)) * 64,
						((col->drawEnd - col->drawStart) << 6)
						/ (float)col->sizeWall);
			my_mlx_pixel_put(data->render, x, col->drawStart, color2);
		}
		col->drawStart++;
	}
}

void	render_floor(t_data *data, int drawEnd, int x, int color)
{
	while (drawEnd < 900)
	{
		my_mlx_pixel_put(data->render, x, drawEnd, color);
		drawEnd++;
	}
}

void	render_line(t_data *data, int x, t_img *img, t_col *col)
{
	render_ceil(data, col->drawStart, x);
	render_walls(data, img, x, col);
	render_floor(data, col->drawEnd, x, data->floor_color);
	return ;
}

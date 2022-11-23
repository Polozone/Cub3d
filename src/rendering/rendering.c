/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:15:27 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 13:48:36 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_ceil(t_data *data, int drawstart, int x)
{
	int		i;

	i = 0;
	while (i < drawstart)
	{
		my_mlx_pixel_put(data->render, x, i, data->ceil_color);
		i++;
	}
}

int	get_color_from_xpm(t_img *img, int x, int y)
{
	char	*color;

	if (y == 64)
		y--;
	color = (img->addr + (x * img->precompute_bits_p_px)
			+ (y * img->size_line));
	return (*(unsigned int *)color);
}

void	render_walls(t_data *data, t_img *img, int x, t_col *col)
{
	int		color2;
	float	hitx;
	float	hity;

	col->sizewall = col->drawend - col->drawstart;
	hitx = (float)col->mapx / data->render->cell_size;
	hity = (float)col->mapy / data->render->cell_size;
	while (col->drawstart < col->drawend)
	{
		if ((col->drawstart > 0 && col->drawstart < 900)
			|| (col->drawend > 0 && col->drawend < 900))
		{
			if (col->side == 0)
				color2 = get_color_from_xpm(img, ((hity - (int)hity))
						* img->height, ((col->drawend - col->drawstart)
							* img->height) / (float)col->sizewall);
			else
				color2 = get_color_from_xpm(img, ((hitx - (int)hitx))
						* img->width, ((col->drawend - col->drawstart)
							* img->width) / (float)col->sizewall);
			my_mlx_pixel_put(data->render, x, col->drawstart, color2);
		}
		col->drawstart++;
	}
}

void	render_floor(t_data *data, int drawend, int x, int color)
{
	while (drawend < 900)
	{
		my_mlx_pixel_put(data->render, x, drawend, color);
		drawend++;
	}
}

void	render_line(t_data *data, int x, t_img *img, t_col *col)
{
	render_ceil(data, col->drawstart, x);
	render_walls(data, img, x, col);
	render_floor(data, col->drawend, x, data->floor_color);
	return ;
}

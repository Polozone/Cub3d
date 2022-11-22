/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:02:05 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 14:45:05 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_render *render, int x, int y, int color)
{
	char	*dst;

	dst = render->addr + (y * render->line_length
			+ x * (render->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

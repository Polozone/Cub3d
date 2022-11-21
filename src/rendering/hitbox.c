/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitbox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:56:56 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/18 11:16:23 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int hitbox(t_data *data)
{
    t_vector2_d origin;
    t_vector2_d to;
    t_vector2_d delta;
    int         angle;
    int         i;

    
    angle = data->render->angle;
    i = 0;
    origin = vect_f_to_d(data->render->origin);
    to.x = origin.x;
    to.y = origin.y + 50;
    while (i < 360)
    {
        float radians = (float)angle * M_PI_2;
        
        delta.x = (cos(radians) * (to.x - origin.x) - sin(radians) * (to.y - origin.y) + origin.x);
        delta.y = (sin(radians) * (to.x - origin.x) + cos(radians) * (to.y - origin.y) + origin.y);
        
        my_mlx_pixel_put(data->render, delta.x, delta.y, 0xffffff);
        i++;
        angle++;
    }    
    return (0);
}
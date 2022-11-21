/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_vect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:51 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/03 12:16:42 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector2_f vect_d_to_f(t_vector2_d vect)
{
	t_vector2_f ret;

	ret.x = (float)vect.x;
	ret.y = (float)vect.y;
	return (ret);
}

t_vector2_d vect_f_to_d(t_vector2_f vect)
{
	t_vector2_d ret;

	ret.x = (int)vect.x;
	ret.y = (int)vect.y;
	return (ret);
}
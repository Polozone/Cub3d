/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:19:55 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/24 14:33:03 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_prg *prg)
{
	if (keycode < 200)
		prg->keyboard[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_prg *prg)
{
	if (keycode < 200)
		prg->keyboard[keycode] = 0;
	return (0);
}
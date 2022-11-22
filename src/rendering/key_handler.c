/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:09:42 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 14:07:43 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	deal_key(int key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 0;
	return (0);
}

void	player_input(t_data *data)
{
	if (data->keytab[KEY_ESC])
		exit_program(data);
	if (data->keytab[KEY_W])
		move_up(data);
	if (data->keytab[KEY_Q] || data->keytab[KEY_LEFT])
		rotate_left(data);
	if (data->keytab[KEY_S])
		move_down(data);
	if (data->keytab[KEY_E] || data->keytab[KEY_RIGHT])
		rotate_right(data);
	if (data->keytab[KEY_D])
		move_right(data);
	if (data->keytab[KEY_A])
		move_left(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_rendering.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:27:42 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 14:17:18 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	check_dir(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->maps->map[i])
	{
		j = 0;
		while (data->maps->map[i][j])
		{
			if (data->maps->map[i][j] == 'N')
				return ('N');
			if (data->maps->map[i][j] == 'S')
				return ('S');
			if (data->maps->map[i][j] == 'E')
				return ('E');
			if (data->maps->map[i][j] == 'W')
				return ('W');
			j++;
		}
		i++;
	}
	return (0);
}

void	set_dir(t_data *data)
{
	if (check_dir(data) == 'N')
	{
		data->render->dir.y = (-1);
		data->render->plane.x = (0.66);
	}
	else if (check_dir(data) == 'S')
	{
		data->render->dir.y = (1);
		data->render->plane.x = (-0.66);
	}
	else if (check_dir(data) == 'E')
	{
		data->render->dir.x = (1);
		data->render->plane.y = (0.66);
	}
	else if (check_dir(data) == 'W')
	{
		data->render->dir.x = (-1);
		data->render->plane.y = (-0.66);
	}
}

void	init_data(t_data *data)
{
	data->render->cell_size = 40;
	data->render->origin.x = get_x_player(data) * 40;
	data->render->origin.y = get_y_player(data) * 40;
	data->render->dir.x = (0);
	data->render->dir.y = (0);
	data->render->plane.x = (0);
	data->render->plane.y = (0);
	data->render->angle = 0;
	set_dir(data);
	ft_bzero(&data->keytab, 200);
	return ;
}

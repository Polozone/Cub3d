/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:54:08 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 09:56:58 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_2d_array(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	return ;
}

void	free_arr_from_end(t_data *data, char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	exit (1);
}

void	free_param_struct(t_data *data)
{
	int	i;

	i = -1;
	while (!data->params[++i].stop)
	{
		if (data->params[i].color)
			free(data->params[i].color);
		if (data->params[i].coord)
			free(data->params[i].coord);
		if (data->params[i].rgb)
			free_2d_array(data->params[i].rgb);
		if (data->params[i].path)
			free(data->params[i].path);
	}
	free(data->params);
}

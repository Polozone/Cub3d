/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:40:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/15 15:22:50 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_one_player(char	*map)
{
	int		i;
	char	cmpt;

	i = 0;
	cmpt = 0;
	while (map[i])
	{
		if (ft_strchr("NSWE", map[i]))
			cmpt++;
		if (cmpt > 1)
		{
			write(2, "Error\nMap need at least (and max) one player", 44);
			return (false);
		}
		i++;
	}
	if (cmpt == 0)
	{
		write(2, "Error\nThere is 0 player on the map, need one", 44);
		return (false);
	}
	return (true);
}

int		get_x_player(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->maps->map[i])
	{
		printf("%s\n", data->maps->map[i]);
		i++;
	// 	j = 0;
	// 	while (data->maps->map[i][j])
	// 	{
	// 		if (ft_strchr("NSWE", data->maps->map[i][j]))
	// 			return (j);
	// 		j++;
	// 	}
	// 	i++;
	// }
	}
	return (-1);
}

int		get_y_player(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->maps->map[i])
	{
		j = 0;
		while (data->maps->map[i][j])
		{
			if (ft_strchr("NSWE", data->maps->map[i][j]))
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
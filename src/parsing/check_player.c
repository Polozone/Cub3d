/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:40:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/24 09:49:51 by pmulin           ###   ########.fr       */
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
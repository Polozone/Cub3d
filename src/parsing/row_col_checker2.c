/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_checker2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:22:02 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 09:08:46 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_last_char_x(char *line)
{
	int		i;
	char	buf;

	buf = -1;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '	')
			buf = line[i];
		i++;
	}
	return (buf);
}

int	get_first_char_y(char **array, int i, int j)
{
	while ((i >= 0) && ft_strchr("NSEW01", array[i][j]))
	{
		i--;
	}
	if (array[++i][j] != '1')
	{
		return (1);
	}
	return (0);
}

int	get_last_char_y(char **array, int i, int j)
{
	while (array[i] && ft_strchr("NSEW01", array[i][j]))
		i++;
	if (array[--i][j] != '1')
	{
		return (1);
	}
	else
		return (0);
}

t_bool	is_valid_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (get_last_char_x(map[i]) != '1'
					|| get_first_char_x(map[i]) != '1')
					return (false);
				if (get_first_char_y(map, i, j) || get_last_char_y(map, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

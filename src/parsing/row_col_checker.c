/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:20:28 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/24 09:22:35 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				is_not_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (true);
	else
		return (false);
}

t_bool		row_checker(char *row, int col)
{
	int		i;

	i = 0;
	while (row[i])
	{
		if ((row[0] && row[0] != '1') || (row[i] != '1' && row[i + 1] == '\0'))
		{
			free(row);
			printf("Error line %d at index %d of the map\n", col, i);
			return (false);
		}
		// if (row[i] != '1' && row[i + 1] == '\0')
		// {
		// 	free(row);
		// 	return (false);
		// }
		// if ((row[i] == '0' && row[i + 1] == '\0') 
		// 	|| row[i] == '0' && row[i + 1] == '\0')
		i++;
	}
	return (true);
}

static t_bool	col_checker(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		printf("%c", map[i][j]);
		j++;
	}
	return (true);
}

t_bool	is_valid_map(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	while (data->maps->map[i])
	{
		tmp = ft_strtrim(data->maps->map[i], " 	");
		if (row_checker(tmp, i) == false)
			return (false);
		i++;
	}
	if (col_checker(data->maps->map) == false)
		return (false);
	return (true);
}
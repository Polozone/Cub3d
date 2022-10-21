/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:20:28 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/21 16:21:59 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool		is_charmap(char c)
{
	if (c == '0' || c == 'N'
		|| c == 'S' || c == 'E'
		|| c == 'W' || c == ' '
		|| c == '1' || c == '	')
	{
		return (true);
	}
	return (false);
}

static t_bool		is_not_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (true);
	else
		return (false);
}

static t_bool		row_checker(char *row, int col)
{
	int		i;

	i = 0;
	while (row[i])
	{
		if ((row[0] && row[0] != '1') || (row[i] != '1' && row[i + 1] == '\0'))
		{
			free(row);
			write(2, "Error\n", 7);
			return (false);
		}
		i++;
	}
	return (true);
}

static t_bool	col_checker(t_data *data, char **map, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	j = 0;
	i = 0;
	len = len_2d_array(map);
	while (i < data->maps->longest_line)
	{
		j = 0;
		str = malloc(sizeof(char) * (len + 1));
		if (!str)
			exit (-1);
		while (map[j])
		{
			str[j] = map[j][i];
			j++;
		}
		str[j] = '\0';
		tmp = ft_strtrim(str, " 	");
		if (row_checker(tmp, i) == false)
			return (false);
		free(str);
		i++;
	}
	return (true);
}

static t_bool	is_player(t_data *data)
{
	int		i;
	int		j;
	char	cmpt;

	cmpt = 0;
	i = 0;
	j = 0;
	while (data->maps->map[i])
	{
		j = 0;
		while (data->maps->map[i][j])
		{
			if (data->maps->map[i][j] == 'W' || data->maps->map[i][j] == 'N'
			|| data->maps->map[i][j] == 'S' || data->maps->map[i][j] == 'E')
			{
				cmpt++;
				if (cmpt > 1)
					return (false);
			}
			j++;
		}
		i++;
	}
	if (cmpt != 1)
	{
		write(2, "Map need one player\n", 20);
		return (false);
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
	if (col_checker(data, data->maps->map, NULL) == false)
		return (false);
	if (is_player(data) == false)
		return (false);
	return (true);
}
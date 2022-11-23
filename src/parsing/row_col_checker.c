/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:20:28 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 13:24:27 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	is_charmap(char c)
{
	if (c == '0' || c == 'N'
		|| c == 'S' || c == 'E'
		|| c == 'W' || c == ' '
		|| c == '1' || c == '	' || c == '\n')
	{
		return (true);
	}
	return (false);
}

t_bool	is_not_wall(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
		return (true);
	else
		return (false);
}

t_bool	row_checker(char *row, int col)
{
	int		i;

	i = 0;
	while (row[i])
	{
		if ((row[0] && row[0] != '1') || (row[i] != '1' && row[i + 1] == '\0')
			|| (row[i] == '0' && row[i + 1] == ' '))
		{
			free(row);
			write(2, "Error\nInvalid map", 17);
			return (false);
		}
		i++;
	}
	return (true);
}

t_bool	col_checker(t_data *data, char **map, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = -1;
	len = len_2d_array(map);
	while (++i < data->maps->longest_line)
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
	}
	return (true);
}

char	get_first_char_x(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '	')
			return (line[i]);
		i++;
	}
	return (-1);
}

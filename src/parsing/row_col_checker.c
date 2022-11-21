/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:20:28 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 09:40:02 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool		is_charmap(char c)
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

static t_bool		is_not_wall(char c)
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

// t_bool	is_valid_map(t_data *data)
// {
// 	// int		i;
// 	// char	*tmp;

// 	// i = 0;
// 	// while (data->maps->map[i])
// 	// {
// 	// 	tmp = ft_strtrim(data->maps->map[i], " 	");
// 	// 	if (row_checker(tmp, i) == false)
// 	// 		return (false);
// 	// 	i++;
// 	// }
// 	// if (col_checker(data, data->maps->map, NULL) == false)
// 	// 	return (false);
// 	return (true);
// }


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

int	get_first_char_y(char **array, int j)
{
	int i = 0;
	while (array[i])
	{
		// printf("%s\n", array[i]);
		i++;
	}
	if (array[0][j] != '1')
	{
		//printf("array[0][%d] ==%c||",j , array[0][j]);
		return (1);
	}
	else
		return (0);
}

int	get_last_char_y(char **array, int i, int j)
{
	while (array[i])
	{
		i++;
	}
	if (array[--i][j] != '1')
	{
		//printf("char == %c", array[--i][j]);
		return (1);
	}
	else
		return (0);
}

t_bool	is_valid_map(char **map)
{
	int i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		printf("%s\n", map[i]);
		// printf("%s\n", map[i]);
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (get_last_char_x(map[i]) != '1' || get_first_char_x(map[i]) != '1')
				{
					return (false);
				}
				if (get_first_char_y(map, j) || get_last_char_y(map, i, j))
				{
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}
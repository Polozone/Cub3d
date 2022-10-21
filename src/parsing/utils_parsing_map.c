/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:07:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/21 10:20:59 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		get_longest_line(char *line)
{
	int		i;
	int		longest;
	int		tmp;

	i = 0;
	longest = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		tmp = 0;
		while (line[i] && line[i] != '\n')
		{
			tmp++;
			i++;
		}
		if (tmp > longest)
			longest = tmp;
		i++;
	}
	return (longest);
}

int				is_map(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

char		*clear_endmap(char	*line)
{
	int		sep;
	int		len;
	char	*newline;

	sep = ft_strlen(line);
	len = sep;
	if (line == 0)
		return (NULL);
	while (sep > 0)
	{
		if (is_map(line[sep]))
		{
			newline = ft_substr(line, 0, sep);
			free(line);
			return (newline);
		}
		sep--;
	}
	return (NULL);
}

int		count_nl(char *line)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}

void		print_map(char **map)
{
	int i = 0;
	int j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
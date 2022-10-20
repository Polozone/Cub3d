/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by pmulin            #+#    #+#             */
/*   Updated: 2022/10/20 15:16:00 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_longest_line(char *line)
{
	int		i;
	int		longest;
	int		tmp;

	i = 0;
	longest = 0;
	tmp = 0;
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

// static int		nl_count(char	*line)
// {
	
// }

int				is_map(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

static void		clear_endmap(char	*line)
{
	int		len;

	len = ft_strlen(line);
	if (line == 0)
		return ;
	while (len != 0)
	{
		if (is_map(line[len]))
		{
			line[len + 1] = '\0';
			return ;
		}
		len--;
	}
}

static void		str_to_map(t_data *data, char *argv)
{
	int		fd;
	char	*line;
	int		longest_line;

	(void)data;
	fd = open(argv, O_RDWR);
	line = _get_file(fd);
	line = ft_strtrim(line, "\n");
	clear_endmap(line);

	printf("%s", line);
	longest_line = get_longest_line(line);
}


int		init_parsing_map(t_data *data, t_map *map, char *argv)
{
	data->maps = map;
	str_to_map(data, argv);
	// get_longest_line(data);
	return (0);
}
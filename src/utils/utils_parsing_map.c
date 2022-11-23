/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:07:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/23 10:43:33 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	create_rgb_utils(t_data *data, int i, char *tmp)
{
	char	*tmp1;

	tmp1 = NULL;
	tmp1 = ft_convert_base(data, tmp, "0123456789abcdef", "0123456789");
	if (!ft_strncmp("F", data->params[i].color,
			ft_strlen(data->params[i].color)))
		data->floor_color = ft_atoi(tmp1);
	else if (!ft_strncmp("C", data->params[i].color,
			ft_strlen(data->params[i].color)))
		data->ceil_color = ft_atoi(tmp1);
}

unsigned long	create_rgb(t_data *data)
{
	int				i;
	int				j;
	char			*tmp;
	char			*tmp1;

	i = -1;
	tmp = NULL;
	while (data->params[++i].stop == 0)
	{
		if (data->params[i].color != NULL)
		{
			j = -1;
			while (++j < 3)
			{
				tmp1 = dec_to_hex_converter(data,
						ft_atoi(data->params[i].rgb[j]), 0);
				if (!ft_strncmp(tmp1, "0", ft_strlen(tmp1)))
					tmp1 = gc_strjoin(&data->track, tmp1, "0");
				tmp = gc_strjoin(&data->track, tmp, tmp1);
			}
			create_rgb_utils(data, i, tmp);
		}
		tmp = NULL;
	}
	return (0);
}

int	get_longest_line(char *line)
{
	int		i;
	int		longest;
	int		tmp;
	int		max;

	i = 0;
	longest = 0;
	max = ft_strlen(line);
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
		if (i >= max)
			return (longest);
		i++;
	}
	return (longest);
}

char	*clear_endmap(char	*line)
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
			newline = ft_substr(line, 0, sep + 1);
			free(line);
			return (newline);
		}
		sep--;
	}
	return (NULL);
}

int	count_nl(char *line)
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

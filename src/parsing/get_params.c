/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:23:51 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 09:01:56 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_coord(t_data *data, char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		while (arg[i] && arg[i] == ' ')
			i++;
		return (gc_substr(&data->track, arg, i, 2));
	}
	return (0);
}

static char	*get_path(t_data *data, char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[++i])
	{
		while (arg[i] && arg[i] != '.')
			i++;
		while (arg[i + j] && arg[i + j] != ' ')
			j++;
		return (gc_substr(&data->track, arg, i, j));
	}
	return (0);
}

static char	*get_color(t_data *data, char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		while (arg[i] && arg[i] == ' ')
			i++;
		return (gc_substr(&data->track, arg, i, 1));
	}
	return (0);
}

static char	**get_rgb(t_data *data, char *arg)
{
	int		i;
	char	**new;
	char	*tmp;

	i = -1;
	tmp = NULL;
	new = NULL;
	while (arg[++i])
	{
		while (arg[i] && !ft_isalpha(arg[i]))
			i++;
		tmp = gc_substr(&data->track, arg, i + 1, ft_strlen(&arg[i + 1]));
		new = gc_split(&data->track, tmp, ',');
		break ;
	}
	i = -1;
	while (new[++i])
		new[i] = gc_strtrim(&data->track, new[i], " ");
	return (new);
}

void	fill_params(t_data *data, char **params)
{
	int	i;

	i = -1;
	while (params[++i])
	{
		data->params[i].type = 0;
		if (params_find_type(params[i]) == 1)
		{
			data->params[i].coord = get_coord(data, params[i]);
			data->params[i].path = get_path(data, params[i]);
		}
		else if (params_find_type(params[i]) == 2)
		{
			data->params[i].color = get_color(data, params[i]);
			data->params[i].rgb = get_rgb(data, params[i]);
			data->params[i].type = 1;
		}
	}
}

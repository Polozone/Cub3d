/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:55 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/22 15:05:56 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_bool	check_param_type(char *param, int *i)
{
	if (param[*i] == 'N' || param[*i] == 'S'
		|| param[*i] == 'E' || param[*i] == 'W')
	{
		if (check_coordinate_param(param, i) == true)
			return (true);
	}
	else if (param[*i] == 'F' || param[*i] == 'C')
	{
		if (check_color_param(param, i) == true)
			return (true);
	}
	return (false);
}

// Cette fonction renvoie true si les paramettre du .cub 
// sont valide et false si ils ne le sont pas
static t_bool  check_param(char *param)
{
	int i;

	i = -1;
	while (param[++i])
	{
		while (param[i] == ' ' && param[i])
			i++;
		if (check_param_type(param, &i) == false)
			return (false);
		if (!param[i])
			break ;
	}
	return (true);
}

int	skip_space_params(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
		if (param[i] != 32 && param[i] != 9 && param[i] != '\n')
			return (1);
	return (0);
}

int	params_find_type(char *param)
{
	int	i;

	i = -1;
	while (param[++i])
	{
		while (!ft_isalpha(param[i]))
			i++;
		if (param[i] == 'N' || param[i] == 'S'
			|| param[i] == 'E' || param[i] == 'W')
			return (1);
		else if (param[i] == 'F' || param[i] == 'C')
			return (2);
	}
	return (0);
}

char	*get_coord(t_data *data, char *arg)
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

char	*get_path(t_data *data, char *arg)
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

char	*get_color(t_data *data, char *arg)
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

char	**get_rgb(t_data *data, char *arg)
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

int	init_params(t_data *data, char **params)
{
	int	i;
	
	i = -1;
	data->params = malloc(sizeof(t_params) * 7);
	while (params[++i])
	{
		data->params[i].type = 0;
		data->params[i].coord = NULL;
		data->params[i].path = NULL;	
		data->params[i].color = NULL;
		data->params[i].rgb = NULL;
		data->params[i].stop = 0;
		data->params[i].hexa_rgb = 0;
	}
	data->params[6].stop = 1;
	fill_params(data, params);
	return (0);
}

// void	init_param_checker(t_data *data, char ***params_check)
// {
// 	*params_check = {
// 		"N0",
// 		"S0",
// 		"E0",
// 		"W0",
// 		"F0",
// 		"C0"
// 	};
// }

t_bool  parse_map_params(t_data *data, char *filename)
{
	char    **file;
	char    **params;
	int		count;
	char	**params_check;
	int		i;
	int		k;

	i = -1;
	k = -1;
	count = 0;
	file = get_cub_file(data, filename);
	if (!file)
		return (false);
	params = gc_calloc(7, sizeof(char *), &data->track);
	while (file[++i])
	{
		if (skip_space_params(file[i]))
		{
			if (check_param(file[i]) == true && count < 6)
			{
				params[++k] = gc_strdup(&data->track, file[i]);
				count++;
			}
			else
			{
				if (count == 6)
					break ;
				write(2, "error\n", 7);
				gc_free_all(&data->track);
				return (false);
			}
		}
	}
	data->map_line = get_map_from_file(data, filename);
	init_params(data, params);
	createRGB(data);
	return (true);
}

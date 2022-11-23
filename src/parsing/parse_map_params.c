/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:55 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 09:21:24 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	init_params(t_data *data, char **params)
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

int	parse_params_utils(t_data *data, t_parse_params *p)
{
	if (check_param(p->file[p->i]) == true && p->count < 6)
	{
		p->params[p->k] = gc_strdup(&data->track, p->file[p->i]);
		(p->k)++;
		(p->count)++;
	}
	else
	{
		if (p->count == 6)
			return (1);
		write(2, "error\n", 7);
		gc_free_all(&data->track);
		return (-1);
	}
	return (0);
}

t_bool	parse_map_params(t_data *data, char *filename)
{
	int				r;
	t_parse_params	p;

	p.i = -1;
	p.k = 0;
	p.count = 0;
	p.file = get_cub_file(data, filename);
	if (!p.file)
		return (false);
	p.params = gc_calloc(7, sizeof(char *), &data->track);
	while (p.file[++p.i])
	{	
		if (skip_space_params(p.file[p.i]))
		{
			r = parse_params_utils(data, &p);
			if (r == -1)
				return (false);
			else if (r == 1)
				break ;
		}
	}
	data->map_line = get_map_from_file(data, filename);
	init_params(data, p.params);
	create_rgb(data);
	return (true);
}

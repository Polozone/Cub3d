/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinate_params.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:25:03 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/22 14:30:44 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_bool	check_path(char *param, int *i)
{
	if (param[(*i)] == '.')
		if (param[(*i) + 1] != '/')
			return (false);
	if (param[(*i)] != '.')
		return (false);
	(*i)++;
	while (param[++(*i)])
	{
		if (param[(*i)] == ' ')
		{
			while (param[(*i)])
			{
				if (param[(*i)] != ' ')
					return (false);
				(*i)++;
			}
		}
	}
	return (true);
}

static t_bool	check_coordinate(char *param, int i)
{
	if (param[i] == 'N')
	{
		if (param[i + 1] == 'O')
			return (true);
	}
	else if (param[i] == 'S')
	{
		if (param[i + 1] == 'O')
			return (true);
	}
	else if (param[i] == 'E')
	{
		if (param[i + 1] == 'A')
			return (true);
	}
	else if (param[i] == 'W')
	{
		if (param[i + 1] == 'E')
			return (true);
	}
	return (false);
}

t_bool	check_coordinate_param(char *param, int *i)
{
	if (check_coordinate(param, (*i)) == false
		&& param[(*i)] && param[(*i)] != ' ')
		return (false);
	(*i) += 2;
	while (param[(*i)] == ' ' && param[(*i)])
		(*i)++;
	if (param[(*i)] && param[(*i)] != ' '
		&& check_path(param, i) == false)
		return (false);
	return (true);
}

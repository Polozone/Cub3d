/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:54:31 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 09:41:37 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_bool	check_color(char *param, int *i, int check)
{
	(void)param;
	(void)check;
	(void)i;
	return false;
	// UTILISER ATOI
}

static t_bool	check_letter(char *param, int i)
{
	if (!param[i + 1] && param[i + 1] != '0'
		&& param[i + 1] != '1' && param[i + 1] != '2')
		return (false);
	return (true);
}

t_bool	check_color_param(char *param, int *i)
{
	if (check_letter(param, (*i)) == false
		&& param[(*i)] && param[(*i)] != ' ')
			return (false);
	(*i) += 1;
	while (param[(*i)] == ' ' && param[(*i)])
		(*i)++;
	if (param[(*i)] && param[(*i)] != ' '
		&& check_color(param, i, 0) == false)
		return (false);
	return (true);
}
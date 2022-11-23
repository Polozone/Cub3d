/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:54:31 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/22 14:29:47 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	trim_spaces(char **str)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strtrim(*str, " ");
	free(tmp);
}

static t_bool	check_color(char *param, int *i)
{
	int		j;
	char	**colors;

	j = 0;
	colors = ft_split(&param[*i], ',');
	if (!colors)
		return (false);
	while (colors[j])
	{
		if (ft_strchr(colors[j], ' '))
			trim_spaces(&colors[j]);
		if (!contains_digit(colors[j]))
			return (false);
		if (ft_atoi(colors[j]) < 0 || ft_atoi(colors[j]) > 255)
			return (false);
		j++;
	}
	(*i) = ft_strlen(param);
	free_2d_array(colors);
	return (true);
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
		&& check_color(param, i) == false)
		return (false);
	return (true);
}

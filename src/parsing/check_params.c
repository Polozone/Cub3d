/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:22:25 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 09:01:36 by tdeville         ###   ########lyon.fr   */
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
t_bool	check_param(char *param)
{
	int	i;

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

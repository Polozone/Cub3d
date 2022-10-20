/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:55 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/20 15:15:29 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
	NOTES PARSING PARAMS

	trim les espaces;
	
	voir si il y a bien une coordonnée et un path

	valider les codes couleurs 0 -> 255 * 3
		(espaces possible mais virgule obligatoire)
*/

static t_bool	check_path(char *param, int *i)
{
	if (param[(*i)] == '.')
		if (param[(*i) + 1] != '/')
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

static t_bool  check_coordinate(char *param, int i)
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
		if (check_coordinate(param, i) == false
			&& param[i] && param[i] != ' ')
			return (false);
		i += 2;
		while (param[i] == ' ' && param[i])
			i++;
		if (param[i] && param[i] != ' '
			&& check_path(param, &i) == false)
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

t_bool  parse_map_params(t_data *data, char *filename)
{
	char    **file;
	char    **params;
	int		i;
	int		k;

	i = -1;
	k = -1;
	file = get_cub_file(data, filename);
	if (!file)
		return (false);
	params = ft_calloc(7, sizeof(char *));
	while (file[++i])
	{
		if (skip_space_params(file[i]))
		{
			if (check_param(file[i]) == true)
				params[++k] = ft_strdup(file[i]);
			else
			{
				// free tout le bordel
				return (false);
			}
		}	
		printf("%s\n", params[i]);
	}
	return (true);
}

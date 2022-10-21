/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:55 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 11:46:11 by tdeville         ###   ########lyon.fr   */
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
			{
				params[++k] = ft_strdup(file[i]);
				printf("%s\n", params[k]);
			}
			else
			{
				if (len_2d_array(params) == 6)
					break ;
				free_2d_array(params);
				free_2d_array(file);
				return (false);
			}
		}
	}
	data->map_line = map_to_line(&file[i]);
	/* A faire avant de free: 
			- mettre les params dans la structure param
	*/
	free_2d_array(params);
	free_2d_array(file);
	free(data->map_line);
	return (true);
}

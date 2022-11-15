/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:20:17 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/15 14:39:45 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Return 0 si contient autre chose qu'un chiffre
// sinon return 1
int	contains_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (1);
}

int	len_2d_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

// Join un 2d arry en une seule string
char	*map_to_line(char **arr)
{
	int		i;
	char	*tmp;
	char	*new;
	char	*wnl;

	i = -1;
	new = NULL;
	tmp = NULL;
	while (arr[++i])
	{
		wnl = ft_strjoin(arr[i], "\n");
		if (!new)
		{
			new = ft_strdup(wnl);
			tmp = new;
		}
		else
		{
			tmp = new;
			new = ft_strjoin(new, wnl);
			free(tmp);
		}
		free(wnl);
	}
	return (new);
}

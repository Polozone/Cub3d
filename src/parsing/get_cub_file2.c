/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub_file2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:42:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 14:44:16 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	check_cub(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'b')
		if (file[--len] == 'u')
			if (file[--len] == 'c')
				if (file[--len] == '.')
					if (file[--len] != '.')
						return (true);
	write(2, "Please, provide .cub file\n", 27);
	return (false);
}

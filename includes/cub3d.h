/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/20 13:55:50 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_data t_data;
typedef struct	s_map t_map;

struct s_data
{
	char	**map;
	t_map	*maps;
};

struct s_map
{
	char	**map;
	int		longest_line;
};

char    **get_cub_file(t_data *data, char *filename);
char    *_get_file(int fd);

/*********PARSING_MAP*************/

int		init_parsing_map(t_data *data, t_map *map, char *argv);

#endif
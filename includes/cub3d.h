/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/20 16:08:55 by pmulin           ###   ########.fr       */
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
typedef struct	s_params t_params;
typedef struct	s_map t_map;
typedef enum	s_bool t_bool;

enum s_bool
{
	false,
	true
};

struct s_params
{
	char	**param;
	int		stop;
};

struct s_data
{
	struct s_params	*params;
	char			*map_line;
	t_map			*maps;
};

struct s_map
{
	char	**map;
	int		longest_line;
};

char    **get_cub_file(t_data *data, char *filename);
char    *_get_file(int fd);
t_bool  parse_map_params(t_data *data, char *filename);

/*********PARSING_MAP*************/

int		init_parsing_map(t_data *data, t_map *map, char *argv);
int		get_longest_line(char *line);
int		is_map(char c);
void	clear_endmap(char	*line);
int		count_nl(char *line);
void	print_map(char **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 14:08:28 by tdeville         ###   ########lyon.fr   */
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

// Si type = 0 : coordonéees
// Si type = 1 : couleurs
struct s_params
{
	int		type;
	char	*coord;
	char	*path;
	char	*color;
	char	**rgb;
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

char    **get_cub_file(char *filename);
char    *_get_file(int fd);
t_bool  parse_map_params(t_data *data, char *filename);
t_bool	check_coordinate_param(char *param, int *i);
t_bool	check_color_param(char *param, int *i);

/*********PARSING_MAP*************/

int		init_parsing_map(t_data *data, t_map *map, char *argv);
int		get_longest_line(char *line);
int		is_map(char c);
char	*clear_endmap(char	*line);
int		count_nl(char *line);
void	print_map(char **map);

/************UTILS****************/

int		contains_digit(char *str);
int		len_2d_array(char **arr);
void	free_2d_array(char **array);
void	free_param_struct(t_data *data);
t_bool	row_checker(char *str, int col);
t_bool	is_valid_map(t_data *data);
char	*map_to_line(char **arr);

#endif
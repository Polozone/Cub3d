/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/24 11:17:55 by pmulin           ###   ########.fr       */
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
typedef struct	s_render t_render;
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
	t_render		*render;
};

struct s_map
{
	char	**map;
	int		longest_line;
};

struct s_render {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

char    	**get_cub_file(t_data *data, char *filename);
char    	*_get_file(int fd);
t_bool  	parse_map_params(t_data *data, char *filename);
t_bool		check_coordinate_param(char *param, int *i);
t_bool		check_color_param(char *param, int *i);

/*********PARSING_MAP*************/

int			init_parsing_map(t_data *data, t_map *map, t_render	*render, char *argv);
int			get_longest_line(char *line);
int			is_map(char c);
char		*clear_endmap(char	*line);
int			count_nl(char *line);
void		print_map(char **map);
t_bool		is_charmap(char c);
t_bool		is_one_player(char	*map);

/************UTILS****************/

int			contains_digit(char *str);
int			len_2d_array(char **arr);
void		free_2d_array(char **array);
t_bool		is_valid_map(t_data *data);
char		*map_to_line(char **arr);

/************RENDER****************/

/************INIT_MLX****************/

void	init_mlx(t_data *data);

/************UTILS****************/

void my_mlx_pixel_put(t_render *render, int x, int y, int color);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/27 15:09:29 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_data t_data;
typedef struct	s_params t_params;
typedef struct	s_map t_map;
typedef struct	s_rad t_rad;
typedef struct	s_render t_render;
typedef struct 	s_vector t_vector2_d;
typedef struct 	s_vector_2f t_vector2_f;
typedef struct	s_prg t_prg;
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
	t_params		*params;
	char			*map_line;
	t_map			*maps;
	t_render		*render;
	t_prg			*prg;
	t_rad			*rad;
};

struct s_vector_2f
{
	double		x;
	double		y;
};

struct s_vector
{
	int		x;
	int		y;
};

struct s_map
{
	char	**map;
	int		longest_line;
	int		height;
};

struct s_render {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_height;
	int		win_width;
	int		cell_size;
	int		view_dst;
	
	t_vector2_f dest;
	t_vector2_d map;
	t_vector2_d origin;

	// Tab
	int		**tab;
	int		tab_width;
	int		tab_height;
};

struct s_rad{
	int		center_x;
	int		center_y;
	int		last_x;
	int		last_y;
	int		rad;
	int		degree;
};

struct s_prg{
	t_bool	*keyboard;
};

typedef struct t_ray {
	t_vector2_f hit_point;
	t_vector2_d cell;
	double 		length;
	int 		side_hit;
	double		angle;
} t_ray;

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
int			get_x_player(t_data *data);
int			get_y_player(t_data *data);

/************UTILS****************/

int			contains_digit(char *str);
int			len_2d_array(char **arr);
void		free_2d_array(char **array);
t_bool		is_valid_map(t_data *data);
char		*map_to_line(char **arr);

/************RENDER****************/

int		_bresenham(t_render *data, int x0, int y0, int x1, int y1);
int _bresenham_c(t_render *data, int x0, int y0, int x1, int y1, int color);

/************DDA****************/

t_vector2_f	dda_init_values(t_data *data, t_vector2_f dest);
double		get_dir_X(double dirX, double planeX, double w, int x);
double		get_dir_Y(double dirY, double planeY, double w, int x);

/************INIT_MLX****************/

void	init_mlx(t_data *data);

/************UTILS****************/

void my_mlx_pixel_put(t_render *render, int x, int y, int color);
double	get_angle(t_vector2_d start, t_vector2_d end);

#endif
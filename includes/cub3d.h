/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/14 09:26:14 by tdeville         ###   ########lyon.fr   */
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

# define MOV_SPD 15
# define ROT_SPD 0.1

typedef struct	s_data t_data;
typedef struct	s_params t_params;
typedef struct	s_map t_map;
typedef struct	s_rad t_rad;
typedef struct	s_render t_render;
typedef struct 	s_vector t_vector2_d;
typedef struct 	s_vector_2f t_vector2_f;
typedef struct	s_prg t_prg;
typedef struct	s_math t_math;
typedef struct	s_minimap t_minimap;
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

struct s_math
{
	float	H_PI;
};

struct s_data
{
	t_params		*params;
	char			*map_line;
	t_map			*maps;
	t_render		*render;
	t_prg			*prg;
	t_rad			*rad;
	t_math			*math;
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

struct s_minimap
{
	void	*minimap;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};


struct s_render {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		angle;
	// int		win_height;
	// int		win_width;
	int		cell_size;
	// int		view_dst;
	// int		fov;
	// int		rays_nbr;
	// t_ray	*rays;
	
	t_vector2_f dir;
	t_vector2_f plane;
	// t_vector2_d map;
	t_vector2_f origin;
	t_minimap	minimap;

	// // Tab
	// int		**tab;
	// int		tab_width;
	// int		tab_height;
};

struct s_rad{
	int		center_x;
	int		center_y;
	int		last_x;
	int		last_y;
	int		rad;
	int		degree;
};

char    *_get_file(int fd);
t_bool  parse_map_params(t_data *data, char *filename);
t_bool	check_coordinate_param(char *param, int *i);
t_bool	check_color_param(char *param, int *i);

struct s_prg{
	t_bool	*keyboard;
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
int			get_x_player(t_data *data);
int			get_y_player(t_data *data);

/************UTILS****************/

int			contains_digit(char *str);
int			len_2d_array(char **arr);
void		free_2d_array(char **array);
t_bool		is_valid_map(t_data *data);
char		*map_to_line(char **arr);

/************RENDER****************/

int		_bresenham_c(t_render *data, t_vector2_d start, t_vector2_d end, int color);
void	render_wall(t_data *data, double sideDistX, double sideDistY, int side, double deltaDistX, double deltaDistY, int mapX, int mapY, int x);
void	clear_img(t_data *data);

/************DDA****************/

int dda(t_data *data);

/************INIT_MLX****************/

void	init_mlx(t_data *data);

/************UTILS****************/

int		contains_digit(char *str);
int		len_2d_array(char **arr);
void	free_2d_array(char **array);
void	free_param_struct(t_data *data);
t_bool	row_checker(char *str, int col);
t_bool	is_valid_map(t_data *data);
char	*map_to_line(char **arr);
void 	my_mlx_pixel_put(t_render *render, int x, int y, int color);
double	get_angle(t_vector2_d start, t_vector2_d end);
void 	my_mlx_pixel_put(t_render *render, int x, int y, int color);

/************MOVE.C****************/

int		move_left(t_data *data);
int		move_right(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);

/************CONVERT_VECT.C****************/

t_vector2_f vect_d_to_f(t_vector2_d vect);
t_vector2_d vect_f_to_d(t_vector2_f vect);

/************INIT_STRUCT_RENDERING.C****************/

void	init_data(t_data *data);

/************UTILS_MATH.C****************/

float	ft_abs(float number);
void draw_circle(t_data *data, t_vector2_d center, int color);
t_vector2_f	add_vect(t_vector2_f start, t_vector2_f end);

int _bresenham(t_render *data, int x0, int y0, int x1, int y1);




// THEO

int 	draw_player_1(t_data *data);
void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right, int color);

#endif
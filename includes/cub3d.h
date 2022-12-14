/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 13:44:04 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MOV_SPD 5
# define ROT_SPD 0.05
# define HITBOX	15
# define WIDTH 1200
# define HEIGHT 900

// Keycode
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MOUSE_WHELL 3
# define LMB 1
# define RMB 2
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_R 15
# define KEY_O 31
# define KEY_P 35
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_E 14
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_1 83
# define KEY_2 84
# define KEY_4 86
# define KEY_5 87
# define KEY_7 89
# define KEY_8 91
# define KEY_PLUS 69
# define KEY_MINUS 78

typedef struct s_params			t_params;
typedef struct s_img			t_img;
typedef struct s_data			t_data;
typedef struct s_vector_2f		t_vector2_f;
typedef struct s_map			t_map;
typedef struct s_render			t_render;
typedef struct s_vector			t_vector2_d;
typedef struct s_col			t_col;
typedef struct s_parse_params	t_parse_params;
typedef enum e_bool				t_bool;

enum e_bool
{
	false,
	true
};

// Si type = 0 : coordon??ees
// Si type = 1 : couleurs
struct s_params
{
	int				type;
	char			*coord;
	char			*path;
	char			*color;
	char			**rgb;
	int				hexa_rgb;
	int				stop;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		precompute_bits_p_px;
	int		size_line;
	int		endian;
	int		height;
	int		width;
};

struct s_data
{
	t_params		*params;
	t_map			*maps;
	t_render		*render;
	t_col			*col;
	char			*map_line;
	int				keytab[200];
	int				ceil_color;
	int				floor_color;
	int				initialized;
	t_track			*track;

	t_img			east;
	t_img			west;
	t_img			north;
	t_img			south;
};

struct s_parse_params
{
	int		count;
	int		k;
	int		i;
	char	**params;
	char	**file;
};

struct s_vector_2f
{
	double		x;
	double		y;
};

struct s_map
{
	char	**map;
	int		longest_line;
	int		height;
};

struct s_render {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			precompute_bits_p_px;
	int			nbr_px;
	int			line_length;
	int			endian;
	int			angle;
	int			cell_size;
	void		*walls;
	int			width;
	int			height;

	t_vector2_f	dir;
	t_vector2_f	plane;
	t_vector2_f	origin;
};

struct s_col {
	double	delta;
	double	rayDirX;
	double	rayDirY;
	double	deltadistx;
	double	deltadisty;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		mapX;
	int		mapY;
	double	sidedistx;
	double	sidedisty;
	int		drawStart;
	int		drawEnd;
	double	perpwalldist;
	int		lineheight;
	int		sizeWall;
	int		h;
};

char			*_get_file(t_data *data, int fd);
t_bool			parse_map_params(t_data *data, char *filename);
t_bool			check_coordinate_param(char *param, int *i);
t_bool			check_color_param(char *param, int *i);

char			**get_cub_file(t_data *data, char *filename);
char			*_get_file(t_data *data, int fd);
t_bool			check_coordinate_param(char *param, int *i);
t_bool			check_color_param(char *param, int *i);

int				draw_player_1(t_data *data);
unsigned long	create_rgb(t_data *data);
int				ft_atoi_base(char *str, char *base);
char			*ft_convert_base(t_data *data,
					char *nbr, char *base_from, char *base_to);
int				init_imgs(t_data *data);
int				open_file(char *filename);
char			*get_map_from_file(t_data *data, char *filename);
int				exit_program(t_data *data);
void			fill_params(t_data *data, char **params);
int				skip_space_params(char *param);
t_bool			check_param(char *param);
int				params_find_type(char *param);
char			*dec_to_hex_converter(t_data *data, unsigned long n, int caps);

/*********PARSING_MAP*************/

int				init_parsing_map(t_data *data,
					t_map *map, t_render	*render, char *argv);
int				get_longest_line(char *line);
int				is_map(char c);
char			*clear_endmap(char	*line);
int				count_nl(char *line);
void			print_map(char **map);
t_bool			is_charmap(char c);
t_bool			is_one_player(char	*map);
int				get_x_player(t_data *data);
int				get_y_player(t_data *data);
void			str_to_map(t_data *data, int fd, char *tmp, int i);
t_bool			check_charmap(char *line);
t_bool			is_not_wall(char c);
t_bool			col_checker(t_data *data, char **map, char *str);
char			get_first_char_x(char *line);
t_bool			check_cub(char *file);

/*********INIT_PARSING_MAP*************/
int				init_parsing_map(t_data *data,
					t_map *map, t_render *render, char *argv);

/*********IMAGE_HANDLER.C*************/
char			*get_path_imgs(t_data *data, char *orientation);
void			init_img(t_data *data, t_img *img, char *orientation);
int				init_imgs(t_data *data);
void			clear_img(t_data *data);

/*********KEY_HANDLER.C*************/
int				deal_key(int key, t_data *data);
int				key_release(int key, t_data *data);
void			player_input(t_data *data);

/************UTILS****************/
int				contains_digit(char *str);
int				len_2d_array(char **arr);
void			free_2d_array(char **array);
t_bool			is_valid_map(char **map);
char			*map_to_line(char **arr);
int				exit_program_from_escape(t_data *data);

/************RENDER****************/
void			render_wall(t_data *data, t_col *col, int x);
void			clear_img(t_data *data);
void			render_line(t_data *data, int x, t_img *img, t_col *col);

/************ROTATE_PLAYER.C****************/
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);

/************DDA****************/
int				dda(t_data *data, int i);

/************INIT_MLX****************/
void			init_mlx(t_data *data);

/************UTILS****************/

int				contains_digit(char *str);
int				len_2d_array(char **arr);
void			free_2d_array(char **array);
void			free_param_struct(t_data *data);
t_bool			row_checker(char *str);
char			*map_to_line(char **arr);
void 			my_mlx_pixel_put(t_render *render, int x, int y, int color);
double			get_angle(t_vector2_d start, t_vector2_d end);
void			free_arr_from_end(t_data *data, char **arr, int i);

/************ORIENTATION_CHECKER****************/
void			orientation_checker_we_ea(t_data *data, int x, t_col *col);
void			orientation_checker_no_so(t_data *data, int x, t_col *col);
void			render_wall(t_data *data, t_col *col, int x);

/************MOVE.C****************/
int				move_left(t_data *data);
int				move_right(t_data *data);
int				move_up(t_data *data);
int				move_down(t_data *data);

/************CONVERT_VECT.C****************/
t_vector2_f		vect_d_to_f(t_vector2_d vect);
t_vector2_d		vect_f_to_d(t_vector2_f vect);

/************INIT_STRUCT_RENDERING.C****************/
void			init_data(t_data *data);

/************UTILS_MATH.C****************/
float			ft_abs(float number);
void			draw_circle(t_data *data, t_vector2_d center, int color);
t_vector2_f		add_vect(t_vector2_f start, t_vector2_f end);
t_vector2_f		sub_vect(t_vector2_f start, t_vector2_f end);

/************EVENTS****************/
int				update(t_data *data);
int				key_release(int key, t_data *data);
int				deal_key(int key, t_data *data);

#endif
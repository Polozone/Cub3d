/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:42:34 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/06 14:55:58 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct  s_char t_char;
typedef struct  s_mlx_data t_mlx_data;

struct  t_char
{
	int		px;
	int		py;
};

struct  s_mlx_data
{
	void            *mlx_win;
	void            *mlx_ptr;
	char            **matrix;
	int				init;
	struct t_char   char_pos;
};


// INIT
void	init_mlx(t_mlx_data *data);

// DRAW
void    draw_map(t_mlx_data *data);

// TESTS
char    **init_matrix_test(char **matrix);

#endif
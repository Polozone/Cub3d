# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 11:52:14 by tdeville          #+#    #+#              #
#    Updated: 2022/10/21 11:00:41 by pmulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
HEADER	= includes/cub3d.h \
			mlx/mlx.h \
			mlx/mlx_new_window.h \
			mlx/mlx_int.h \
			mlx/mlx_opengl.h \
			mlx/mlx_png.h \
			libft/libft.h

LIBFT	= Libft
MLX		= mlx
INCLUDES= ${addprefix -I, ${sort ${dir ${HEADER}}}}

SRCS	=	main.c src/parsing/get_cub_file.c src/parsing/parse_map_params.c \
			src/parsing/parsing_map.c \
			src/parsing/utils_parsing_map.c \
			src/parsing/check_colors_params.c \
			src/parsing/check_coordinate_params.c \
			src/utils/free_utils.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBFLAGS= -framework OpenGL -framework AppKit

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${INCLUDES} -c $< -o $@


${NAME}: ${OBJS} libft/libft.a mlx/libmlx.a
		${CC} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a mlx/libmlx.a

maker:
		${MAKE} -C ${LIBFT}
		${MAKE}	-C ${MLX}

clean:
		rm -f ${OBJS}
		${MAKE} clean -C ${LIBFT}
		${MAKE} clean -C ${MLX}

fclean:	clean
		rm -f ${NAME}
		${MAKE} fclean -C ${LIBFT}
		${MAKE} clean -C ${MLX}

re:		fclean all

.PHONY: all clean fclean re maker
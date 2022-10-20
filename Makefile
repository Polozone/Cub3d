# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 11:52:14 by tdeville          #+#    #+#              #
#    Updated: 2022/10/06 13:41:19 by tdeville         ###   ########lyon.fr    #
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

SRCS	=	main.c src/init_mlx.c src/tests.c \
			src/draws.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LIBFLAGS= -framework OpenGL -framework AppKit

all: maker ${NAME}

%.o : %.c	${HEADER}
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


${NAME}: ${OBJS} libft/libft.a mlx/libmlx.a
		${CC} ${CFLAGS} ${OBJS} ${LIBFLAGS} ${INCLUDES} -o $@ Libft/libft.a mlx/libmlx.a

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
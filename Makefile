# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 11:52:14 by tdeville          #+#    #+#              #
#    Updated: 2022/11/23 12:43:28 by pmulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
END		:=	\033[0m

NAME		:= cub3D

CC			:= cc

# CFLAGS		:= -Wall -Werror -Wextra -I mlx
CFLAGS		:= -I mlx

RM			:=	rm -f

LIBFT_DIR	:= Libft

MLX_DIR		:= mlx

INCS_DIR	:= includes

SRCS_DIR	:= src

OBJS_DIR	:= .objs

INCS_LST	:= 	cub3d.h \
				../mlx/mlx.h \
				../mlx/mlx_new_window.h \
				../mlx/mlx_int.h \
				../mlx/mlx_opengl.h \
				../mlx/mlx_png.h \

SRCS_LST		:=	main/main.c \
					parsing/get_cub_file.c \
					parsing/parse_map_params.c \
					parsing/get_cub_file2.c \
					parsing/parsing_map.c \
					parsing/check_colors_params.c \
					parsing/check_coordinate_params.c \
					parsing/row_col_checker.c \
					parsing/row_col_checker2.c \
					parsing/check_player.c \
					parsing/ft_convert_base.c \
					parsing/ft_convert_base2.c \
					parsing/check_params.c \
					parsing/get_params.c \
					parsing/init_parsing_map.c \
					utils/utils_parsing_map.c \
					utils/utils_parsing2.c \
					utils/free_utils.c \
					utils/string_utils.c \
					utils/open_utils.c \
					rendering/init_map.c \
					rendering/move.c \
					rendering/rotate_player.c \
					rendering/init_struct_rendering.c \
					rendering/pixelput.c \
					rendering/utils_math.c \
					rendering/get_collision.c \
					rendering/rendering.c \
					rendering/orientation_checker.c \
					rendering/image_handler.c \
					rendering/key_handler.c \

SUBDIR_LST	:=	main	\
				parsing \
				utils	\
				rendering	\

OBJS_LST	:= ${SRCS_LST:.c=.o}

LIBFT_AR	:= $(LIBFT_DIR)/libft.a

MLX_AR		:= $(MLX_DIR)/libmlx.a

INCS		:=	$(addprefix $(INCS_DIR)/, $(INCS_LST))

SRCS		:=	$(addprefix $(SRCS_DIR)/, $(SRCS_LST))

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

LIBFLAGS	:= -framework OpenGL -framework AppKit

# .SILENT:

all: libft mlx ${NAME}

libft:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR)

${NAME}: ${OBJS} ${LIBFT_AR} ${MLX_AR}
			${CC} ${OBJS} ${LIBFT_AR} ${MLX_AR} ${LIBFLAGS} -o $@ 

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIR_LST))

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c ${INCS} Makefile | ${OBJS_DIR}
		${CC} ${CFLAGS} -I ${INCS_DIR} -c $< -o $@

clean:
		${MAKE} clean -C ${LIBFT_DIR}
		${MAKE} clean -C ${MLX_DIR}
		${RM} ${OBJS}
		rm -rf ${OBJS_DIR}

fclean:	clean
		${RM} ${LIBFT_AR}
		${RM} ${MLX_AR}
		${RM} ${NAME}

re:		fclean all

.PHONY: all libft mlx clean fclean re 
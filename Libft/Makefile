# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 13:51:24 by tdeville          #+#    #+#              #
#    Updated: 2022/11/23 13:26:42 by tdeville         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

HEADER	=	libft.h		\
			
SRCS	= ft_strlen.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isalpha.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_strcmp.c \
		ft_gc/gc_add_mal.c			\
		ft_gc/gc_lstadd_front.c		\
		ft_gc/gc_lstdelone.c		\
		ft_gc/gc_lstnew.c			\
		ft_gc/gc_free_all.c			\
		ft_gc/gc_free_malloc.c		\
		ft_gc/gc_free_malloc_split.c\
		gc_split.c \
		gc_strjoin.c \
		gc_substr.c \
		gc_strtrim.c \
		gc_strdup.c \
		gc_calloc.c \
		gc_get_next_line.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

# SRCS_B =	ft_lstnew.c \
# 			ft_lstadd_front.c \
# 			ft_lstsize.c \
# 			ft_lstlast.c \
# 			ft_lstadd_back.c \
# 			ft_lstdelone.c \
# 			ft_lstclear.c \
# 			ft_lstiter.c \
# 			ft_lstmap.c \

OBJS	= ${SRCS:.c=.o}
# OBJS_B	= ${SRCS_B:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

# all: ${NAME} bonus
all: ${NAME}

%.o : %.c	${HEADER} Makefile 
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

# bonus:	${OBJS} ${OBJS_B}
# 	ar rcs ${NAME} ${OBJS} ${OBJS_B}


clean:
	rm -f ${OBJS} ${OBJS_B}

fclean:	clean
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re

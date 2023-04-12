# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 09:38:29 by jihoon            #+#    #+#              #
#    Updated: 2021/04/16 17:55:43 by jihoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c	ft_vprintf.c	ft_asprintf.c	\
			  srcs_internal/ft_vasprintf_internal.c			\
			  srcs_internal/conversion_handler_cs.c			\
			  srcs_internal/conversion_handler_flt.c		\
			  srcs_internal/conversion_handler_int.c		\
			  srcs_internal/conversion_handler_np.c			\
			  srcs_internal/conversion_handler_uint.c		\
			  srcs_internal/format_conversion_arrange.c		\
			  srcs_internal/format_conversion_handler.c		\
			  srcs_internal/format_conversion_parse.c		\
			  srcs_internal/format_conversion_utils.c		\
			  srcs_internal/format_string_handler.c


OBJS		= ${SRCS:.c=.o}

INCS		= headers/

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LIBC		= ar -rcs

NAME		= libft.a

LIBFT		= libft.a

LIBFT_SRC	= libft/

RM			= rm -f

.c.o	:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

all	: ${NAME}

${NAME} : ${OBJS}
	make -C ${LIBFT_SRC}
	cp ${LIBFT_SRC}${LIBFT} ${NAME}
	${LIBC} ${NAME} ${OBJS}

clean	:
	${RM} ${OBJS}
	make clean -C ${LIBFT_SRC}

fclean	: clean
	${RM} ${NAME}
	make fclean -C ${LIBFT_SRC}

re		: fclean all

bonus	: all

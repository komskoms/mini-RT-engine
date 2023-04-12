# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 01:28:09 by jihokim           #+#    #+#              #
#    Updated: 2020/11/07 16:17:05 by jihokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
	 	  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit_isalnum.c \
		  ft_isascii_isprint.c \
		  ft_toupper_tolower.c \
		  ft_calloc.c \
		  ft_strdup_strndup.c \
		  ft_substr_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putbundle_fd.c

OBJS	= ${SRCS:.c=.o}

INCS	= ./

NAME	= libft.a

CC	= gcc

LIBC	= ar -rcs

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

all		: ${NAME}

.c.o	:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}	: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

clean	:
	${RM} ${OBJS}

fclean	: clean
	${RM} ${NAME}

re	: fclean all

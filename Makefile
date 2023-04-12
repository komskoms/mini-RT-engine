# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihokim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 13:02:05 by jihokim           #+#    #+#              #
#    Updated: 2021/04/21 20:22:37 by jihokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S		:= $(shell uname -s)
SRCS		= ${addprefix ${SRCPATH}, ${SRCFILES}}
SRCPATH		= source/
SRCFILES	= main.c messages.c key_handle.c bmpsave.c debug00.c	\
			  control_prescene.c control_terminate.c cam_manage.c	\
			  get_next_line.c rtfile_check00.c rtfile_check01.c	\
			  rtfile_read.c rtfile_parse00.c rtfile_parse01.c rtfile_parse02.c	\
			  var_manage00.c var_manage01.c ray_tracer.c ray_manage.c 	\
			  object_manage.c object_sphere.c object_plane.c object_square.c	\
			  object_triangle.c object_cylinder00.c object_cylinder01.c	\
			  object_material_manage.c object_material.c object_background.c	\
			  vec3_manage.c vec3_calc00.c vec3_calc01.c	vec3_calc02.c \
			  vec3_calc03.c vec3_calc_ray.c	\
			  util_string00.c util_string01.c util_string_gnl.c	\
			  util_color.c util_texture.c util_others.c util_rand.c util_parse.c
OBJS		= ${SRCS:.c=.o}
OBJPATH		= temp_build/
INCS		= include/
LIBFTPATH	= libft/
LIBFT		= libft/libft.a
MLXPATH		= mlx/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra #-g -fsanitize=address
ifeq ($(UNAME_S),Linux)
GUIFLAGS	= -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S),Darwin)
GUIFLAGS	= -framework openGL -framework Appkit
endif

NAME		= minirt

all		: ${NAME}

%.o		: %.c
		  ${CC} ${CFLAGS} -I${INCS} -I${MLXPATH} -c -o			\
		  $@ $<

${NAME}	: ${OBJS}
ifeq ($(UNAME_S),Darwin)
			make -C ${MLXPATH}
			cp ${MLXPATH}libmlx.dylib ./
endif
		  make -C ${LIBFTPATH}
		  ${CC} ${CFLAGS} -L${MLXPATH} -o $@ ${OBJS} ${LIBFT}	\
		  -lmlx ${GUIFLAGS}

clean	:
		  make clean -C ${LIBFTPATH}
		  make clean -C ${MLXPATH}
		  rm -rf ${OBJS}

fclean	: clean
		  make fclean -C ${LIBFTPATH}
		  rm ${NAME} libmlx.dylib

re		: clean all

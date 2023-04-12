/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_string.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:40:40 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/25 02:42:15 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_STRING_H
# define UTIL_STRING_H

# include "vector3.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 100
# endif

int			exit_with_msg(char *msg, int ret);
int			next_index(char *line, int last_idx);
int			get_next_line(char **line, int fd);
int			rt_get_next_line(char **line, int fd);
int			is_blank(char ch);
double		my_atod(char *str);
int			my_atoi(char *str);
t_vec		*str_to_vec3(t_vec ret[3], char *str);
void		my_itoa8(char ret[9], int num);

#endif

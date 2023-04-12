/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:33:01 by jihokim           #+#    #+#             */
/*   Updated: 2020/11/02 13:13:31 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GNL_ERR -1
# define GNL_EOF 0
# define GNL_NL 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stddef.h>

typedef struct		s_cache
{
	int			initialized;
	char		*stored_line;
	size_t		line_size;
	char		buffer[BUFFER_SIZE];
	int			bytes;
	size_t		offset;
	int			overrun;
	int			end;
}					t_cache;

void				*ft_memcpy(void *dest, const void *src, size_t count);
int					get_next_line(int fd, char **line);

#endif

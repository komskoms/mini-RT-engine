/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:35:07 by jihokim           #+#    #+#             */
/*   Updated: 2020/11/02 20:13:21 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

static int		cache_initialize(t_cache *cache, int fd, int code, int ret)
{
	if (code == 0)
	{
		cache->initialized = 1;
		cache->stored_line = NULL;
		cache->line_size = 0;
		cache->offset = BUFFER_SIZE;
	}
	else if (code == 1)
	{
		cache->offset = 0;
		cache->overrun = (cache->bytes == BUFFER_SIZE) ? 1 : 0;
	}
	else if (code == 2)
	{
		if (cache->end == -1)
			return (cache_initialize(cache, fd, 0, GNL_EOF));
		cache->line_size = 0;
		cache->end = 0;
		if (fd == 0)
			cache->offset = BUFFER_SIZE;
	}
	else if (code == 3)
		cache->line_size = 0;
	return (ret);
}

static int		gnl_store(t_cache *cache, size_t len)
{
	char	*tmp;

	if (!(tmp = malloc(sizeof(char) * (cache->line_size + len + 1))))
		return (0);
	tmp[cache->line_size + len] = '\0';
	if (cache->line_size)
	{
		ft_memcpy(tmp, cache->stored_line, cache->line_size);
		ft_memcpy(tmp + cache->line_size, cache->buffer + cache->offset, len);
		free(cache->stored_line);
	}
	else
		ft_memcpy(tmp, cache->buffer + cache->offset, len);
	cache->stored_line = tmp;
	cache->line_size += len;
	cache->offset += (len + 1);
	return (1);
}

static int		gnl_buffer_handler(t_cache *cache, char **line)
{
	int		idx;

	idx = cache->offset;
	while (idx < BUFFER_SIZE)
	{
		if (cache->buffer[idx] == '\n' && idx < cache->bytes)
		{
			cache->end = 1;
			break ;
		}
		if (idx == cache->bytes && cache->overrun == 0)
		{
			cache->end = -1;
			break ;
		}
		idx++;
	}
	if (!(gnl_store(cache, idx - cache->offset)))
		return (-1);
	if (cache->end != 0)
	{
		*line = cache->stored_line;
		return (cache_initialize(cache, 0, 3, 1));
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_cache	initial_cache[OPEN_MAX];
	t_cache			*cache;
	int				flag;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (GNL_ERR);
	*line = NULL;
	cache = initial_cache + fd;
	if (cache->initialized == 0)
		cache_initialize(cache, fd, 0, 0);
	while (1)
	{
		if (cache->offset >= BUFFER_SIZE)
		{
			if ((cache->bytes = read(fd, cache->buffer, BUFFER_SIZE)) < 0)
				return (GNL_ERR);
			cache_initialize(cache, fd, 1, 0);
		}
		if ((flag = gnl_buffer_handler(cache, line)) == -1)
			return (GNL_ERR);
		if (flag)
			return (cache_initialize(cache, fd, 2, GNL_NL));
	}
}

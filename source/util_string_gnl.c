/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_string_gnl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:11:09 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 23:01:46 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_string.h"

static int	where_nl(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	join_line(char **line, char *buf)
{
	char	*new;
	int		len_line;
	int		len_buf;
	int		i;

	if (!*line)
		len_line = 0;
	else
		len_line = ft_strlen(*line);
	len_buf = ft_strlen(buf);
	if (!(new = malloc(sizeof(char) * (len_line + len_buf + 1))))
		return (0);
	i = -1;
	while (++i < len_line)
		new[i] = (*line)[i];
	while (i < len_line + len_buf)
	{
		new[i] = buf[i - len_line];
		i++;
	}
	new[i] = 0;
	free(*line);
	*line = new;
	return (1);
}

static void	holder_reset(char *holder, int start_idx)
{
	char	tmp[GNL_BUFFER_SIZE];
	int		len;
	int		i;

	len = ft_strlen(holder);
	i = 0;
	while (i < len - start_idx)
	{
		tmp[i] = holder[start_idx + i];
		i++;
	}
	tmp[i++] = 0;
	while (i--)
		holder[i] = tmp[i];
}

static int	process_line(char **line, char *holder, int newline)
{
	char	tmp[GNL_BUFFER_SIZE];
	int		nl_ignore;

	nl_ignore = 0;
	if (newline > 0 && holder[newline - 1] == '\\')
		nl_ignore = 1;
	ft_strlcpy(tmp, holder, newline - nl_ignore + 1);
	if (!join_line(line, tmp))
		return (0);
	holder_reset(holder, newline + 1);
	if (nl_ignore)
		return (2);
	return (1);
}

int			rt_get_next_line(char **line, int fd)
{
	static char		holder[GNL_BUFFER_SIZE];
	int				chk;
	int				newline_idx;

	while (1)
	{
		if (!*holder)
		{
			chk = read(fd, holder, GNL_BUFFER_SIZE - 1);
			holder[chk] = '\0';
			if (chk <= 0)
				return (chk);
		}
		newline_idx = where_nl(holder);
		if (newline_idx == -1)
		{
			join_line(line, holder);
			holder_reset(holder, GNL_BUFFER_SIZE);
			continue ;
		}
		else if (process_line(line, holder, newline_idx) == 2)
			continue ;
		return (1);
	}
}

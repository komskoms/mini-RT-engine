/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:52:10 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 23:01:35 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtfile.h"
#include "variables.h"
#include "util_package.h"
#include "scene_control.h"
#include <stdio.h>

static int	file_readin(int fd, t_vars *v_)
{
	int		read_status;
	int		parse_done;
	char	*line;

	line = 0;
	while (1)
	{
		read_status = rt_get_next_line(&line, fd);
		if (read_status == -1)
			return (0);
		parse_done = parse_line__(v_, line);
		if (parse_done == -1)
		{
			free(line);
			return (0);
		}
		if (!read_status && !parse_done)
			return (1);
		free(line);
		line = 0;
	}
}

int			rtfile_read(char *pathname, t_vars *v_)
{
	int				fd;

	v_->filepath = pathname;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		perror("rtfile open failure");
		exit(0);
	}
	if (!file_readin(fd, v_))
	{
		perror("rtfile read failure");
		exit(0);
	}
	close(fd);
	printf("The scene file(%s) has been read sucessfully.\n", pathname);
	return (1);
}

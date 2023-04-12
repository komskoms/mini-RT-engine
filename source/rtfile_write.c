/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:33:21 by jihoon            #+#    #+#             */
/*   Updated: 2021/04/16 15:33:22 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			rtfile_write(t_vars *v_, char *filename)
{
	char	*rt_line;
	int		fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	write(fd, 0, 0);
	return (1);
}

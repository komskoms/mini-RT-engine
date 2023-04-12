/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:14:02 by jihoon            #+#    #+#             */
/*   Updated: 2021/04/21 21:14:04 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtfile.h"

int			format_check_vec3(char *line)
{
	int		count;

	count = 0;
	while (*line && !is_blank(*line))
	{
		if (*line++ == ',')
			count++;
	}
	if (count == 2)
		return (1);
	return (0);
}

int			format_check_resolution(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int			format_check_anbience(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int			format_check_camera(char *line)
{
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

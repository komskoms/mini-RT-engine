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

int				format_check_sphere(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int				format_check_plane(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int				format_check_square(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int				format_check_triangle(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

int				format_check_cylinder(char *line)
{
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (!format_check_vec3(line))
		return (0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	line += next_index(line, 0);
	if (*line)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 23:18:46 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/10 18:09:22 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtfile.h"
#include "object_manage.h"
#include "variables.h"

int			type_detector(char *line)
{
	if (*line == 's' && *(line + 1) == 'p')
		return (OBJ_SPHERE);
	if (*line == 'p' && *(line + 1) == 'l')
		return (OBJ_PLANE);
	if (*line == 's' && *(line + 1) == 'q')
		return (OBJ_SQUARE);
	if (*line == 't' && *(line + 1) == 'r')
		return (OBJ_TRIANGLE);
	if (*line == 'c' && *(line + 1) == 'y')
		return (OBJ_CYLINDER);
	return (0);
}

int			mat_type_selector(int ch)
{
	if (ch == 'n')
		return (OBJ_NORMAL);
	if (ch == 'm')
		return (OBJ_METAL);
	if (ch == 'g')
		return (OBJ_GLASS);
	if (ch == 'l')
		return (OBJ_LIGHT);
	return (0);
}

int			parse_line(t_obj_list **list, char *line)
{
	if (type_detector(line) == OBJ_SPHERE)
		return (read_as_sphere(list, line));
	if (type_detector(line) == OBJ_PLANE)
		return (read_as_plane(list, line));
	if (type_detector(line) == OBJ_SQUARE)
		return (read_as_square(list, line));
	if (type_detector(line) == OBJ_TRIANGLE)
		return (read_as_triangle(list, line));
	if (type_detector(line) == OBJ_CYLINDER)
		return (read_as_cylinder(list, line));
	return (0);
}

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

int			read_as_sphere(t_obj_list **list_, char *line)
{
	t_parse_var		vars;
	void			*tmp_sphr;
	t_material		mat_;

	if (!format_check_sphere(line))
		return (-1);
	vars.type = OBJ_SPHERE;
	line += next_index(line, 0);
	line += readnmove_str(vars.name, line);
	line += readnmove_vec3(vars.coordinate, line);
	line += readnmove_double(&vars.radius, line);
	line += readnmove_int(&vars.texture, line);
	line += readnmove_vec3(vars.color, line);
	vars.mat_type = mat_type_selector(*line);
	line += next_index(line, 0);
	vars.mat_fuzz = my_atod(line);
	if (!(tmp_sphr = create_sphere(vars.coordinate, vars.radius)))
		return (0);
	material_set(&mat_, vars);
	object_list_add(list_, vars, tmp_sphr, &mat_);
	return (1);
}

int			read_as_plane(t_obj_list **list_, char *line)
{
	t_parse_var		vars;
	void			*tmp_obj;
	t_material		mat_;

	if (!format_check_plane(line))
		return (-1);
	vars.type = OBJ_PLANE;
	line += next_index(line, 0);
	line += readnmove_str(vars.name, line);
	line += readnmove_vec3(vars.coordinate, line);
	line += readnmove_vec3(vars.coordinate_1, line);
	line += readnmove_int(&vars.texture, line);
	line += readnmove_vec3(vars.color, line);
	vars.mat_type = mat_type_selector(*line);
	line += next_index(line, 0);
	vars.mat_fuzz = my_atod(line);
	if (!(tmp_obj = create_plane(vars.coordinate, vars.coordinate_1)))
		return (0);
	material_set(&mat_, vars);
	object_list_add(list_, vars, tmp_obj, &mat_);
	return (1);
}

int			read_as_square(t_obj_list **list_, char *line)
{
	t_parse_var		vars;
	void			*tmp_obj;
	t_material		mat_;

	if (!format_check_square(line))
		return (-1);
	vars.type = OBJ_SQUARE;
	line += next_index(line, 0);
	line += readnmove_str(vars.name, line);
	line += readnmove_vec3(vars.coordinate, line);
	line += readnmove_vec3(vars.coordinate_1, line);
	line += readnmove_double(&vars.length, line);
	line += readnmove_int(&vars.texture, line);
	line += readnmove_vec3(vars.color, line);
	vars.mat_type = mat_type_selector(*line);
	line += next_index(line, 0);
	vars.mat_fuzz = my_atod(line);
	if (!(tmp_obj =
		create_square(vars.coordinate, vars.coordinate_1, vars.length)))
		return (0);
	material_set(&mat_, vars);
	object_list_add(list_, vars, tmp_obj, &mat_);
	return (1);
}

int			read_as_triangle(t_obj_list **list_, char *line)
{
	t_parse_var		vars;
	void			*tmp_obj;
	t_material		mat_;

	if (!format_check_triangle(line))
		return (-1);
	vars.type = OBJ_TRIANGLE;
	line += next_index(line, 0);
	line += readnmove_str(vars.name, line);
	line += readnmove_vec3(vars.coordinate, line);
	line += readnmove_vec3(vars.coordinate_1, line);
	line += readnmove_vec3(vars.coordinate_2, line);
	line += readnmove_int(&vars.texture, line);
	line += readnmove_vec3(vars.color, line);
	vars.mat_type = mat_type_selector(*line);
	line += next_index(line, 0);
	vars.mat_fuzz = my_atod(line);
	if (!(tmp_obj =
		create_triangle(vars.coordinate, vars.coordinate_1, vars.coordinate_2)))
		return (0);
	material_set(&mat_, vars);
	object_list_add(list_, vars, tmp_obj, &mat_);
	return (1);
}

int			read_as_cylinder(t_obj_list **list_, char *line)
{
	t_parse_var		vars;
	void			*tmp_obj;
	t_material		mat_;

	if (!format_check_cylinder(line))
		return (-1);
	vars.type = OBJ_CYLINDER;
	line += next_index(line, 0);
	line += readnmove_str(vars.name, line);
	line += readnmove_vec3(vars.coordinate, line);
	line += readnmove_vec3(vars.coordinate_1, line);
	line += readnmove_double(&vars.radius, line);
	line += readnmove_double(&vars.length, line);
	line += readnmove_int(&vars.texture, line);
	line += readnmove_vec3(vars.color, line);
	vars.mat_type = mat_type_selector(*line);
	line += next_index(line, 0);
	vars.mat_fuzz = my_atod(line);
	if (!(tmp_obj = create_cylinder(
			vars.coordinate, vars.coordinate_1, vars.radius, vars.length)))
		return (0);
	material_set(&mat_, vars);
	object_list_add(list_, vars, tmp_obj, &mat_);
	return (1);
}

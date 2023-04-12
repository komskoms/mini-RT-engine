/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:10:45 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/25 02:45:25 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTFILE_H
# define RTFILE_H

# include "variables.h"
# include "vector3.h"
# include "util_string.h"

int				rtfile_read(char *pathname, t_vars *v_);
int				parse_line__(t_vars *v_, char *line);
int				parse_line(t_obj_list **head, char *line);
int				readnmove_vec3(t_vec store[3], char *line);
int				readnmove_double(double *store, char *line);
int				readnmove_int(int *store, char *line);
int				readnmove_str(char *store, char *line);
int				mat_type_selector(int ch);
int				read_as_sphere(t_obj_list **list_, char *line);
int				read_as_plane(t_obj_list **list_, char *line);
int				read_as_square(t_obj_list **list_, char *line);
int				read_as_triangle(t_obj_list **list_, char *line);
int				read_as_cylinder(t_obj_list **list_, char *line);
/*
**	the simplest format checker for .rt
*/
int				format_check_vec3(char *line);
int				format_check_resolution(char *line);
int				format_check_anbience(char *line);
int				format_check_camera(char *line);
int				format_check_sphere(char *line);
int				format_check_plane(char *line);
int				format_check_square(char *line);
int				format_check_triangle(char *line);
int				format_check_cylinder(char *line);

#endif

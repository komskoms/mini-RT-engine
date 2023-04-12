/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:52:38 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/15 06:11:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_MANAGE_H
# define OBJECT_MANAGE_H

# define OBJ_SPHERE 1
# define OBJ_PLANE 2
# define OBJ_SQUARE 3
# define OBJ_CYLINDER 4
# define OBJ_TRIANGLE 5

# define OBJ_NORMAL 1
# define OBJ_METAL 2
# define OBJ_GLASS 3
# define OBJ_LIGHT 4

# include "vector3.h"
# include "util_package.h"

typedef struct			s_parse_var
{
	int					type;
	char				name[80];
	t_vec				coordinate[3];
	t_vec				coordinate_1[3];
	t_vec				coordinate_2[3];
	t_vec				normal_v[3];
	double				radius;
	double				length;
	int					texture;
	int					color_int[4];
	t_vec				color[3];
	int					mat_type;
	double				mat_fuzz;
}						t_parse_var;

typedef struct			s_obj_plane
{
	t_vec				center[3];
	t_vec				norm[3];
}						t_obj_plane;

typedef struct			s_obj_sphere
{
	t_vec				center[3];
	double				radius;
}						t_obj_sphere;

typedef struct			s_obj_square
{
	t_vec				center[3];
	t_vec				norm[3];
	double				length;
	t_vec				point_a[3];
	t_vec				point_b[3];
	t_vec				point_c[3];
	t_vec				point_d[3];
	t_vec				side_ab[3];
	t_vec				side_ac[3];
	double				product[2];
}						t_obj_square;

typedef struct			s_obj_triangle
{
	t_vec				point0[3];
	t_vec				point1[3];
	t_vec				point2[3];
	t_vec				norm[3];
	t_vec				side_u[3];
	t_vec				side_v[3];
	double				dot_uu;
	double				dot_uv;
	double				dot_vv;
	double				product;
}						t_obj_triangle;

typedef struct			s_obj_cylinder
{
	t_vec				center[3];
	t_vec				norm[3];
	double				radius;
	double				height;
	t_vec				center_top[3];
	t_vec				center_bot[3];
	t_vec				h_vec[3];
	double				comp_[9];
}						t_obj_cylinder;

typedef	struct			s_material
{
	int					type;
	int					texture;
	t_vec				color[3];
	double				fuzz;
}						t_material;

typedef struct			s_obj_list
{
	void				*obj;
	char				name[80];
	int					type;
	t_material			material;
	struct s_obj_list	*next;
}						t_obj_list;

int						object_list_add(
						t_obj_list **head, t_parse_var vars,
										void *obj, t_material *mat);
void					object_list_clear(t_obj_list *head);
t_material				*material_set(t_material *mat, t_parse_var vars);
void					material_cpy(t_material *dst, t_material src);
t_obj_sphere			*create_sphere(t_vec center[3], double radius);
t_obj_plane				*create_plane(t_vec center[3], t_vec norm[3]);
t_obj_square			*create_square(t_vec cen[3], t_vec norm[3], double len);
t_obj_triangle			*create_triangle(t_vec p0[3], t_vec p1[3], t_vec p2[3]);
t_obj_cylinder			*create_cylinder(
						t_vec cen[3], t_vec norm[3], double rad, double hg);
/*
** debugging functions
*/
void					print_material(t_obj_list *head, char *name);
void					print_material_all(t_obj_list *head);

#endif

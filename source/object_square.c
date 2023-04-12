/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 00:42:53 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 03:37:13 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object_manage.h"
#include "vector3.h"
#include "raytracer.h"

t_obj_square	*create_square(t_vec center[3], t_vec norm[3], double len)
{
	t_obj_square	*new;
	t_vec			q_[4][3];

	if (!(new = malloc(sizeof(t_obj_square))))
		return (0);
	vec3_cpy(new->center, center);
	vec3_cpy(new->norm, norm);
	new->length = len;
	vec3_calc_unit(q_[0], vec3_calc_coef(q_[1], norm, -1));
	vec3_calc_unit(q_[1], vec3_calc_crs(q_[1],
				vec3_put(q_[1], 0, 1, 0), q_[0]));
	vec3_calc_crs(q_[2], q_[0], q_[1]);
	vec3_calc_coef(new->side_ab, q_[1], len);
	vec3_calc_coef(new->side_ac, q_[2], len);
	vec3_calc_add(q_[0], q_[1], q_[2]);
	vec3_calc_coef(q_[0], q_[0], len / 2);
	vec3_calc_sub(new->point_a, center, q_[0]);
	vec3_calc_add(new->point_b, new->point_a, new->side_ab);
	vec3_calc_add(new->point_c, new->point_a, new->side_ac);
	vec3_calc_add(new->point_d, center, q_[0]);
	new->product[0] = vec3_calc_dot(new->side_ab, new->side_ab);
	new->product[1] = vec3_calc_dot(new->side_ac, new->side_ac);
	return (new);
}

static void		trace_set_face(t_trace *trace, t_ray ray)
{
	trace->face = vec3_calc_dot(ray.dir, trace->norm) < 0;
	if (!trace->face)
		vec3_calc_coef(trace->norm, trace->norm, -1);
}

int				hit_square(t_obj_square *object, t_ray ray, t_trace *trace)
{
	t_vec	q_[5][3];
	t_vec	tmp[3];
	double	d_[4];

	d_[0] = vec3_calc_dot(ray.ori, object->norm) -
			vec3_calc_dot(object->norm, object->center);
	d_[1] = vec3_calc_dot(ray.dir, object->norm);
	d_[0] = -d_[0] / d_[1];
	if (d_[0] < ray.min || d_[0] > ray.max || d_[0] != d_[0])
		return (0);
	ray_point(tmp, ray, d_[0]);
	vec3_calc_sub(q_[0], tmp, object->point_a);
	d_[0] = vec3_calc_dot(q_[0], object->side_ab) / object->product[0];
	d_[1] = vec3_calc_dot(q_[0], object->side_ac) / object->product[1];
	if (d_[0] < 0 || d_[0] > 1 || d_[1] < 0 || d_[1] > 1)
		return (0);
	trace->t = d_[0];
	vec3_cpy(trace->point, tmp);
	vec3_cpy(trace->norm, object->norm);
	trace_set_face(trace, ray);
	return (1);
}

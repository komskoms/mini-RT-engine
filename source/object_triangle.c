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

t_obj_triangle	*create_triangle(t_vec p0[3], t_vec p1[3], t_vec p2[3])
{
	t_obj_triangle	*new;

	if (!(new = malloc(sizeof(t_obj_triangle))))
		return (0);
	vec3_cpy(new->point0, p0);
	vec3_cpy(new->point1, p1);
	vec3_cpy(new->point2, p2);
	vec3_calc_sub(new->side_u, p1, p0);
	vec3_calc_sub(new->side_v, p2, p0);
	vec3_calc_crs(new->norm, new->side_u, new->side_v);
	new->dot_uu = vec3_calc_dot(new->side_u, new->side_u);
	new->dot_uv = vec3_calc_dot(new->side_u, new->side_v);
	new->dot_vv = vec3_calc_dot(new->side_v, new->side_v);
	new->product = new->dot_uv * new->dot_uv - new->dot_uu * new->dot_vv;
	return (new);
}

static void		trace_set_face(t_trace *trace, t_ray ray)
{
	trace->face = vec3_calc_dot(ray.dir, trace->norm) < 0;
	if (!trace->face)
		vec3_calc_coef(trace->norm, trace->norm, -1);
}

int				hit_triangle(t_obj_triangle *object, t_ray ray, t_trace *trace)
{
	t_vec	q_[5][3];
	t_vec	tmp[3];
	double	d_[4];

	d_[0] = vec3_calc_dot(ray.ori, object->norm) -
			vec3_calc_dot(object->norm, object->point0);
	d_[1] = vec3_calc_dot(ray.dir, object->norm);
	d_[0] = -d_[0] / d_[1];
	if (d_[0] < ray.min || d_[0] > ray.max || d_[0] != d_[0])
		return (0);
	ray_point(tmp, ray, d_[0]);
	vec3_calc_sub(q_[0], tmp, object->point0);
	d_[0] = vec3_calc_dot(q_[0], object->side_u);
	d_[1] = vec3_calc_dot(q_[0], object->side_v);
	d_[2] = (object->dot_uv * d_[1] - object->dot_vv * d_[0]) / object->product;
	if (d_[2] < 0 || d_[2] > 1)
		return (0);
	d_[3] = (object->dot_uv * d_[0] - object->dot_uu * d_[1]) / object->product;
	if (d_[3] < 0 || d_[2] + d_[3] > 1)
		return (0);
	trace->t = d_[0];
	vec3_cpy(trace->point, tmp);
	vec3_cpy(trace->norm, object->norm);
	trace_set_face(trace, ray);
	return (1);
}

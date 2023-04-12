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

t_obj_plane		*create_plane(t_vec center[3], t_vec norm[3])
{
	t_obj_plane		*new;

	if (!(new = malloc(sizeof(t_obj_plane))))
		return (0);
	vec3_cpy(new->center, center);
	vec3_cpy(new->norm, norm);
	return (new);
}

static void		trace_set_face(t_trace *trace, t_ray ray)
{
	trace->face = vec3_calc_dot(ray.dir, trace->norm) < 0;
	if (!trace->face)
		vec3_calc_coef(trace->norm, trace->norm, -1);
}

int				hit_plane(t_obj_plane *plane, t_ray ray, t_trace *trace)
{
	t_vec	q_[2][3];
	double	v[2];

	v[0] = vec3_calc_dot(vec3_calc_sub(q_[0], ray.ori, plane->center),
						plane->norm);
	v[1] = vec3_calc_dot(ray.dir, plane->norm);
	if (v[1] == 0 || (v[0] < 0 && v[1] < 0) || (v[0] > 0 && v[1] > 0))
		return (0);
	v[0] = -v[0] / v[1];
	if (v[0] < ray.min || v[0] > ray.max)
		return (0);
	trace->t = v[0];
	ray_point(trace->point, ray, trace->t);
	vec3_cpy(trace->norm, plane->norm);
	trace_set_face(trace, ray);
	return (1);
}

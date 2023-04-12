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

t_obj_sphere	*create_sphere(t_vec center[3], double radius)
{
	t_obj_sphere	*new;

	if (!(new = malloc(sizeof(t_obj_sphere))))
		return (0);
	vec3_cpy(new->center, center);
	new->radius = radius;
	return (new);
}

static void		trace_set_face(t_trace *trace, t_ray ray)
{
	double		theta;
	double		phi;

	theta = acos(-trace->point[1]);
	phi = atan2(-trace->point[2], -trace->point[0]) + PI;
	trace->u = phi / (2 * PI);
	trace->v = theta / PI;
	trace->face = vec3_calc_dot(ray.dir, trace->norm) < 0;
	if (!trace->face)
		vec3_calc_coef(trace->norm, trace->norm, -1);
}

int				hit_sphere(t_obj_sphere *sphere, t_ray ray, t_trace *trace)
{
	t_vec	dummy[3];
	double	v[5];

	vec3_calc_sub(dummy, ray.ori, sphere->center);
	v[0] = vec3_calc_dot(ray.dir, ray.dir);
	v[1] = vec3_calc_dot(dummy, ray.dir);
	v[2] = vec3_calc_dot(dummy, dummy) - sphere->radius * sphere->radius;
	v[3] = v[1] * v[1] - v[0] * v[2];
	if (v[3] < 0)
		return (0);
	v[3] = sqrt(v[3]);
	v[4] = (-v[1] - v[3]) / v[0];
	if (v[4] < ray.min || v[4] > ray.max)
	{
		v[4] = (-v[1] + v[3]) / v[0];
		if (v[4] < ray.min || v[4] > ray.max)
			return (0);
	}
	trace->t = v[4];
	ray_point(trace->point, ray, v[4]);
	vec3_calc_coef(trace->norm, vec3_calc_sub(
		dummy, trace->point, sphere->center), 1 / sphere->radius);
	trace_set_face(trace, ray);
	return (1);
}

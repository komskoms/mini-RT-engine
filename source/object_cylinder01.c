/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinder01.c                                :+:      :+:    :+:   */
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

static int		trace_set_face(t_trace *trace, t_ray ray)
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
	return (1);
}

static void		set_equation_wall(
				t_vec q_[8][3], t_obj_cylinder *obj, t_ray ray)
{
	double	d_[2];

	vec3_calc_sub(q_[0], ray.ori, obj->center_bot);
	d_[0] = vec3_calc_dot(ray.dir, obj->norm);
	d_[1] = vec3_calc_dot(q_[0], obj->norm);
	q_[5][0] = vec3_calc_dot(ray.dir, ray.dir) - d_[0] * d_[0];
	q_[5][1] = 2.0 * (vec3_calc_dot(ray.dir, q_[0]) - d_[0] * d_[1]);
	q_[5][2] = vec3_calc_dot(q_[0], q_[0]) - d_[1] * d_[1]
							- obj->radius * obj->radius;
	q_[6][0] = q_[5][1] * q_[5][1] - 4.0 * (q_[5][0] * q_[5][2]);
}

static void		set_equation_cap(
				t_vec q_[8][3], t_obj_cylinder *obj, t_ray ray)
{
	q_[6][1] = (-q_[5][1] + sqrt(q_[6][0])) / (2.0 * q_[5][0]);
	q_[6][2] = (-q_[5][1] - sqrt(q_[6][0])) / (2.0 * q_[5][0]);
	ray_point(q_[3], ray, q_[6][1]);
	vec3_calc_sub(q_[3], q_[3], obj->center_bot);
	q_[7][0] = vec3_calc_dot(q_[3], obj->h_vec);
	ray_point(q_[4], ray, q_[6][2]);
	vec3_calc_sub(q_[4], q_[4], obj->center_bot);
	q_[7][1] = vec3_calc_dot(q_[4], obj->h_vec);
}

static int		solve_equation_cap(
				t_vec q_[8][3], t_obj_cylinder *obj, t_ray ray, t_trace *trace)
{
	if (q_[6][1] < q_[6][2])
		trace->t = q_[6][1];
	else
		trace->t = q_[6][2];
	if (trace->t < ray.min)
		return (0);
	ray_point(trace->point, ray, trace->t);
	vec3_calc_sub(q_[1], trace->point, obj->center_bot);
	q_[7][2] = vec3_calc_dot(q_[1], obj->h_vec);
	if (q_[7][2] >= 0 && q_[7][2] <= obj->height)
	{
		vec3_calc_sub(q_[1], trace->point, obj->center_bot);
		vec3_calc_coef(q_[1], obj->norm, vec3_calc_dot(q_[1], obj->norm));
		vec3_calc_sub(q_[2], trace->point, q_[1]);
		vec3_calc_sub(trace->norm, q_[2], obj->center_bot);
		return (1);
	}
	if (q_[7][2] > obj->height)
		vec3_calc_sub(q_[0], ray.ori, obj->center_bot);
	q_[5][0] = vec3_calc_dot(q_[0], obj->norm);
	q_[5][1] = vec3_calc_dot(ray.dir, obj->norm);
	trace->t = -q_[5][0] / q_[5][1];
	ray_point(trace->point, ray, trace->t);
	vec3_cpy(trace->norm, obj->norm);
	return (trace_set_face(trace, ray));
}

int				hit_cylinder(t_obj_cylinder *obj, t_ray ray, t_trace *trace)
{
	t_vec	q_[8][3];

	set_equation_wall(q_, obj, ray);
	if (q_[6][0] < 0)
		return (0);
	if (q_[6][0] == 0)
	{
		if ((trace->t = -q_[5][1] / (2.0 * q_[5][0])) < ray.min)
			return (0);
		ray_point(trace->point, ray, trace->t);
		vec3_calc_sub(q_[1], trace->point, obj->center_bot);
		vec3_calc_coef(q_[1], obj->norm, vec3_calc_dot(q_[1], obj->norm));
		vec3_calc_sub(q_[2], trace->point, q_[1]);
		vec3_calc_sub(trace->norm, q_[2], obj->center_bot);
		trace_set_face(trace, ray);
		return (1);
	}
	set_equation_cap(q_, obj, ray);
	if ((q_[7][0] < 0 || q_[7][0] > obj->height) &&
		(q_[7][1] < 0 || q_[7][1] > obj->height))
		return (0);
	return (solve_equation_cap(q_, obj, ray, trace));
}

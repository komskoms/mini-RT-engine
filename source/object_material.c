/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:15:03 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/21 02:20:19 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

static int	material_normal(t_trace *trace, t_ray *reflect, t_vec color[3])
{
	t_vec	q_[2][3];
	t_vec	tmp_color[3];

	vec3_cpy(reflect->ori, trace->point);
	vec3_calc_add(reflect->dir, trace->norm,
								diffuse_direction(q_[0], trace->material.fuzz));
	if (vec3_nearzero(reflect->dir))
		vec3_cpy(reflect->dir, trace->norm);
	if (trace->material.texture)
	{
		vec3_cpy(tmp_color, texture_checker(trace,
			vec3_put(q_[0], 0.2, 0.3, 0.1), vec3_put(q_[1], 0.9, 0.9, 0.9)));
		vec3_calc_coef(color, tmp_color, 1 - trace->material.fuzz / 2);
	}
	else
		vec3_calc_coef(color, trace->material.color,
							1 - trace->material.fuzz / 2);
	return (1);
}

static int	material_metal(
			t_ray ray, t_trace *trace, t_ray *reflect, t_vec color[3])
{
	t_vec	q_[2][3];

	vec3_cpy(reflect->ori, trace->point);
	vec3_calc_unit(q_[0], trace->norm);
	reflect_direction(reflect->dir, ray.dir, q_[0]);
	vec3_calc_add(reflect->dir, reflect->dir,
						diffuse_direction(q_[0], trace->material.fuzz));
	if (trace->material.texture)
		vec3_cpy(color, texture_checker(trace,
			vec3_put(q_[0], 0.2, 0.3, 0.1), vec3_put(q_[1], 0.9, 0.9, 0.9)));
	else
		vec3_cpy(color, trace->material.color);
	return (vec3_calc_dot(reflect->dir, trace->norm) > 0);
}

static int	material_glass(
			t_ray ray, t_trace *trace, t_ray *reflect, t_vec color[3])
{
	double	ratio;
	t_vec	q_[3];

	ratio = trace->face ? 1.0 / 1.5 : 1.5;
	vec3_cpy(reflect->ori, trace->point);
	vec3_cpy(reflect->dir, refract_direction(q_,
				vec3_calc_unit(q_, ray.dir), trace->norm, ratio));
	vec3_calc_add(reflect->dir, reflect->dir,
						diffuse_direction(q_, trace->material.fuzz));
	vec3_cpy(color, trace->material.color);
	return (1);
}

static int	material_light(
			t_ray ray, t_trace *trace, t_ray *reflect, t_vec color[3])
{
	if (ray.min == ray.max)
		ray.min = ray.max;
	vec3_cpy(reflect->ori, trace->point);
	vec3_put(reflect->dir, 0, 0, 0);
	vec3_cpy(color, trace->material.color);
	trace->t = 0;
	return (1);
}

int			material_response(
			t_ray ray, t_trace *trace, t_ray *reflect, t_vec color[3])
{
	if (trace->material.type == OBJ_NORMAL)
		return (material_normal(trace, reflect, color));
	if (trace->material.type == OBJ_METAL)
		return (material_metal(ray, trace, reflect, color));
	if (trace->material.type == OBJ_GLASS)
		return (material_glass(ray, trace, reflect, color));
	if (trace->material.type == OBJ_LIGHT)
		return (material_light(ray, trace, reflect, color));
	return (0);
}

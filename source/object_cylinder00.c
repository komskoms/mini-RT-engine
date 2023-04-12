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

t_obj_cylinder	*create_cylinder(
				t_vec center[3], t_vec norm[3], double radius, double height)
{
	t_obj_cylinder	*new;
	t_vec			h_unit[3];

	if (!(new = malloc(sizeof(t_obj_cylinder))))
		return (0);
	vec3_cpy(new->center, center);
	vec3_calc_unit(new->norm, norm);
	new->radius = radius;
	new->height = height;
	vec3_calc_coef(h_unit, new->norm, height / 2);
	vec3_calc_sub(new->center_bot, center, h_unit);
	vec3_calc_add(new->center_top, center, h_unit);
	vec3_calc_coef(new->h_vec, new->norm, height);
	return (new);
}

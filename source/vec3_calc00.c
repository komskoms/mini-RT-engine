/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:22:50 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/05 20:00:42 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

t_vec		*vec3_calc_coef(t_vec res[3], t_vec vec[3], double v)
{
	res[0] = vec[0] * v;
	res[1] = vec[1] * v;
	res[2] = vec[2] * v;
	return (res);
}

t_vec		*vec3_calc_unit(t_vec res[3], t_vec vec[3])
{
	return (vec3_calc_coef(res, vec, 1.0 / vec3_calc_len(vec)));
}

double		vec3_calc_dot(t_vec v1[3], t_vec v2[3])
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

double		vec3_calc_lsq(t_vec vec[3])
{
	return (vec3_calc_dot(vec, vec));
}

double		vec3_calc_len(t_vec vec[3])
{
	return (sqrt(vec3_calc_dot(vec, vec)));
}

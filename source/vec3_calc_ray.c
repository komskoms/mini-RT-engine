/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_ray_calcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:23:49 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 16:24:26 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "util_package.h"
#include <math.h>

t_vec		*diffuse_direction(t_vec res[3], double range)
{
	if (!range)
	{
		vec3_put(res, 0, 0, 0);
		return (res);
	}
	while (1)
	{
		rand_vec3(res, -range, range);
		if (vec3_calc_lsq(res) < range * range)
			return (res);
	}
}

t_vec		*reflect_direction(t_vec res[3], t_vec r_in[3], t_vec norm[3])
{
	t_vec	dummy[3];

	vec3_calc_coef(dummy, norm, vec3_calc_dot(r_in, norm) * 2);
	vec3_calc_sub(res, r_in, dummy);
	return (res);
}

t_vec		*refract_direction(
			t_vec res[3], t_vec r_in[3], t_vec norm[3], double ratio)
{
	double		cos_theta;
	double		sin_theta;
	t_vec		out[2][3];
	t_vec		q_[3];

	if ((cos_theta = vec3_calc_dot(vec3_calc_coef(q_, r_in, -1), norm)) > 1)
		cos_theta = 1.0;
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	if (ratio * sin_theta > 1)
		return (reflect_direction(res, r_in, norm));
	else
	{
		vec3_calc_add(out[0], r_in, vec3_calc_coef(q_, norm, cos_theta));
		vec3_calc_coef(out[0], out[0], ratio);
		vec3_calc_coef(out[1], norm, -sqrt(fabs(1.0 - vec3_calc_lsq(out[0]))));
	}
	return (vec3_calc_add(res, out[0], out[1]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_calc01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:19:17 by jihoon            #+#    #+#             */
/*   Updated: 2021/01/28 16:32:58 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <math.h>

t_vec		*vec3_calc_rot_x(t_vec ret[3], t_vec vec[3], double ang)
{
	t_vec	tmp[3];

	tmp[0] = vec[0];
	tmp[1] = vec[1] * cos(ang) - vec[2] * sin(ang);
	tmp[2] = vec[1] * sin(ang) + vec[2] * cos(ang);
	ret[0] = tmp[0];
	ret[1] = tmp[1];
	ret[2] = tmp[2];
	return (ret);
}

t_vec		*vec3_calc_rot_y(t_vec ret[3], t_vec vec[3], double ang)
{
	t_vec	tmp[3];

	tmp[0] = vec[0] * cos(ang) + vec[2] * sin(ang);
	tmp[1] = vec[1];
	tmp[2] = vec[2] * cos(ang) - vec[0] * sin(ang);
	ret[0] = tmp[0];
	ret[1] = tmp[1];
	ret[2] = tmp[2];
	return (ret);
}

t_vec		*vec3_calc_rot_z(t_vec ret[3], t_vec vec[3], double ang)
{
	t_vec	tmp[3];

	tmp[0] = vec[0] * cos(ang) - vec[1] * sin(ang);
	tmp[1] = vec[0] * sin(ang) + vec[1] * cos(ang);
	tmp[2] = vec[2];
	ret[0] = tmp[0];
	ret[1] = tmp[1];
	ret[2] = tmp[2];
	return (ret);
}

t_vec		*vec3_calc_rot(t_vec ret[3], t_vec vec[3], t_vec ang[3])
{
	vec3_calc_rot_x(ret, vec, ang[0]);
	vec3_calc_rot_y(ret, vec, ang[1]);
	vec3_calc_rot_z(ret, vec, ang[2]);
	return (ret);
}

t_vec		*vec3_calc_rot_rev(t_vec ret[3], t_vec vec[3], t_vec ang[3])
{
	vec3_calc_rot_x(ret, vec, -ang[0]);
	vec3_calc_rot_y(ret, vec, -ang[1]);
	vec3_calc_rot_z(ret, vec, -ang[2]);
	return (ret);
}

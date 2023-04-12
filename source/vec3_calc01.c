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

t_vec		*vec3_calc_add(t_vec res[3], t_vec v1[3], t_vec v2[3])
{
	res[0] = v1[0] + v2[0];
	res[1] = v1[1] + v2[1];
	res[2] = v1[2] + v2[2];
	return (res);
}

t_vec		*vec3_calc_sub(t_vec res[3], t_vec v1[3], t_vec v2[3])
{
	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];
	res[2] = v1[2] - v2[2];
	return (res);
}

t_vec		*vec3_calc_mul(t_vec res[3], t_vec v1[3], t_vec v2[3])
{
	res[0] = v1[0] * v2[0];
	res[1] = v1[1] * v2[1];
	res[2] = v1[2] * v2[2];
	return (res);
}

t_vec		*vec3_calc_div(t_vec res[3], t_vec v1[3], t_vec v2[3])
{
	res[0] = v1[0] / v2[0];
	res[1] = v1[1] / v2[1];
	res[2] = v1[2] / v2[2];
	return (res);
}

t_vec		*vec3_calc_crs(t_vec res[3], t_vec v1[3], t_vec v2[3])
{
	t_vec	tmp[3];

	tmp[0] = v1[1] * v2[2] - v1[2] * v2[1];
	tmp[1] = v1[2] * v2[0] - v1[0] * v2[2];
	tmp[2] = v1[0] * v2[1] - v1[1] * v2[0];
	res[0] = tmp[0];
	res[1] = tmp[1];
	res[2] = tmp[2];
	return (res);
}

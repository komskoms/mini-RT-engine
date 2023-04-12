/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:17:33 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/19 14:32:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "util_package.h"
#include <math.h>

unsigned int	color_trgb(int t, int r, int g, int b)
{
	return ((t & 0xFF) << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

unsigned int	color_vec3(double t, double color[3])
{
	double		hmm;

	hmm = 0.99999999999;
	return (color_trgb(
			255 * t + hmm, 255 * color[0] + hmm,
			255 * color[1] + hmm, 255 * color[2] + hmm));
}

t_vec			*color_itv3(t_vec res[3], unsigned int trgb)
{
	int		value[4];
	double	tp;

	value[0] = (trgb >> 24) & 0xFF;
	value[1] = (trgb >> 16) & 0xFF;
	value[2] = (trgb >> 8) & 0xFF;
	value[3] = trgb & 0xFF;
	tp = (double)(0xFF - value[0]) / 0xFF;
	vec3_put(
		res, tp * value[1] / 255, tp * value[2] / 255, tp * value[3] / 255);
	return (res);
}

t_vec			*color_blend(
				t_vec res[3], t_vec c0[3], t_vec c1[3], double ratio)
{
	t_vec	q_[2][3];

	vec3_calc_coef(q_[0], c0, ratio);
	vec3_calc_coef(q_[1], c1, 1.0 - ratio);
	vec3_calc_add(res, q_[0], q_[1]);
	clip_vec3(res, 0, 1);
	return (res);
}

t_vec			*gamma_correct(t_vec color[3], double value)
{
	color[0] = pow(color[0], 1 / value);
	color[1] = pow(color[1], 1 / value);
	color[2] = pow(color[2], 1 / value);
	return (color);
}

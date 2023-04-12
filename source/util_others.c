/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:17:26 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/10 18:03:45 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include "util_package.h"

double			to_radian(double deg)
{
	return (deg * PI / 180.0);
}

double			clip_double(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_vec			*clip_vec3(t_vec target[3], double min, double max)
{
	target[0] = clip_double(target[0], min, max);
	target[1] = clip_double(target[1], min, max);
	target[2] = clip_double(target[2], min, max);
	return (target);
}

int				vec3_nearzero(t_vec vec[3])
{
	double		tg;

	tg = 1e-8;
	return ((vec[0] < tg) && (vec[1] < tg) && (vec[2] < tg));
}

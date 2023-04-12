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
#include "raytracer.h"
#include <math.h>

t_vec			*texture_checker(t_trace *t_, t_vec even[3], t_vec odd[3])
{
	double	sines;

	sines =
	sin(10 * t_->point[0]) * sin(10 * t_->point[1]) * sin(10 * t_->point[2]);
	if (sines < 0)
		return (vec3_cpy(t_->material.color, odd));
	else
		return (vec3_cpy(t_->material.color, even));
}

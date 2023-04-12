/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_backgroud.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:59:59 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/12 23:27:25 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		*bg_gradation_vertic(t_vec res[3], t_vec ray_dir[3],
					t_vec top[3], t_vec bot[3])
{
	t_vec	unit[3];

	vec3_calc_unit(unit, ray_dir);
	return (color_blend(res, top, bot, 1.0 / 1 - unit[1]));
}

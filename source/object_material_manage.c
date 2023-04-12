/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_material_manage.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 00:15:03 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/15 05:52:26 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_manage.h"

t_material	*material_set(t_material *mat, t_parse_var vars)
{
	mat->type = vars.mat_type;
	mat->texture = vars.texture;
	vec3_cpy(mat->color, vars.color);
	mat->fuzz = vars.mat_fuzz < 1.0 ? vars.mat_fuzz : 1.0;
	return (mat);
}

void		material_cpy(t_material *dst, t_material src)
{
	dst->type = src.type;
	dst->texture = src.texture;
	vec3_cpy(dst->color, src.color);
	dst->fuzz = src.fuzz;
}

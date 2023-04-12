/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 21:55:50 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 03:30:18 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"
#include <stdlib.h>

t_vec		*vec3_create(double x, double y, double z)
{
	t_vec	*vector;

	if (!(vector = malloc(sizeof(double) * 3)))
		return (0);
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
	return (vector);
}

t_vec		*vec3_put(t_vec dst[3], double x, double y, double z)
{
	dst[0] = x;
	dst[1] = y;
	dst[2] = z;
	return (dst);
}

t_vec		*vec3_cpy(t_vec dst[3], t_vec src[3])
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	return (dst);
}

t_vec		*vec3_dup(t_vec vec[3])
{
	return (vec3_create(vec[0], vec[1], vec[2]));
}

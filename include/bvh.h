/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 23:18:46 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 03:42:10 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "vector3.h"
# include "object_manage.h"

typedef struct	s_aabb
{
	t_vec		min[3];
	t_vec		max[3];
}				t_aabb;

void			aabb_set(t_aabb *box, t_vec v1[3], t_vec v2[3]);
void			sphere_bounding_box(t_obj_sphere *sphere, t_aabb *box);

#endif

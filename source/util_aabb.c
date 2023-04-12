/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_aabb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:12:47 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 03:42:25 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "object_manage.h"
#include "raytracer.h"
#include <math.h>

void		aabb_set(t_aabb *aabb, t_vec v1[3], t_vec v2[3])
{
	vec3_cpy(aabb->min, v1);
	vec3_cpy(aabb->max, v2);
}

int			aabb_hit(t_aabb *aabb, t_ray r_, double t_min, double t_max)
{
	double	t[2];
	int		i;

	i = 0;
	while (i < 3)
	{
		t[0] = fmin((aabb->min[i] - r_.ori[i]) / r_.dir[i],
					(aabb->max[i] - r_.ori[i]) / r_.dir[i]);
		t[1] = fmax((aabb->min[i] - r_.ori[i]) / r_.dir[i],
					(aabb->max[i] - r_.ori[i]) / r_.dir[i]);
		t_min = fmax(t[0], t_min);
		t_max = fmin(t[1], t_max);
		if (t_max <= t_min)
			return (0);
	}
	return (1);
}

static void	*box_determine_selector(int type)
{
	if (type == OBJ_SPHERE)
		return (&sphere_bounding_box);
	return (0);
}

static void	surrounding_box(t_aabb *box0, t_aabb *box1)
{
	t_aabb		tmp;
	t_vec		min[3];
	t_vec		max[3];

	vec3_put(min, fmin(box0->min[0], box1->min[0]),
				fmin(box0->min[1], box1->min[1]),
				fmin(box0->min[2], box1->min[2]));
	vec3_put(max, fmax(box0->max[0], box1->max[0]),
				fmax(box0->max[1], box1->max[1]),
				fmax(box0->max[2], box1->max[2]));
	aabb_set(box0, min, max);
}

int			objlist_bounding_box(t_obj_list *head, t_aabb *out_box)
{
	t_aabb		tmp;
	int			*(*bounding_box_)(void *, t_aabb *);
	int			first_mark;

	if (!head)
		return (0);
	first_mark = 1;
	bounding_box_ = box_determine_selector(head->type);
	while (head)
	{
		if (!(*bounding_box_)(head->obj, &tmp))
			return (0);
		if (first_mark)
		{
			aabb_set(out_box, tmp.min, tmp.max);
			first_mark = 0;
		}
		else
			surrounding_box(out_box, &tmp);
	}
	return (1);
}

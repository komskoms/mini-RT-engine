/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 00:23:16 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 02:16:31 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		*tracer_selector(int obj_type)
{
	if (obj_type == OBJ_SPHERE)
		return (&hit_sphere);
	if (obj_type == OBJ_PLANE)
		return (&hit_plane);
	if (obj_type == OBJ_SQUARE)
		return (&hit_square);
	if (obj_type == OBJ_TRIANGLE)
		return (&hit_triangle);
	if (obj_type == OBJ_CYLINDER)
		return (&hit_cylinder);
	return (0);
}

static int		tracer_hit(t_obj_list *head, t_ray ray, t_trace *trace)
{
	int			*(*tracer_)(void *, t_ray, t_trace *);
	int			ret;

	tracer_ = 0;
	ret = 0;
	while (head)
	{
		if ((tracer_ = tracer_selector(head->type)))
		{
			if (tracer_(head->obj, ray, trace))
			{
				trace->material = head->material;
				ray.max = trace->t;
				ret = 1;
			}
		}
		head = head->next;
	}
	return (ret);
}

t_vec			*pixel_sampling(t_vec res[3], t_render *r_, t_vars *v_, int m)
{
	t_trace	trace;
	t_vec	col[3];

	if (m <= 0)
		return (vec3_put(res, 0, 0, 0));
	if (tracer_hit(v_->obj, r_->ray, &trace))
	{
		if (material_response(r_->ray, &trace, &r_->ray, col))
		{
			if (trace.material.type == OBJ_LIGHT)
				vec3_calc_add(res, col, pixel_sampling(res, r_, v_, m - 1));
			else
				vec3_calc_mul(res, col, pixel_sampling(res, r_, v_, m - 1));
			return (res);
		}
		return (vec3_put(res, 0, 0, 0));
	}
	return (color_itv3(res, v_->frame.ambience));
}

void			rt_render(t_vars *v_, t_render *r_)
{
	t_vec			col[2][3];

	r_->h_ = -1;
	while (++r_->h_ < v_->frame.height)
	{
		r_->w_ = -1;
		while (++r_->w_ < v_->frame.width)
		{
			ray_set(r_, v_, 0.001, 1000);
			pixel_sampling(col[0], r_, v_, MAX_REFLECT);
			gamma_correct(col[0], 1.7);
			clip_vec3(col[0], 0, 1);
			if (r_->count > 1)
			{
				r_->prev_color = my_mlx_pixel_read(
					&v_->img, r_->w_, v_->frame.height - 1 - r_->h_);
				r_->prev_color = color_vec3(0, color_blend(col[0],
				col[0], color_itv3(col[1], r_->prev_color), 1.0 / r_->count));
			}
			else
				r_->prev_color = color_vec3(0, col[0]);
			my_mlx_pixel_fill(
			&v_->img, r_->w_, v_->frame.height - 1 - r_->h_, r_->prev_color);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:55:13 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/12 23:41:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray		*ray_set(t_render *r_, t_vars *v_, double min, double max)
{
	t_cam		*cam;
	double		x;
	double		y;
	t_vec		q_[2][3];

	cam = v_->current_cam;
	x = ((double)r_->w_ + rand_double()) / v_->frame.width;
	y = ((double)r_->h_ + rand_double()) / v_->frame.height;
	vec3_cpy(r_->ray.ori, cam->origin);
	vec3_calc_coef(q_[0], cam->horize, x);
	vec3_calc_coef(q_[1], cam->vertic, y);
	vec3_calc_add(q_[0], q_[0], q_[1]);
	vec3_calc_add(q_[0], cam->corner, q_[0]);
	vec3_calc_sub(r_->ray.dir, q_[0], cam->origin);
	r_->ray.min = min;
	r_->ray.max = max;
	return (&r_->ray);
}

t_ray		*ray_put(t_ray *ret, t_vec point[3], t_vec direction[3])
{
	vec3_cpy(ret->ori, point);
	vec3_cpy(ret->dir, direction);
	return (ret);
}

t_vec		*ray_point(t_vec res[3], t_ray ray, double t)
{
	return (vec3_calc_add(res, ray.ori, vec3_calc_coef(res, ray.dir, t)));
}

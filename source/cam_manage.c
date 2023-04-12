/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_var_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:33:44 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 15:50:16 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void			cam_set_base(
				t_cam *c_, t_vec pos[3][3], double f_ratio, double angle)
{
	double		h_unit;
	t_vec		unit[3][3];
	t_vec		q_[2][3];

	h_unit = tan(to_radian(angle) / 2);
	vec3_calc_unit(unit[0], vec3_calc_sub(q_[0], pos[0], pos[1]));
	vec3_calc_unit(unit[1], vec3_calc_crs(q_[0], pos[2], unit[0]));
	vec3_calc_crs(unit[2], unit[0], unit[1]);
	vec3_cpy(c_->origin, pos[0]);
	vec3_calc_coef(c_->horize, unit[1], h_unit);
	vec3_calc_coef(c_->vertic, unit[2], h_unit * f_ratio);
	vec3_calc_sub(c_->corner, c_->origin,
		vec3_calc_add(q_[0], vec3_calc_coef(q_[0], c_->horize, 0.5),
			vec3_calc_coef(q_[1], c_->vertic, 0.5)));
	vec3_calc_sub(c_->corner, c_->corner, unit[0]);
}

int				cam_list_add(
				t_cam **c_, t_vec pos[3][3], double f_ratio, double angle)
{
	t_cam		*new;

	new = *c_;
	if (!new)
	{
		if (!(new = malloc(sizeof(t_cam))))
			return (0);
		*c_ = new;
	}
	else
	{
		while (new->next)
			new = new->next;
		if (!(new->next = malloc(sizeof(t_cam))))
			return (0);
		new = new->next;
	}
	cam_set_base(new, pos, f_ratio, angle);
	new->next = 0;
	return (1);
}

void			cam_list_clear(t_cam *head)
{
	if (!head)
		return ;
	cam_list_clear(head->next);
	free(head);
}

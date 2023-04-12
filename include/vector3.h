/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_manage.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:01:53 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/05 20:00:09 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef	double		t_vec;

t_vec				*vec3_create(double x, double y, double z);
t_vec				*vec3_put(t_vec dst[3], double x, double y, double z);
t_vec				*vec3_cpy(t_vec dst[3], t_vec src[3]);
t_vec				*vec3_dup(t_vec vec[3]);
t_vec				*vec3_calc_add(t_vec res[3], t_vec v1[3], t_vec v2[3]);
t_vec				*vec3_calc_sub(t_vec res[3], t_vec v1[3], t_vec v2[3]);
t_vec				*vec3_calc_mul(t_vec res[3], t_vec v1[3], t_vec v2[3]);
t_vec				*vec3_calc_div(t_vec res[3], t_vec v1[3], t_vec v2[3]);
t_vec				*vec3_calc_crs(t_vec res[3], t_vec v1[3], t_vec v2[3]);
t_vec				*vec3_calc_coef(t_vec res[3], t_vec vec[3], double v);
t_vec				*vec3_calc_unit(t_vec res[3], t_vec vec[3]);
double				vec3_calc_dot(t_vec v1[3], t_vec v2[3]);
double				vec3_calc_lsq(t_vec vec[3]);
double				vec3_calc_len(t_vec vec[3]);
t_vec				*vec3_calc_rot_x(t_vec ret[3], t_vec vec[3], double ang);
t_vec				*vec3_calc_rot_y(t_vec ret[3], t_vec vec[3], double ang);
t_vec				*vec3_calc_rot_z(t_vec ret[3], t_vec vec[3], double ang);
t_vec				*vec3_calc_rot(t_vec ret[3], t_vec vec[3], t_vec ang[3]);
t_vec				*vec3_calc_rot_rev
					(t_vec ret[3], t_vec vec[3], t_vec ang[3]);
double				vec3_calc_dist(t_vec pa[3], t_vec pb[3]);
void				print_vec3(t_vec vec[3]);

#endif

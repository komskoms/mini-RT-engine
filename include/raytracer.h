/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:52:38 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/15 06:11:53 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "object_manage.h"
# include "variables.h"

t_vec				*ray_point(t_vec res[3], t_ray ray, double t);
t_ray				*ray_put(t_ray *ret, t_vec point[3], t_vec direction[3]);
t_ray				*ray_set(t_render *r_, t_vars *v_, double min, double max);
t_vec				*pixel_sampling
					(t_vec res[3], t_render *r_, t_vars *v_, int depth);
void				rt_render(t_vars *v_, t_render *r_);
/*
**	something internalish
*/
t_vec				*bg_gradation_vertic
					(t_vec *res, t_vec dir[3], t_vec c1[3], t_vec c2[3]);
t_vec				*texture_checker(t_trace *t_, t_vec even[3], t_vec odd[3]);
int					hit_sphere(t_obj_sphere *sph, t_ray ray, t_trace *t_);
int					hit_plane(t_obj_plane *plane, t_ray ray, t_trace *t_);
int					hit_square(t_obj_square *square, t_ray ray, t_trace *t_);
int					hit_triangle(t_obj_triangle *tri, t_ray ray, t_trace *t_);
int					hit_cylinder(t_obj_cylinder *cyl, t_ray ray, t_trace *t_);
int					material_response
					(t_ray r, t_trace *trace, t_ray *reflect, t_vec color[3]);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_package.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:40:40 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/25 02:42:15 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_PACKAGE_H
# define UTIL_PACKAGE_H

# include "vector3.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define RAND_SEED 1234567
# define PI 3.1415926535897932385

/*
** Improvised random number generators
*/
unsigned int	my_rand(void);
double			rand_double(void);
double			rand_double_range(double min, double max);
t_vec			*rand_vec3(t_vec res[3], double min, double max);
/*
** Simple math
*/
double			to_radian(double degree);
double			clip_double(double x, double min, double max);
t_vec			*clip_vec3(t_vec vec[3], double min, double max);
int				vec3_nearzero(t_vec vec[3]);
/*
** Color processor
*/
unsigned int	color_trgb(int t, int r, int g, int b);
unsigned int	color_vec3(double t, t_vec color[3]);
t_vec			*color_itv3(t_vec res[3], unsigned int trgb);
t_vec			*color_blend
				(t_vec res[3], t_vec c1[3], t_vec c2[3], double ratio);
t_vec			*gamma_correct(t_vec color[3], double v);
/*
** Ray reflection calculators
*/
t_vec			*diffuse_direction(t_vec res[3], double range);
t_vec			*reflect_direction(t_vec res[3], t_vec r_in[3], t_vec norm[3]);
t_vec			*refract_direction
				(t_vec res[3], t_vec r_in[3], t_vec norm[3], double ratio);

#endif

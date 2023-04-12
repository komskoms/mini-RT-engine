/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:02:10 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/09 03:32:01 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "raytracer.h"
# include "rtfile.h"
# include "scene_control.h"
# include <stdio.h>
# include <errno.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# ifndef MAX_REFLECT
#  define MAX_REFLECT 50
# endif
# ifndef BMP_RENDERING_RATE
#  define BMP_RENDERING_RATE 50
# endif
# define BMP_HEADER_SIZE 122

int			save_bmp(t_vars *v_, char *filename);
int			console_interface(t_vars *v_);

#endif

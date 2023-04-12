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

#ifndef VARIABLES_H
# define VARIABLES_H

# include "vector3.h"
# include "object_manage.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

/*
** major variables & structures for miniRT
*/
typedef struct		s_img
{
	void			*inst;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_frame
{
	double			ratio;
	int				width;
	int				height;
	int				ambience;
}					t_frame;

typedef struct		s_cam
{
	t_vec			origin[3];
	t_vec			horize[3];
	t_vec			vertic[3];
	t_vec			corner[3];
	struct s_cam	*next;
}					t_cam;

typedef struct		s_ray
{
	t_vec			ori[3];
	t_vec			dir[3];
	double			min;
	double			max;
}					t_ray;

typedef struct		s_trace
{
	t_vec			point[3];
	t_vec			norm[3];
	t_material		material;
	double			t;
	double			u;
	double			v;
	int				face;
}					t_trace;

typedef struct		s_render
{
	t_ray			ray;
	t_trace			trace;
	int				w_;
	int				h_;
	unsigned int	prev_color;
	int				count;
}					t_render;

typedef struct		s_vars
{
	char			*filepath;
	void			*mlx;
	void			*win;
	t_img			img;
	t_frame			frame;
	t_cam			*cam;
	t_cam			*current_cam;
	t_obj_list		*obj;
	t_render		r_info;
	int				flag[9];
}					t_vars;

void				screen_size_limit(t_vars *v_, int *sizex, int *sizey);
void				initiate_image(t_vars *v_);
void				initiate_all(t_vars *v_);
void				cam_set_base(
					t_cam *c_, t_vec pos[3][3], double f_ratio, double angle);
int					cam_list_add(
					t_cam **c_, t_vec pos[3][3], double f_ratio, double angle);
t_cam				*cam_list_select(t_cam *head);
void				cam_list_clear(t_cam *head);
void				my_mlx_pixel_fill(
					t_img *img, int x, int y, unsigned int color);
unsigned int		my_mlx_pixel_read(t_img *img, int x, int y);

#endif

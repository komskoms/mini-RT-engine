/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_manage00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:33:44 by jihoon            #+#    #+#             */
/*   Updated: 2021/04/15 00:44:08 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void			screen_size_limit(t_vars *v_, int *sizex, int *sizey)
{
	int		maxx;
	int		maxy;

	mlx_get_screen_size(v_->mlx, &maxx, &maxy);
	if (*sizex > maxx)
		*sizex = maxx;
	if (*sizey > maxy)
		*sizey = maxy;
}

static void		flag_reset(int *arr, int size)
{
	while (size--)
		arr[size] = 0;
}

void			initiate_image(t_vars *v_)
{
	v_->img.inst = mlx_new_image(v_->mlx,
								v_->frame.width,
								v_->frame.height);
	v_->img.addr = mlx_get_data_addr(v_->img.inst,
									&v_->img.bits_per_pixel,
									&v_->img.line_length,
									&v_->img.endian);
}

void			initiate_all(t_vars *v_)
{
	v_->win = mlx_new_window(v_->mlx,
							v_->frame.width,
							v_->frame.height,
							"minirt");
	initiate_image(v_);
	flag_reset(v_->flag, 9);
	v_->current_cam = v_->cam;
	v_->r_info.count = 0;
}

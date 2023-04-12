/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:47:24 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/29 23:47:27 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keycode.h"
#include "variables.h"
#include "scene_control.h"
#include "rtfile.h"
#include <stdio.h>

static void	reinitiate_image(t_vars *v_)
{
	mlx_destroy_image(v_->mlx, v_->img.inst);
	initiate_image(v_);
	v_->r_info.count = 0;
}

int			key_hook(int keycode, t_vars *v_)
{
	printf("key input : [%d]\n", keycode);
	if (keycode == KEYCODE_ESC)
		terminate_minirt(v_);
	if (keycode == KEYCODE_TAB)
	{
		v_->current_cam =
			v_->current_cam->next ? v_->current_cam->next : v_->cam;
		reinitiate_image(v_);
	}
	if (keycode == KEYCODE_R)
	{
		object_list_clear(v_->obj);
		v_->obj = 0;
		if (!rtfile_read(v_->filepath, v_))
			terminate_minirt(v_);
		reinitiate_image(v_);
	}
	if (keycode == KEYCODE_P)
		v_->flag[0] = v_->flag[0] ? 0 : 1;
	return (0);
}

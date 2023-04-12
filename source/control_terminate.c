/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_terminate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 00:15:31 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/30 00:15:32 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_manage.h"
#include "variables.h"

void			terminate_minirt(t_vars *v_)
{
	cam_list_clear(v_->cam);
	object_list_clear(v_->obj);
	mlx_destroy_image(v_->mlx, v_->img.inst);
	exit(0);
}

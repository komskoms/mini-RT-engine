/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:46:48 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/25 17:39:52 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"

void			my_mlx_pixel_fill(t_img *img, int x, int y, unsigned int color)
{
	void	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_pixel_read(t_img *img, int x, int y)
{
	void	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}

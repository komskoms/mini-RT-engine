/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpsave.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:43:10 by jihokim           #+#    #+#             */
/*   Updated: 2021/04/13 00:43:11 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		fill_header(t_vars *v_, void *raw_bmp)
{
	unsigned int	img_size;

	img_size = v_->frame.width * v_->frame.height * 3;
	*(unsigned char *)raw_bmp = 'B';
	*(unsigned char *)(raw_bmp + 1) = 'M';
	*(unsigned int *)(raw_bmp + 2) = (img_size + BMP_HEADER_SIZE);
	*(unsigned int *)(raw_bmp + 6) = 0u;
	*(unsigned char *)(raw_bmp + 10) = BMP_HEADER_SIZE;
	*(unsigned int *)(raw_bmp + 14) = BMP_HEADER_SIZE - 14;
	*(unsigned int *)(raw_bmp + 18) = v_->frame.width;
	*(unsigned int *)(raw_bmp + 22) = v_->frame.height;
	*(unsigned short *)(raw_bmp + 26) = 1;
	*(unsigned short *)(raw_bmp + 28) = 24;
	*(unsigned int *)(raw_bmp + 30) = 0;
	*(unsigned int *)(raw_bmp + 34) = img_size;
	*(unsigned int *)(raw_bmp + 38) = 3780;
	*(unsigned int *)(raw_bmp + 42) = 3780;
	*(int *)(raw_bmp + 46) = 0;
	*(int *)(raw_bmp + 50) = 0;
}

static void		fill_data(t_vars *v_, void *raw_bmp)
{
	unsigned int	color;
	unsigned int	idx;
	int				w;
	int				h;

	idx = BMP_HEADER_SIZE;
	h = v_->frame.height;
	while (h--)
	{
		w = 0;
		while (w < v_->frame.width)
		{
			color = my_mlx_pixel_read(&v_->img, w, h);
			*(unsigned char *)(raw_bmp + idx++) = (color >> 0) & 0xFF;
			*(unsigned char *)(raw_bmp + idx++) = (color >> 8) & 0xFF;
			*(unsigned char *)(raw_bmp + idx++) = (color >> 16) & 0xFF;
			w++;
		}
	}
}

int				save_bmp(t_vars *v_, char *filename)
{
	void	*raw_bmp;
	int		img_size;
	int		i;
	int		fd;

	img_size = v_->frame.width * v_->frame.height * 3;
	if (!(raw_bmp = malloc(img_size + BMP_HEADER_SIZE)))
		return (0);
	i = 0;
	while (i < img_size + BMP_HEADER_SIZE)
		((unsigned char *)raw_bmp)[i++] = 0;
	fill_header(v_, raw_bmp);
	fill_data(v_, raw_bmp);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	write(fd, raw_bmp, (img_size + BMP_HEADER_SIZE));
	close(fd);
	free(raw_bmp);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtfile_parse00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:37:04 by jihokim           #+#    #+#             */
/*   Updated: 2021/04/13 21:32:24 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtfile.h"
#include "variables.h"
#include "util_package.h"

static int		parse_resolution(t_vars *v_, char *line)
{
	line += next_index(line, 0);
	v_->frame.width = my_atoi(line);
	line += next_index(line, 0);
	v_->frame.height = my_atoi(line);
	screen_size_limit(v_, &v_->frame.width, &v_->frame.height);
	v_->frame.ratio = (double)v_->frame.height / v_->frame.width;
	return (1);
}

static int		parse_anbience(t_vars *v_, char *line)
{
	int			col[3];
	double		aa;

	line += next_index(line, 0);
	aa = my_atod(line);
	line += next_index(line, 0);
	col[0] = my_atoi(line);
	while (*line == ',')
		line++;
	col[1] = my_atoi(line);
	while (*line == ',')
		line++;
	col[2] = my_atoi(line);
	v_->frame.ambience = color_trgb(255 * (1 - aa), col[0], col[1], col[2]);
	return (1);
}

static int		parse_camera(t_vars *v_, char *line)
{
	t_vec		info[3][3];
	double		aa;

	line += next_index(line, 0);
	line += readnmove_vec3(info[0], line);
	line += readnmove_vec3(info[1], line);
	aa = my_atod(line);
	vec3_put(info[2], 0, 1, 0);
	if (!(cam_list_add(&v_->cam, info, v_->frame.ratio, aa)))
		return (0);
	return (1);
}

int				parse_line__(t_vars *v_, char *line)
{
	if (!line)
		return (0);
	if (*line == 'R')
		return (parse_resolution(v_, line));
	if (*line == 'A')
		return (parse_anbience(v_, line));
	if (*line == 'c' && is_blank(*(line + 1)))
		return (parse_camera(v_, line));
	return (parse_line(&v_->obj, line));
}

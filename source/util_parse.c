/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:52:49 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/30 16:52:50 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_string.h"
#include "rtfile.h"
#include "vector3.h"

int			next_index(char *line, int last_idx)
{
	int			i;

	line += last_idx;
	i = 0;
	while (line[i] > 32 && line[i] < 127)
		i++;
	while (line[i] <= 32 && line[i])
		i++;
	return (i);
}

int			readnmove_vec3(t_vec store[3], char *line)
{
	str_to_vec3(store, line);
	return (next_index(line, 0));
}

int			readnmove_double(double *store, char *line)
{
	*store = my_atod(line);
	return (next_index(line, 0));
}

int			readnmove_int(int *store, char *line)
{
	*store = my_atoi(line);
	return (next_index(line, 0));
}

int			readnmove_str(char *store, char *line)
{
	int		i;

	i = 0;
	while (i < 79 && !is_blank(line[i]))
		i++;
	ft_strlcpy(store, line, ++i);
	return (next_index(line, 0));
}

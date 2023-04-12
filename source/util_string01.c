/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:04:14 by jihokim           #+#    #+#             */
/*   Updated: 2021/02/27 18:10:46 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_string.h"
#include "vector3.h"

t_vec		*str_to_vec3(t_vec ret[3], char *str)
{
	if (!str)
		return (0);
	while (is_blank(*str))
		str++;
	ret[0] = my_atod(str);
	while (*str++ != ',')
		;
	ret[1] = my_atod(str);
	while (*str++ != ',')
		;
	ret[2] = my_atod(str);
	return (ret);
}

void		my_itoa8(char ret[9], int num)
{
	ret[0] = ((num / 10000000) % 10) + '0';
	ret[1] = ((num / 1000000) % 10) + '0';
	ret[2] = ((num / 100000) % 10) + '0';
	ret[3] = ((num / 10000) % 10) + '0';
	ret[4] = ((num / 1000) % 10) + '0';
	ret[5] = ((num / 100) % 10) + '0';
	ret[6] = ((num / 10) % 10) + '0';
	ret[7] = (num % 10) + '0';
	ret[8] = 0;
}

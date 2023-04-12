/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:31:41 by jihoon            #+#    #+#             */
/*   Updated: 2021/02/10 21:44:19 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int	my_rand(void)
{
	static unsigned int	z1 = RAND_SEED;
	static unsigned int	z2 = RAND_SEED;
	static unsigned int	z3 = RAND_SEED;
	static unsigned int	z4 = RAND_SEED;
	unsigned int		b;

	b = ((z1 << 6) ^ z1) >> 13;
	z1 = ((z1 & (UINT_MAX - 1)) << 18) ^ b;
	b = ((z2 << 2) ^ z2) >> 27;
	z2 = ((z2 & (UINT_MAX - 7)) << 2) ^ b;
	b = ((z3 << 13) ^ z3) >> 21;
	z3 = ((z3 & (UINT_MAX - 15)) << 7) ^ b;
	b = ((z4 << 3) ^ z4) >> 12;
	z4 = ((z4 & (UINT_MAX - 127)) << 13) ^ b;
	return (z1 ^ z2 ^ z3 ^ z4);
}

double			rand_double(void)
{
	return (my_rand() / (UINT_MAX + 1.0));
}

double			rand_double_range(double min, double max)
{
	return (min + (max - min) * rand_double());
}

t_vec			*rand_vec3(t_vec res[3], double min, double max)
{
	res[0] = rand_double_range(min, max);
	res[1] = rand_double_range(min, max);
	res[2] = rand_double_range(min, max);
	return (res);
}

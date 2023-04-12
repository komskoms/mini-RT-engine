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

int				is_blank(char ch)
{
	if (ch == '\t' || ch == '\v' || ch == '\n' ||
		ch == '\f' || ch == '\r' || ch == ' ')
		return (1);
	else
		return (0);
}

static int		s_atoi(char *str)
{
	int		ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret);
}

static double	post_point(char *str)
{
	double		ret;
	double		coef;

	ret = 0;
	coef = 1;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '.')
		return (0);
	else
		str++;
	while (*str >= '0' && *str <= '9')
	{
		coef /= 10;
		ret += (*str - '0') * coef;
		str++;
	}
	return (ret);
}

int				my_atoi(char *str)
{
	int			ret;
	int			neg;

	if (!str)
		return (0);
	while (is_blank(*str))
		str++;
	neg = 0;
	if (*str == '-')
		neg = *str++;
	ret = s_atoi(str);
	if (neg)
		ret *= -1;
	return (ret);
}

double			my_atod(char *str)
{
	double		ret;
	int			neg;

	if (!str)
		return (0);
	while (is_blank(*str))
		str++;
	neg = 0;
	if (*str == '-')
		neg = *str++;
	ret = s_atoi(str);
	ret += post_point(str);
	if (neg)
		ret *= -1;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 22:14:03 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/16 00:03:41 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_digit_count(int num)
{
	int		count;

	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*put_min(void)
{
	char	*str;
	char	*min;
	int		i;

	str = malloc(sizeof(char) * 12);
	min = "-2147483648";
	i = 0;
	while (i < 11)
	{
		str[i] = min[i];
		i++;
	}
	str[11] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		digit_count;
	int		neg_flag;
	int		i;

	if (n == -2147483648)
		return (str = put_min());
	neg_flag = n <= 0 ? 1 : 0;
	digit_count = get_digit_count(n);
	digit_count += neg_flag;
	if (!(str = malloc(sizeof(char) * (digit_count + 1))))
		return (0);
	if (neg_flag && (n *= -1))
		str[0] = '-';
	str[digit_count] = '\0';
	i = neg_flag && n ? neg_flag : 0;
	while (digit_count-- > i)
	{
		str[digit_count] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

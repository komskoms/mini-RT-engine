/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 23:25:46 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/07 16:08:21 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	long long	number;
	int			neg_flag;

	number = 0;
	neg_flag = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' ||
				*str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg_flag = -1;
		str++;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
		number = number * 10 + (*str++ - '0');
	number *= neg_flag;
	return (number);
}

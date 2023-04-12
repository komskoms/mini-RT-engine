/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:34:15 by jihoon            #+#    #+#             */
/*   Updated: 2020/12/05 22:28:56 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	char	*ret_str;
	int		ret_len;
	int		i;

	ret_str = NULL;
	ret_len = ft_vasprintf(&ret_str, format, ap);
	i = 0;
	while (i < ret_len)
	{
		str[i] = ret_str[i];
		i++;
	}
	str[i] = '\0';
	free(ret_str);
	return (ret_len);
}

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	char	*ret_str;
	int		ret_len;
	size_t	i;

	ret_len = ft_vasprintf(&ret_str, format, ap);
	i = 0;
	while (i < size)
	{
		str[i] = ret_str[i];
		i++;
	}
	if (size)
		str[i] = '\0';
	free(ret_str);
	return (ret_len);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	int		size;

	str = NULL;
	size = ft_vasprintf(&str, format, ap);
	if (write(fd, str, size) < 0)
		return (-1);
	free(str);
	return (size);
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

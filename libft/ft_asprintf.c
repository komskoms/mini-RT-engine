/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:59:21 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/05 22:26:04 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <stdio.h>

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	return (ft_vasprintf_internal(ret, format, ap));
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list		ap;
	int			ret_len;

	va_start(ap, format);
	ret_len = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ret_len);
}

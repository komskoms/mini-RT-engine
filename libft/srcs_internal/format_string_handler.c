/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:17:14 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/05 23:55:00 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static char	*trim_non_conversion(t_prf_traits *traits, const char *format)
{
	char	*ret;
	int		len;

	len = 0;
	while (format[len] != CONV_CHAR && format[len] != '\0')
		len++;
	traits->flag_len = len;
	traits->conv_len = len;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	while (len--)
		ret[len] = format[len];
	return (ret);
}

char		*format_string_handler(
		t_prf_traits *traits, const char *format, va_list ap)
{
	if (*format == CONV_CHAR)
	{
		traits->flag_len++;
		return (format_conversion_handler(traits, format, ap));
	}
	else
		return (trim_non_conversion(traits, format));
}

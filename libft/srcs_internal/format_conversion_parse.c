/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion_parse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:35:45 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/16 00:31:20 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static int	get_flags(t_prf_traits *traits, const char *format)
{
	int		i;

	i = 0;
	while (FLAGS[i])
	{
		if (FLAGS[i] == *format)
		{
			traits->flag[i] = *format;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	get_intnum(int *intpt, const char *format, va_list ap)
{
	int		digits;

	digits = 0;
	if (*format == '*')
	{
		*intpt = va_arg(ap, int);
		return (1);
	}
	while (format[digits] >= '0' && format[digits] <= '9')
	{
		*intpt = *intpt * 10 + format[digits] - '0';
		digits++;
	}
	return (digits);
}

/*
**	get_length() must be executed twice to scan 'll' or 'hh'
*/

static int	get_length(t_prf_traits *traits, const char *format)
{
	int		i;

	if (traits->length)
	{
		if (traits->length != *format)
			return (1);
		if (*format == 'l')
			traits->length = 1;
		if (*format == 'h')
			traits->length = 2;
		return (2);
	}
	i = 0;
	while (LENGTH_FLAGS[i])
	{
		if (LENGTH_FLAGS[i] == *format)
		{
			traits->length = LENGTH_FLAGS[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int			conversion_parse(
		t_prf_traits *traits, const char *format, va_list ap)
{
	while (get_flags(traits, format + traits->flag_len))
		traits->flag_len++;
	traits->flag_len +=
		get_intnum(&traits->width, format + traits->flag_len, ap);
	if (traits->width < 0)
	{
		traits->flag[FI_DASH] = '-';
		traits->width *= -1;
	}
	if (format[traits->flag_len] == PRECISION_FLAG)
	{
		traits->precision = 0;
		traits->flag_len++;
		traits->flag_len +=
			get_intnum(&traits->precision, format + traits->flag_len, ap);
		traits->precision = traits->precision < 0 ? -1 : traits->precision;
	}
	if (get_length(traits, format + traits->flag_len))
		traits->flag_len += get_length(traits, format + traits->flag_len + 1);
	if (format[traits->flag_len] &&
			ft_strchr(CONV_SPECIFIERS, format[traits->flag_len]))
		traits->conversion = format[traits->flag_len++];
	if (traits->flag[FI_DASH])
		traits->flag[FI_ZERO] = 0;
	return (1);
}

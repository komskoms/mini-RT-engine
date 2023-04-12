/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:34:23 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/08 15:55:40 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static char	*conversion_to_string(t_prf_traits *traits, va_list ap)
{
	if (traits->conversion == 'c' || traits->conversion == CONV_CHAR)
		return (conversion_handler_c(traits, ap));
	if (traits->conversion == 's')
		return (conversion_handler_s(traits, ap));
	if (ft_strchr(INT_GRP, traits->conversion))
		return (conversion_handler_int(traits, ap));
	if (ft_strchr(UINT_GRP, traits->conversion))
		return (conversion_handler_uint(traits, ap));
	if (ft_strchr(FLT_GRP, traits->conversion))
		return (conversion_handler_flt(traits, ap));
	if (traits->conversion == 'p')
		return (conversion_handler_p(traits, ap));
	if (traits->conversion == 'n')
		return (conversion_handler_n(traits, ap));
	return (ft_strdup(""));
}

/*
**	'conversion_parse()' sets the 'traits' structure according to the specifiers
**	read from 'format'.
**	'conversion_to_string()' generates and returns the accordingly converted
**	freeable string.
**	'conversion_arrange()' deals with flags(-+ #) and width. input string is
**	automatically freed, and modified string is generated and returned.
*/

char		*format_conversion_handler(
		t_prf_traits *traits, const char *format, va_list ap)
{
	if (!(conversion_parse(traits, format, ap)))
		return (NULL);
	return (conversion_to_string(traits, ap));
}

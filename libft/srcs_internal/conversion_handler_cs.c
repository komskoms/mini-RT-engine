/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler_cs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:54:59 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/06 22:10:19 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

char	*conversion_handler_c(t_prf_traits *traits, va_list ap)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (traits->conversion == CONV_CHAR)
		ret[0] = CONV_CHAR;
	else
		ret[0] = va_arg(ap, int);
	ret[1] = '\0';
	traits->conv_len = 1;
	conversion_width_arrange(traits, &ret, traits->width - traits->conv_len);
	return (ret);
}

char	*conversion_handler_s(t_prf_traits *traits, va_list ap)
{
	char	*trim;
	char	*ret;

	ret = va_arg(ap, char *);
	if (ret)
		ret = ft_strdup(ret);
	else
		ret = ft_strdup("(null)");
	if (traits->precision >= 0)
	{
		trim = malloc(sizeof(char) * (traits->precision + 1));
		ft_strlcpy(trim, ret, traits->precision + 1);
		free(ret);
		ret = ft_strdup(trim);
		free(trim);
	}
	traits->conv_len = ft_strlen(ret);
	conversion_width_arrange(traits, &ret, traits->width - traits->conv_len);
	return (ret);
}

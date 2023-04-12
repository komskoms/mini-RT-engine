/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:35:21 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/08 00:47:55 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static int	process_itoa(char **ret, long long arg)
{
	char	number[48];
	int		i;
	int		j;

	i = 0;
	while (arg)
	{
		if (arg < 0)
			number[i++] = '0' - arg % 10;
		else
			number[i++] = arg % 10 + '0';
		arg /= 10;
	}
	*ret = malloc(sizeof(char) * (i + 1));
	(*ret)[i] = '\0';
	j = 0;
	while (i--)
		(*ret)[i] = number[j++];
	return (j);
}

static char	*process_int(t_prf_traits *traits, long long arg)
{
	char	*ret;
	int		neg_flag;
	int		sign_flag;

	neg_flag = (arg < 0) ? 1 : 0;
	sign_flag =
		(traits->flag[FI_PLUS] || traits->flag[FI_BLNK] || neg_flag) ? 1 : 0;
	traits->conv_len = process_itoa(&ret, arg);
	if (traits->precision && !*ret)
		traits->conv_len = prefix_pad_char(&ret, '0', 0, 1);
	if (traits->flag[FI_ZERO] &&
			traits->precision < 0 && traits->precision < traits->width)
		traits->precision = traits->width - sign_flag;
	if (traits->precision > 0)
		traits->conv_len = prefix_pad_char(
			&ret, '0', traits->conv_len, traits->precision - traits->conv_len);
	conversion_add_sign_int(traits, &ret, neg_flag);
	traits->flag[FI_ZERO] = 0;
	conversion_width_arrange(traits, &ret, traits->width - traits->conv_len);
	return (ret);
}

char		*conversion_handler_int(t_prf_traits *traits, va_list ap)
{
	char		*ret;

	ret = NULL;
	if (!traits->length)
		ret = process_int(traits, va_arg(ap, int));
	else if (traits->length == 'l')
		ret = process_int(traits, va_arg(ap, long));
	else if (traits->length == 1)
		ret = process_int(traits, va_arg(ap, long long));
	else if (traits->length == 'h')
		ret = process_int(traits, (short)va_arg(ap, int));
	else if (traits->length == 2)
		ret = process_int(traits, (char)va_arg(ap, int));
	return (ret);
}

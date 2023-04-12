/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler_uint.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:13:53 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/08 14:21:20 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static int	process_itoa_u(char **ret, unsigned long long arg)
{
	char	number[48];
	int		len;
	int		i;
	int		j;

	i = 0;
	while (arg)
	{
		number[i++] = arg % 10 + '0';
		arg /= 10;
	}
	len = i;
	*ret = malloc(sizeof(char) * (i + 1));
	(*ret)[i] = '\0';
	j = 0;
	while (i)
		(*ret)[--i] = number[j++];
	return (len);
}

static int	process_itoa_o(char **ret, unsigned long long arg)
{
	char	number[56];
	int		len;
	int		i;
	int		j;

	i = 0;
	while (arg)
	{
		number[i++] = arg % 8 + '0';
		arg /= 8;
	}
	len = i;
	*ret = malloc(sizeof(char) * (i + 1));
	(*ret)[i] = '\0';
	j = 0;
	while (i)
		(*ret)[--i] = number[j++];
	return (len);
}

static int	process_itoa_x(char **ret, unsigned long long arg, char c)
{
	char	number[48];
	int		len;
	int		i;

	i = 0;
	while (arg)
	{
		if (arg % 16 < 10)
			number[i++] = arg % 16 + '0';
		else if (c == 'x')
			number[i++] = arg % 16 - 10 + 'a';
		else if (c == 'X')
			number[i++] = arg % 16 - 10 + 'A';
		arg /= 16;
	}
	*ret = malloc(sizeof(char) * (i + 1));
	(*ret)[i] = '\0';
	len = 0;
	while (i--)
		(*ret)[i] = number[len++];
	return (len);
}

static char	*process_uint(t_prf_traits *traits, unsigned long long arg)
{
	char	*ret;

	if (traits->conversion == 'u')
		traits->conv_len = process_itoa_u(&ret, arg);
	else if (traits->conversion == 'o')
		traits->conv_len = process_itoa_o(&ret, arg);
	else if (traits->conversion == 'x')
		traits->conv_len = process_itoa_x(&ret, arg, 'x');
	else if (traits->conversion == 'X')
		traits->conv_len = process_itoa_x(&ret, arg, 'X');
	if (traits->precision && !*ret)
		traits->conv_len = prefix_pad_char(&ret, '0', 0, 1);
	if (traits->flag[FI_ZERO] && traits->precision < 0 &&
			traits->precision < traits->width)
		traits->precision = traits->width -
			((arg && traits->flag[FI_SHRP]) ? 2 : 0);
	if (traits->precision > 0)
		traits->conv_len = prefix_pad_char(
			&ret, '0', traits->conv_len, traits->precision - traits->conv_len);
	traits->flag[FI_ZERO] = 0;
	if (arg)
		conversion_add_sign_uint(traits, &ret);
	conversion_width_arrange(traits, &ret, traits->width - traits->conv_len);
	return (ret);
}

char		*conversion_handler_uint(t_prf_traits *traits, va_list ap)
{
	char	*ret;

	ret = NULL;
	if (!traits->length)
		ret = process_uint(traits, va_arg(ap, unsigned int));
	else if (traits->length == 'l')
		ret = process_uint(traits, va_arg(ap, unsigned long));
	else if (traits->length == 1)
		ret = process_uint(traits, va_arg(ap, unsigned long long));
	else if (traits->length == 'h')
		ret = process_uint(traits, (unsigned short)va_arg(ap, int));
	else if (traits->length == 2)
		ret = process_uint(traits, (unsigned char)va_arg(ap, int));
	return (ret);
}

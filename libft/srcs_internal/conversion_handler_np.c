/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler_np.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:48:39 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/14 23:24:26 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

char		*conversion_handler_n(t_prf_traits *traits, va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, int *);
	if (!traits->length)
		*(int *)ptr = (int)traits->ret_len;
	if (traits->length == 'l')
		*(long *)ptr = (long)traits->ret_len;
	if (traits->length == 1)
		*(long long *)ptr = (long long)traits->ret_len;
	if (traits->length == 'h')
		*(short *)ptr = (short)traits->ret_len;
	if (traits->length == 2)
		*(char *)ptr = (char)traits->ret_len;
	return (ft_strdup(""));
}

static int	process_itoa_x(char **ret, unsigned long arg)
{
	char	number[24];
	int		len;
	int		i;

	i = 0;
	while (arg)
	{
		if (arg % 16 < 10)
			number[i++] = arg % 16 + '0';
		else
			number[i++] = arg % 16 - 10 + 'a';
		arg /= 16;
	}
	*ret = malloc(sizeof(char) * (i + 1));
	(*ret)[i] = '\0';
	len = 0;
	while (i--)
		(*ret)[i] = number[len++];
	return (len);
}

char		*conversion_handler_p(t_prf_traits *traits, va_list ap)
{
	char			*ret;

	traits->conv_len = process_itoa_x(&ret, va_arg(ap, unsigned long));
	if (traits->precision && !*ret)
		traits->conv_len = prefix_pad_char(&ret, '0', 0, 1);
	traits->conv_len = prefix_str(&ret, "0x", traits->conv_len);
	conversion_width_arrange(traits, &ret, traits->width - traits->conv_len);
	return (ret);
}

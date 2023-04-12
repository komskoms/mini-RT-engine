/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion_arrange.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:52:05 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/08 00:51:43 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

void		conversion_add_sign_int(
		t_prf_traits *traits, char **str, int neg_flag)
{
	if (neg_flag)
		traits->conv_len = prefix_pad_char(str, '-', traits->conv_len, 1);
	else if (traits->flag[FI_BLNK])
		traits->conv_len = prefix_pad_char(str, ' ', traits->conv_len, 1);
	else if (traits->flag[FI_PLUS])
		traits->conv_len = prefix_pad_char(str, '+', traits->conv_len, 1);
}

void		conversion_add_sign_uint(t_prf_traits *traits, char **str)
{
	if (!traits->flag[FI_SHRP])
		return ;
	if (traits->conversion == 'o')
		traits->conv_len = prefix_pad_char(str, '0', traits->conv_len, 1);
	else if (traits->conversion == 'x')
		traits->conv_len = prefix_str(str, "0x", traits->conv_len);
	else if (traits->conversion == 'X')
		traits->conv_len = prefix_str(str, "0X", traits->conv_len);
}

void		conversion_width_arrange(
		t_prf_traits *traits, char **str, int pad_len)
{
	char	pad_char;

	if (pad_len > 0)
	{
		pad_char = traits->flag[FI_ZERO] ? '0' : ' ';
		if (traits->flag[FI_DASH])
			traits->conv_len = postfix_pad_char(
					str, pad_char, traits->conv_len, pad_len);
		else
			traits->conv_len = prefix_pad_char(
					str, pad_char, traits->conv_len, pad_len);
	}
}

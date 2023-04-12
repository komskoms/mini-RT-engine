/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:24:46 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/08 16:43:44 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

static void	traits_initializer(t_prf_traits *traits)
{
	int		i;

	i = 0;
	while (FLAGS[i])
		traits->flag[i++] = 0;
	traits->width = 0;
	traits->precision = -1;
	traits->length = 0;
	traits->conversion = -1;
	traits->flag_len = 0;
	traits->conv_len = 0;
}

static int	string_append(
		t_prf_traits traits, char **ret, char *str, int org_len)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (org_len + traits.conv_len + 1));
	i = -1;
	while (++i < org_len)
		new[i] = (*ret)[i];
	while (i < org_len + traits.conv_len)
		new[i++] = *str++;
	new[i] = '\0';
	free(*ret);
	*ret = new;
	return (i);
}

int			ft_vasprintf_internal(char **ret, const char *format, va_list ap)
{
	t_prf_traits	traits;
	char			*str;
	unsigned int	idx;

	idx = 0;
	traits.ret_len = 0;
	while (format[idx])
	{
		traits_initializer(&traits);
		if (!(str = format_string_handler(&traits, format + idx, ap)))
		{
			free(*ret);
			*ret = NULL;
			return (-1);
		}
		traits.ret_len = string_append(traits, ret, str, traits.ret_len);
		free(str);
		idx += traits.flag_len;
	}
	return (traits.ret_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:17:22 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/05 16:46:14 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

int		prefix_pad_char(char **str, char pad_char, int org_len, int pad_len)
{
	char	*ret;
	int		i;

	if (pad_len <= 0)
		return (org_len);
	ret = malloc(sizeof(char) * (org_len + pad_len + 1));
	i = 0;
	while (i < pad_len)
		ret[i++] = pad_char;
	i = -1;
	while (++i < org_len)
		ret[pad_len + i] = (*str)[i];
	ret[org_len + pad_len] = '\0';
	free(*str);
	*str = ret;
	return (org_len + pad_len);
}

int		prefix_str(char **str, char *pad_str, int org_len)
{
	char	*ret;
	int		pad_str_len;
	int		ret_len;

	if (!(pad_str_len = ft_strlen(pad_str)))
		return (org_len);
	ret_len = pad_str_len + org_len;
	ret = malloc(sizeof(char) * (ret_len + 1));
	ret[ret_len] = '\0';
	while (org_len--)
		ret[org_len + pad_str_len] = (*str)[org_len];
	while (pad_str_len--)
		ret[pad_str_len] = pad_str[pad_str_len];
	free(*str);
	*str = ret;
	return (ret_len);
}

int		postfix_pad_char(char **str, char pad_char, int org_len, int pad_len)
{
	char	*ret;
	int		i;

	if (pad_len <= 0)
		return (org_len);
	ret = malloc(sizeof(char) * (org_len + pad_len + 1));
	i = -1;
	while (++i < org_len)
		ret[i] = (*str)[i];
	i = 0;
	while (i < pad_len)
		ret[org_len + i++] = pad_char;
	ret[org_len + pad_len] = '\0';
	free(*str);
	*str = ret;
	return (org_len + pad_len);
}

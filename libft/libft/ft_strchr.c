/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:59:26 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/07 01:32:19 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, const int ch)
{
	while (*str != '\0')
	{
		if (*str == (unsigned char)ch)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)ch)
		return ((char *)str);
	return (0);
}

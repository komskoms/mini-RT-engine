/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:47:05 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/12 00:16:27 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	size_t	trim_start;
	size_t	trim_end;
	size_t	i;

	if (s1 == NULL)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	trim_start = i;
	while (s1[i])
		i++;
	if (i == trim_start)
		trim_end = trim_start;
	else
	{
		while (ft_strchr(set, s1[--i]))
			;
		trim_end = i + 1;
	}
	trimed_str = ft_substr(s1, trim_start, trim_end - trim_start);
	return (trimed_str);
}

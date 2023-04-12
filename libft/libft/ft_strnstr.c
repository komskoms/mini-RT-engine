/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 21:32:51 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/12 20:51:52 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	*find_needle(const char *haystack, const char *needle, size_t max)
{
	size_t	i;
	size_t	j;

	if (!*haystack && !*needle)
		return ((char *)haystack);
	max++;
	while (max--)
	{
		i = 0;
		j = 0;
		while (haystack[i++] == needle[j++])
		{
			if (!needle[j])
				return ((char *)haystack);
			if (haystack[i] != needle[j])
				break ;
		}
		haystack++;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	max;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = ft_strlen(haystack);
	max = (i < len) ? i : len;
	if ((i = ft_strlen(needle)) > len)
		return (0);
	max = (max > i) ? max - i : 0;
	return (find_needle(haystack, needle, max));
}

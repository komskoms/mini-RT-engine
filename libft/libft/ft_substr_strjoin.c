/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 21:12:36 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/11 23:54:51 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (start < ft_strlen(s) && s[start] && (size < len))
	{
		start++;
		size++;
	}
	if (!(new_str = malloc(sizeof(char) * (size + 1))))
		return (0);
	new_str[size] = '\0';
	while (size--)
		new_str[size] = s[--start];
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size1;
	size_t	size2;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(new_str = ft_calloc(size1 + size2 + 1, sizeof(char))))
		return (NULL);
	ft_memccpy(new_str, s1, 0, size1);
	ft_memccpy(new_str + size1, s2, 0, size2);
	return (new_str);
}

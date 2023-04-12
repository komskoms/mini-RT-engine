/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <kjhgomtang2@naver.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:34:28 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/04 01:48:02 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		size;
	char	*dst;

	size = 0;
	while (src[size] != '\0')
		size++;
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (0);
	dst[size] = '\0';
	while (size--)
		dst[size] = src[size];
	return (dst);
}

char	*ft_strndup(const char *src, size_t size)
{
	char	*dst;
	size_t	i;

	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

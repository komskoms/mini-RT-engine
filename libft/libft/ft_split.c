/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:47:05 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/12 00:31:25 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	strlen_ch(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (*str != ch && *str)
	{
		str++;
		i++;
	}
	return (i);
}

static size_t	split_next_idx(const char *str, char ch)
{
	size_t	i;

	i = 0;
	while (*str != ch && *str)
	{
		i++;
		str++;
	}
	while (*str == ch && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static void		*free_strs(char **strs, size_t i)
{
	while (i)
		free(strs[--i]);
	free(strs[i]);
	free(strs);
	return (0);
}

static void		delimiter_count(size_t *delimited, const char *s, char c)
{
	size_t	i;

	*delimited = 0;
	i = 0;
	while (s[i])
	{
		(*delimited)++;
		i += split_next_idx(&s[i], c);
	}
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	delimited;
	size_t	i;

	if (!s)
		return (NULL);
	while (*s == c && c != '\0')
		s++;
	delimiter_count(&delimited, s, c);
	if (!(strs = malloc(sizeof(char *) * (delimited + 1))))
		return (0);
	i = 0;
	while (i < delimited)
	{
		if (!(strs[i++] = ft_strndup(s, strlen_ch(s, c))))
			return (free_strs(strs, --i));
		s += split_next_idx(s, c);
	}
	strs[i] = NULL;
	return (strs);
}

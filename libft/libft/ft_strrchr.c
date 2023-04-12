/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:03:15 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/07 14:01:56 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int ch)
{
	char	*start;

	start = (char *)str;
	while (*str)
		str++;
	while (str != start)
	{
		if (*str == (unsigned char)ch)
			return ((char *)str);
		str--;
	}
	if (*str == (unsigned char)ch)
		return ((char *)str);
	return (0);
}

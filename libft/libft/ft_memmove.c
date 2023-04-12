/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:53:28 by jihoon            #+#    #+#             */
/*   Updated: 2020/10/07 00:21:23 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (dest < src)
	{
		while (i < count)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
		while (i++ < count)
			((unsigned char *)dest)[count - i] =
				((unsigned char *)src)[count - i];
	return (dest);
}

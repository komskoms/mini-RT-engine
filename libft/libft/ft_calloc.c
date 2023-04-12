/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 00:37:32 by jihokim           #+#    #+#             */
/*   Updated: 2020/10/03 16:30:30 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

	if (!(mem = malloc(count * size)))
		return (0);
	i = 0;
	while (i < count * size)
		((unsigned char *)mem)[i++] = 0;
	return (mem);
}

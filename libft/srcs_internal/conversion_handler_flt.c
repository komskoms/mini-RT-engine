/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handler_flt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:23:35 by jihokim           #+#    #+#             */
/*   Updated: 2020/12/15 23:40:09 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_conversions.h"

char		*conversion_handler_flt(t_prf_traits *traits, va_list ap)
{
	traits->conversion = va_arg(ap, double);
	return (0);
}

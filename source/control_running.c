/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_running.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:57:55 by jihoon            #+#    #+#             */
/*   Updated: 2021/04/16 19:57:56 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			console_interface(t_vars *v_)
{
	char		*input;

	if (get_next_line(&input, 0) != -1)
	{
		printf("%s\n", input);
		free(input);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_prescene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:54:21 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/14 11:54:22 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variables.h"
#include "util_string.h"
#include "rtfile.h"
#include <stdio.h>

static int		prompt_noarg(t_vars *v_)
{
	char	ch;

	ch = 0;
	while (1)
	{
		printf("no argument : proceed with default scene? (y/n)\n");
		read(0, &ch, 1);
		if (ch == 'y')
		{
			if (!rtfile_read("defaultscene.rt", v_))
				return (0);
			return (1);
		}
		else if (ch == 'n')
		{
			printf("program ends\n");
			exit(0);
		}
		else
			printf("wrong input");
		while (ch != '\n')
			read(0, &ch, 1);
	}
	return (1);
}

int				scene_prepare(int argc, char **argv, t_vars *v_)
{
	if (argc == 1)
	{
		if (!prompt_noarg(v_))
			return (0);
	}
	else
	{
		if (!rtfile_read(argv[1], v_))
			return (0);
	}
	initiate_all(v_);
	return (1);
}

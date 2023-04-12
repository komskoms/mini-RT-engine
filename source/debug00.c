/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:16:14 by jihokim           #+#    #+#             */
/*   Updated: 2021/04/20 15:16:19 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void				print_vec3(t_vec vec[3])
{
	printf("%f %f %f\n", vec[0], vec[1], vec[2]);
}

void				print_material(t_obj_list *head, char *name)
{
	while (head && ft_strncmp(head->name, name, 80))
		head = head->next;
	printf("%s \t %d\t%d\t%f\t/", head->name, head->material.type,
			head->material.texture, head->material.fuzz);
	print_vec3(head->material.color);
}

void				print_material_all(t_obj_list *head)
{
	while (head)
	{
		print_material(head, head->name);
		head = head->next;
	}
}

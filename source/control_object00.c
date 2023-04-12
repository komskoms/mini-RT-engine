/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 11:54:16 by jihokim           #+#    #+#             */
/*   Updated: 2021/03/14 11:54:18 by jihokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_string.h"

void			object_list_print(t_obj_list *head)
{
	while (head)
		printf("name : [%s], type : [%d], ", head->name, head->type);
}

t_obj_list		*object_list_search(t_obj_list *head, char *name)
{
	while (head->name == name)
		head = head->next;
	return (head);
}

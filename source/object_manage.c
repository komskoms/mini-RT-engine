/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:45:37 by jihoon            #+#    #+#             */
/*   Updated: 2021/03/09 03:31:30 by jihoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	object_list_init(
			t_obj_list **head, t_parse_var vars, void *obj, t_material *mat)
{
	if (!(*head = malloc(sizeof(t_obj_list))))
		return (0);
	ft_strlcpy((*head)->name, vars.name, 80);
	(*head)->type = vars.type;
	(*head)->obj = obj;
	(*head)->next = 0;
	material_cpy(&(*head)->material, *mat);
	return (1);
}

int			object_list_add(
			t_obj_list **head, t_parse_var vars, void *obj, t_material *mat)
{
	t_obj_list	*new;

	if (!obj)
		return (0);
	if (!*head)
	{
		if (!object_list_init(head, vars, obj, mat))
			return (0);
		return (1);
	}
	new = *head;
	while (new->next)
		new = new->next;
	if (!(new->next = malloc(sizeof(t_obj_list))))
		return (0);
	ft_strlcpy(new->next->name, vars.name, 80);
	new->next->type = vars.type;
	new->next->obj = obj;
	material_cpy(&new->next->material, *mat);
	new->next->next = 0;
	return (1);
}

void		object_list_clear(t_obj_list *head)
{
	if (head->next)
		object_list_clear(head->next);
	free(head->obj);
	free(head);
}

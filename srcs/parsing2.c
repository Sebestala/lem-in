/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 23:47:42 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/10 18:33:25 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant	*find_final_room(t_ant *ant)
{
	t_ptr	*begin;

	begin = ant->end->tube;
	while(begin != NULL)
	{
		if (begin->ptr_room != ant->start)
			begin->ptr_room->last_room = 1;
		begin = begin->next;
	}
	return (ant);
}

int		verif_name(t_ant *ant, char *name2)
{
	t_ptr	*room;

	room = ant->room;
	while (room != NULL)
	{
		if (!ft_strcmp(room->ptr_room->name, name2))
		{
			room = ant->room;
			return (1);
		}
		room = room->next;
	}
	return (0);
}

void	delete_last_path(t_ant *ant)
{
	t_ptr	*ptr3;
	t_ptr	*ptr2;
	t_ptr	*ptr1;

	ptr1 = ant->path;
	while (ptr1->next != NULL)
		ptr1 = ptr1->next;
	ptr2 = ptr1->ptr_path->id_path;
	while (ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
		memdel_zero(ptr3, sizeof(t_ptr));
	}
	ptr2 = ptr1->ptr_path->room;
	while (ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
		memdel_zero(ptr3, sizeof(t_ptr));
	}
	ptr2 = ptr1->back;
	ptr2->next = NULL;
	memdel_zero(ptr1, sizeof(t_path));
}

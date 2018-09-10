/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:31:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/08/28 17:19:34 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		fct_test(t_ant *ant)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;
	t_room	*room;

	printf("PATH\n");
	fflush(stdout);
	ptr = ant->path;
	ptr2 = ptr->ptr_path->room;
	room = ptr2->ptr_room;
	while (ptr != NULL)
	{
		printf("\n\n	PATH %d \n", ptr->ptr_path->id);
		fflush(stdout);
		ptr2 = ptr->ptr_path->room;
			printf("0\n");
			fflush(stdout);
		while (ptr2 != NULL)
		{
			printf("1\n");
			fflush(stdout);
			room = ptr2->ptr_room;
			printf("	%s\n", room->name);
			fflush(stdout);
			ptr2 = ptr->next;
			printf("2\n");
			fflush(stdout);
		}
			printf("3\n");
			fflush(stdout);
		ptr = ptr->next;
	}

}


static t_ant	*ptr_on_end(t_ant *ant, t_room *room, t_ptr *ptr)
{
	t_ptr	*ptr1;
	t_ptr	*ptr2;

	ptr1 = ant->path;
	while (ptr1->next != NULL)
		ptr1 = ptr1->next;
	ptr2 = ptr1->ptr_path->room;
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	room = ptr2->ptr_room;
	ptr = room->tube;
	ptr = ptr;
	return (ant);
}

static t_ant	*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
printf("make_ptr_path    algorithm\n");
fflush(stdout);
	t_ptr	*struct_ptr;
	t_ptr	*ptr;

	ptr = ant->path;
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_ptr_path");
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (ptr->ptr_path->room->next != NULL)
			ptr->ptr_path->room = ptr->ptr_path->room->next;
		struct_ptr->back = ptr->ptr_path->room;
		ptr->ptr_path->room->next = struct_ptr;
	}
	else
		ptr = struct_ptr;
	struct_ptr->ptr_room = ptr_room;
	return (ant);
}

static t_ant	*del_ptr_path(t_ant *ant)
{
printf("del_ptr_path    algorithm\n");
fflush(stdout);
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr2 = ant->path;
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	while (ptr2->ptr_path->room->next != NULL)
		ptr2->ptr_path->room = ptr2->ptr_path->room->next;
	ptr = ptr2->ptr_path->room;
	ptr2->ptr_path->room->ptr_room->check = 0;
	ptr2->ptr_path->room = ptr2->ptr_path->room->back;
	ptr2->ptr_path->room->next = NULL;
	ft_bzero(ptr, sizeof(t_ptr));
	free(ptr);
	ptr = NULL;
	return (ant);
}

static t_ant	*make_enter_path(t_ant *ant, int i)
{
printf("make_enter_path    algorithm\n");
fflush(stdout);
	t_path	*path;
	t_ptr	*struct_ptr;
	t_ptr	*struct_ptr_in_path;
	t_ptr	*ptr;

	ptr = ant->path;
	path = memalloc_sterr(sizeof(t_path), "make_enter_path");
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_enter_path");
	struct_ptr_in_path = memalloc_sterr(sizeof(t_ptr), "make_enter_path");
	if (ant->path == NULL)
	{
		ant->path = struct_ptr;
		ant->path_begin = struct_ptr;
	}
	else
	{
		while (ptr->next != NULL)
		{
			i++;
			ptr = ptr->next;
		}
		i++;
		ptr->next = struct_ptr;
		struct_ptr->back = ptr;
	}
	struct_ptr->ptr_path = path;
	path->id = i;
	path->room = struct_ptr_in_path;
	struct_ptr_in_path->ptr_room = ant->start;
printf("	path n*%d\n", path->id);
fflush(stdout);
printf("	%s\n", struct_ptr_in_path->ptr_room->name);
fflush(stdout);
	return (ant);
}

t_ant		*valid_path(t_ant *ant)
{
printf("valid_path    algorithm\n");
fflush(stdout);
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr = ant->path;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr2 = ptr->ptr_path->room;
	ant = make_enter_path(ant, 1);
	while (ptr2 != NULL)
	{
		ant = make_ptr_path(ant, ptr2->ptr_room);
		ptr2 = ptr2->next;
	}
	return (ant);
}

static t_ant	*on_end(t_ant *ant, t_room *room, t_ptr *ptr)
{
printf("on_end    algorithm\n");
fflush(stdout);
	ant = make_ptr_path(ant, room);
	ant = valid_path(ant);
	ptr = ptr->back;
	room = ptr->ptr_room;
	room->check++;
	ant = del_ptr_path(ant);
	ant = ptr_on_end(ant, room, ptr);
	return (ant);
}

static t_ant	*find_end(t_ant *ant, t_room *room, t_ptr *ptr)
{
printf("find_end    algorithm\n");
fflush(stdout);
	while (ptr != NULL)
	{
		if (ptr->ptr_room == ant->end)
			break ;
		ptr = ptr->next;
	}
	if (ptr != NULL)
	{
		ant = make_ptr_path(ant, room);
		ant = make_ptr_path(ant, ptr->ptr_room);
		ant = valid_path(ant);
		ant = del_ptr_path(ant);
	}
	else
		exit_str("Error : end's room not find");
	return (ant);
}

t_ant			*deep_way(t_ant *ant)
{
	t_room	*element;
	t_ptr	*ptr;

	element = ant->start;
ant->test = 0;
printf("\n\n\nTEST ==	%d \n", ant->test);
fflush(stdout);
ant->test++;
	ant = make_enter_path(ant, 1);
	while (!(element == ant->start && ptr == NULL))
	{
		ptr = element->tube;
printf("\n\n\nDEBUT TEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
		ant = init_ant(ant);
		element->check++;
		if (element == ant->end)
			ant = on_end(ant, element, ptr);
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
		if (element->last_room == 1 && element != ant->start)
		{
			ant = find_end(ant, element, ptr);
			ant = ptr_on_end(ant, element, ptr);
			element->check++;
			ant = del_ptr_path(ant);
			ant = ptr_on_end(ant, element, ptr);
fct_test(ant);
		}
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
		if (ant->i + 1 < element->check - 1
				&& element->last_room == 0 && ptr != NULL)
			ptr = ptr->next;
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
		if (ptr == NULL)
		{
			ptr = ptr->back;
			element = ptr->ptr_room;
			element->check++;
			ant = del_ptr_path(ant);
		}
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
		if (ptr->ptr_room->check == 0 && ptr->ptr_room->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr->ptr_room);
			element = ptr->ptr_room;
		}
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, element->tube->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
	}
	return (ant);
}

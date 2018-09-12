/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:31:34 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:48:44 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		fct_test3(t_ant *ant)
{
	t_pawn	*pawn;
	t_poss	*poss;
	t_ptr	*ptr;

printf("best_poss  id = %d    nb_path = %d    total_power = %d\n", ant->best_poss->id_poss, ant->best_poss->nb_path, ant->best_poss->total_power);
fflush(stdout);
	poss = ant->best_poss;
	ptr = poss->id_path;
	while (ptr)
	{
		printf("Path {%d}   Power = %d   ptr_path = %p    id_in_path = %d\n", ptr->id, ptr->ptr_path->power, ptr->ptr_path, ptr->ptr_path->id);
		fflush(stdout);
		ptr = ptr->next;
	}
	pawn = ant->pawn;
	printf("\n\nPAWN\n");
	fflush(stdout);
	while (pawn != NULL)
	{
		printf("L%d  check = %d  id-path = %d\n", pawn->id_pawn, pawn->check, pawn->path->id);
		fflush(stdout);
		pawn = pawn->next;
	}
	printf("\n\n");
	fflush(stdout);
}

void		fct_test2(t_ant *ant)
{
	t_ptr	*ptr;
	t_poss	*poss;

	poss = ant->poss;
	printf("POSS\n");
	fflush(stdout);
	while (poss != NULL)
	{
		ptr = poss->id_path;
		printf("\nid_poss = %d   nb_path = %d   power = %d\nID PATHS= ", poss->id_poss, poss->nb_path, poss->total_power);
		fflush(stdout);
		while (ptr != NULL)
		 {
			printf("{%d} ", ptr->id);
			fflush(stdout);
			ptr = ptr->next;
		}
		poss = poss->next;
	}
	printf("\n\n");
	fflush(stdout);
}

void		fct_test1(t_ant *ant)
{
	t_ptr	*ptr;
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_ptr	*ptr4;
	t_room	*room;

	printf("PATH\n");
	fflush(stdout);
	ptr = ant->path;
	ptr2 = ptr->ptr_path->room;
	room = ptr2->ptr_room;
	while (ptr != NULL)
	{
		printf("\n\n	PATH %d   POWER = %d   ID = ", ptr->ptr_path->id, ptr->ptr_path->power);
		fflush(stdout);
		ptr3 = ptr->ptr_path->id_path;
		while (ptr3 != NULL)
		{
			printf("{%d} ", ptr3->id);
			fflush(stdout);
			ptr3 = ptr3->next;
		}
	printf("\n");
	fflush(stdout);
		ptr2 = ptr->ptr_path->room;
		while (ptr2 != NULL)
		{
			room = ptr2->ptr_room;
			printf("	%s   id = ", room->name);
			fflush(stdout);
			ptr4 = room->id_path;
			while (ptr4 != NULL)
			{
				printf("{%d} ", ptr4->id);
				fflush(stdout);
				ptr4 = ptr4->next;
			}
	printf("\n\n");
	fflush(stdout);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	int i = 1;
	printf("NB_PATH = %d  TAB = ", ant->nb_path);
	fflush(stdout);
	while (i <= ant->nb_path)
	{
		printf("[%d] ", ant->tab_id[i]);
		fflush(stdout);
		i++;
	}
	printf("\n\n");
	fflush(stdout);
}

static t_ptr	*ptr_room(t_ptr *ptr, int nb)
{
	int		i;

	i = 1;
	printf("1   ptr = %p\n", ptr);
	fflush(stdout);
	while (ptr->back != NULL)
		ptr = ptr->back;
	printf("2   ptr = %p\n", ptr);
	fflush(stdout);
	while (ptr != NULL && i < nb)
	{
		ptr = ptr->next;
		i++;
	printf("3   ptr = %p\n", ptr);
	fflush(stdout);
	}
	return (ptr);
}

static t_room	*ptr_room_end(t_ant *ant)
{
	t_ptr	*ptr1;
	t_ptr	*ptr2;

	ptr1 = ant->path;
	while (ptr1->next != NULL)
		ptr1 = ptr1->next;
	ptr2 = ptr1->ptr_path->room;
	while (ptr2->next != NULL)
		ptr2 = ptr2->next;
	return (ptr2->ptr_room);
}

static t_ant	*make_ptr_path(t_ant *ant, t_room *ptr_room)
{
printf("make_ptr_path    algorithm\n");
fflush(stdout);
printf("room = %s\n", ptr_room->name);
fflush(stdout);
	t_ptr	*struct_ptr;
	t_ptr	*ptr;
	t_ptr	*ptr2;

	if (ptr_room == ant->start)
		return (ant);
	ptr = ant->path;
	struct_ptr = memalloc_sterr(sizeof(t_ptr), "make_ptr_path");
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr2 = ptr->ptr_path->room;
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		struct_ptr->back = ptr2;
		ptr2->next = struct_ptr;
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
	ptr = ptr2->ptr_path->room;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->ptr_room->check = 0;
	ptr2 = ptr->back;
	ptr2->next = NULL;
	ft_bzero(ptr, sizeof(t_ptr));
	free(ptr);
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
	return (ant);
}

static t_ant	*find_end(t_ant *ant, t_ptr *ptr)
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
	ptr = element->tube;
printf("\n\n\nptr = %p \n", ptr);
fflush(stdout);
	while (element != ant->start || ptr != NULL)
	{
	printf("START\n");
	fflush(stdout);
		ptr = element->tube;
if (ptr)
{
printf("\n\n\nTEST DEBUT == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, ptr->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
}
		element->check++;
		if (element == ant->end)
		{
			ant = on_end(ant, element, ptr);
			element = ptr_room_end(ant);
			ptr = element->tube;
		}
if (ptr)
{
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, ptr->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
}
		if (element->last_room == 1 && element != ant->start)
		{
			ant = find_end(ant, ptr);
			ant = del_ptr_path(ant);
			element = ptr_room_end(ant);
			ptr = element->tube;
			element->check++;
printf("END room = %s   room_ptr = %s\n", element->name, ptr->ptr_room->name);
fflush(stdout);
		}
if (ptr)
{
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, ptr->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
}
		if (element->check > 1 && element->last_room == 0 && ptr != NULL)
			ptr = ptr_room(ptr, element->check);
	printf("4\n");
	fflush(stdout);
if (ptr)
{
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, ptr->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
}
		while (ptr == NULL)
		{
	printf("5\n");
	fflush(stdout);
			if (element == ant->start)
				break ;
	printf("5\n");
	fflush(stdout);
			ant = del_ptr_path(ant);
	printf("5\n");
	fflush(stdout);
			element = ptr_room_end(ant);
	printf("5\n");
	fflush(stdout);
			element->check++;
	printf("5\n");
	fflush(stdout);
			ptr = ptr_room(element->tube, element->check);
	printf("5\n");
	fflush(stdout);
		}
	printf("8\n");
	fflush(stdout);
if (ptr)
{
printf("\n\n\nTEST == %d   NAME ROOM ACTUEL == %s   NAME ROOM TUBE == %s   CHECK = %d\n", ant->test, element->name, ptr->ptr_room->name, element->check);
fflush(stdout);
ant->test++;
printf("check = %d  ptr = %p\n", ptr->ptr_room->check, ptr->ptr_room->tube);
fflush(stdout);
}
	printf("9\n");
	fflush(stdout);
		if (ptr && ptr->ptr_room->check == 0 && ptr->ptr_room->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr->ptr_room);
			element = ptr->ptr_room;
		}
	}
	return (ant);
}

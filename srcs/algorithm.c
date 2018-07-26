#include "../includes/lem_in.h"

static t_ant	make_ptr_path(t_ant ant, t_room *ptr_room)
{
	t_ptr	struct_ptr;

	ft_bzero(&struct_ptr, sizeof(t_ptr));
	while (ant.path->next != NULL)
		ant.path = ant.path->next;
	while (ant.path->ptr_path->room->next != NULL)
		ant.path->ptr_path->room == ant.path->ptr_path->room->next;
	struct_ptr.back = ant.path->ptr_path->room;
	ant.path->ptr_path->room->next = &struct_ptr;
	struct_ptr.ptr_room = ptr_room;
	return (ant);
}

static t_ant	del_ptr_path(t_ant ant)
{
	t_ptr	*ptr;

	while (ant.path->next != NULL)
		ant.path = ant.path->next;
	while (ant.path->ptr_path->room->next != NULL)
		ant.path->ptr_path->room == ant.path->ptr_path->room->next;
	ptr = ant.path->ptr_path->room;
	ant.path->ptr_path->room->ptr_room->check == 0;
	ant.path->ptr_path->room == ant.path->ptr_path->room->back;
	ant.path->ptr_path->room->next == NULL;
	free(ptr);
	ft_bzero(ptr, sizeof(t_ptr));
	ptr = NULL;
	return (ant);
}

static t_ant	make_enter_path(t_ant ant, int i)
{
	t_path	path;
	t_ptr	struct_ptr;
	t_ptr	struct_ptr_in_path;

	ft_bzero(&struct_ptr, sizeof(t_ptr));
	ft_bzero(&struct_ptr_in_path, sizeof(t_ptr));
	ft_bzero(&path, sizeof(t_path));
	if (ant.path == NULL)
		ant.path = &struct_ptr;
	else
	{
		while (ant.path->next != NULL)
		{
			i++;
			ant.path = ant.path->next;
		}
		i++;
		ant.path->next = &struct_ptr;
		struct_ptr.back = ant.path;
	}
	struct_ptr.ptr_path = &path;
	path.id = i;
	path.room = &struct_ptr_in_path;
	struct_ptr_in_path.ptr_room = ant.start;
	return (ant);
}

t_ant		valid_path(t_ant ant)
{
	t_ptr	*ptr;

	while (ant.path->next != NULL)
		ant.path = ant.path->next;
	ptr = ant.path->ptr_path->room;
	ant = make_enter_path(ant, 1);
	while (ptr != NULL)
	{
		ant = make_ptr_path(ant, ptr->ptr_room);
		ptr = ptr->next;
	}
	return (ant);
}

static t_ant	on_end(t_ant ant, t_room *room)
{
	ant = make_ptr_path(ant, room);
	ant = valid_path(ant);
	return (ant);
}

static t_ant	find_end(t_ant ant, t_room *room)
{
	while (room->tube != NULL)
	{
		if (room->tube->ptr_room == ant.end)
			break ;
		room->tube = room->tube->next;
	}
	if (room->tube != NULL)
	{
		ant = make_ptr_path(ant, room);
		ant = make_ptr_path(ant, room->tube->ptr_room);
		ant = valid_path(ant);
		ant = del_ptr_path(ant);
	}
	else
		exit_str("Error : end's room not find");
	return (ant);
}

t_ant			deep_way(t_ant ant)
{
	t_room	*element;
	t_ptr	*ptr;

	element = ant.start;
	ptr = element->tube;
	while (!(element == ant.start && ptr == NULL))
	{
		ptr = element->tube;
		ant = init_ant(ant);
		ant = make_enter_path(ant, 1);
		element->check++;
		if (element == ant.end)
		{
			ant = on_end(ant, element);
			ptr = ptr->back;
			ant = del_ptr_path(ant);

		}
		if (element->last_room == 1 && element != ant.start)//a verifier la condition
		{
			ant = find_end(ant, element);
			ant = del_ptr_path(ant);
		}
		while (ant.i < element->check - 1 &&
							element->last_room == 0 && ptr != NULL)
			ptr = ptr->next;
		if (ptr == NULL)
			ant = del_ptr_path(ant);
		if (ptr->ptr_room->check == 0 && ptr->ptr_room->tube != NULL)
		{
			ant = make_ptr_path(ant, ptr->ptr_room);
			element = ptr->ptr_room;
		}
	}
}

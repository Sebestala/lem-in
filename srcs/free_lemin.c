
#include "../includes/lem_in.h"

void		delete_last_path(t_ant *ant, int i)
{
	t_ptr	*ptr3;
	t_ptr	*ptr2;
	t_ptr	*ptr1;
	t_path	*path;

	ptr1 = ant->path;
	while (ptr1->next != NULL)
		ptr1 = ptr1->next;
	ptr2 = ptr1->ptr_path->id_path;
	while (i > 0)
	{
		while (ptr2 != NULL)
		{
			ptr3 = ptr2;
			ptr2 = ptr2->next;
			memdel_zero(ptr3, sizeof(t_ptr));
		}
		i--;
		ptr2 = ptr1->ptr_path->room;
	}
	if (ptr1->back)
		ptr2 = ptr1->back;
	ptr2->next = NULL;
	path = ptr1->ptr_path;
	memdel_zero(path, sizeof(t_path));
}

void		delete_last_poss(t_ant *ant)
{
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_poss	*poss;
	t_poss	*poss2;

	poss = ant->poss;
	while (poss->next != NULL)
	{
		poss2 = poss;
		poss = poss->next;
	}
	poss2->next = NULL;
	ptr2 = poss->id_path;
	while (ptr2 != NULL)
	{
		ptr3 = ptr2;
		ptr2 = ptr2->next;
		memdel_zero(ptr3, sizeof(t_ptr));
	}
	memdel_zero(poss, sizeof(t_poss));
}

static void	delete_all_poss(t_ant *ant)
{
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_poss	*poss;
	t_poss	*poss2;

	poss = ant->poss;
	while (poss)
	{
		poss2 = poss->next;
		ptr2 = poss->id_path;
		while (ptr2 != NULL)
		{
			ptr3 = ptr2;
			ptr2 = ptr2->next;
			memdel_zero(ptr3, sizeof(t_ptr));
		}
		memdel_zero(poss, sizeof(t_poss));
		poss = poss2;
	}
}

static void	delete_all_pawn(t_ant *ant)
{
	t_pawn	*pawn;
	t_pawn	*pawn2;

	pawn = ant->pawn;
	while (pawn)
	{
		pawn2 = pawn->next;
		memdel_zero(pawn, sizeof(t_pawn));
		pawn = pawn2;
	}
}

static void	delete_all_room(int i, t_ptr *ptr1, t_ptr *ptr2)
{
	t_ptr	*ptr3;
	t_room	*room;

	while (ptr1)
	{
		i = 2;
		room = ptr1->ptr_room;
		ptr2 = room->id_path;
		while (i > 0)
		{
			while (ptr2)
			{
				ptr3 = ptr2;
				ptr2 = ptr2->next;
				memdel_zero(ptr3, sizeof(t_ptr));
			}
			i--;
			ptr2 = room->tube;
		}
		ptr2 = ptr1;
		ptr1 = ptr1->next;
		memdel_zero(ptr2, sizeof(t_ptr));
		ft_strdel(&room->name);
		memdel_zero(room, sizeof(t_room));
	}
}

void		delete_lemin(t_ant *ant)
{
	t_ptr	*ptr;

	delete_all_poss(ant);
	ptr =  ant->path;
	while (ptr->next != NULL)
		ptr = ptr->next;
	while (ptr != NULL)
	{
		ptr = ptr->back;
		delete_last_path(ant, 2);
	}
	delete_all_pawn(ant);
	delete_all_room(2, ant->room, NULL);
	ft_strdel(&ant->line);
	memdel_zero(ant->tab_id, ((ant->nb_path * 50) * sizeof(int)));
	memdel_zero(ant, sizeof(t_ant));
}

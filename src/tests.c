
#include "../includes/lem-in.h"
void		fct_test(t_ant *ant)
{
	t_tab	*ptr;
	t_room	*room;
	t_room	*room0;
	int		i = 0;

	room0 = ant->room;
	printf("ANT  =	%d \n", ant->nb_ant);
	fflush(stdout);
	while (room0 != NULL)
	{
		printf("NAME =	%s    LAST ROOM = %d\n", room0->name, room0->last_room);
		fflush(stdout);
		ptr = room0->tube;
		while (ptr != NULL)
		{
			i = 0;
			while (ptr->tab[i])
			{
				room = ptr->tab[i];
				printf("	%s---%s\n", room0->name, room->name);
				fflush(stdout);
				i++;
			}
			ptr = ptr->next;
		}
	printf("\n");
	fflush(stdout);
		room0 = room0->next;
	}
	ant = init_ant(ant);
	printf("START	name = %s \n", ant->start->name);
	fflush(stdout);
	printf("END	name = %s \n", ant->end->name);
	fflush(stdout);

}

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
/*
	t_room	*room;
	t_poss	*poss1;
	t_path	*path1;
	t_ptr	*ptr1;

	printf("ID IN PTR TUBE ROOM\n");
	fflush(stdout);
	room = ant->room;
	while (room)
	{
		ptr1 = room->tube;
		while (ptr1)
		{
			printf("ID = %d\n", ptr1->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		room = room->next;
	}
	printf("ID IN PATH ROOM\n");
	fflush(stdout);
	path1 = ant->path;
	while (path1)
	{
		ptr1 = path1->room;
			printf("ID PATH = %d \n", path1->id);
			fflush(stdout);
		while (ptr1)
		{
			printf("ID = %d \n", ptr1->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		path1 = path1->next;
	}
	printf("ID IN POSS ID_PATH\n");
	fflush(stdout);
	poss1 = ant->poss;
	while (poss1)
	{
		ptr1 = poss1->id_path;
			printf("ID POSS = %d \n", poss1->id_poss);
			fflush(stdout);
		while (ptr1)
		{
			printf("ID = %d ID IN PATH = %d\n", ptr1->id, ptr1->ptr_path->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		poss1 = poss1->next;
	}

*/


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
	t_path	*path;
	t_room	*room;
	t_tab	*tab;
	int		i = 0;
	int		j = 0;

	printf("PATH\n");
	fflush(stdout);
	path = ant->path;
	tab = path->room;
	while (path != NULL)
	{
		printf("\n\n	PATH %d   POWER = %d   ID = ", path->id, path->power);
		fflush(stdout);
		i = 0; 
		while (path->id_path[i])
		{
			if (path->id_path[i] == '1')
			{
				printf("{%d} ", i);
				fflush(stdout);
			}
			i++;
		}
	printf("\n\n");
	fflush(stdout);
		tab = path->room;
		j = 0;
		while (tab->tab[j])
		{
			i = 0;
			room = tab->tab[j];
			printf("	%s   id = ", room->name);
			fflush(stdout);
			while (room->id_path[i])
			{
				if (room->id_path[i] == '1')
				{
					printf("{%d} ", i);
					fflush(stdout);
				}
				i++;
			}
			j++;
	printf("\n\n");
	fflush(stdout);
		}
		path = path->next;
	}
	int k = 1;
	printf("NB_PATH = %d  TAB = ", ant->nb_path);
	fflush(stdout);
	while (k <= ant->nb_path)
	{
		if (ant->tab_id[k] == '1')
		{
			printf("{%d} ", k);
			fflush(stdout);
		}
		k++;
	}
	printf("\n\n");
	fflush(stdout);
}

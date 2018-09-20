
#include "../includes/lem-in.h"
void		fct_test(t_ant *ant)
{
	t_ptr	*ptr;

	printf("ANT  =	%d \n", ant->nb_ant);
	fflush(stdout);
	while (ant->room != NULL)
	{
		printf("NAME =	%s    LAST ROOM = %d\n", ant->room->name, ant->room->last_room);
		fflush(stdout);
		ptr = ant->room->tube;
		while (ptr != NULL)
		{
			printf("	%s---%s\n", ant->room->name, ptr->ptr_room->name);
			fflush(stdout);
			ptr = ptr->next;
		}
		ant->room = ant->room->next;
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
	t_path	*ptr;
	t_ptr	*ptr2;
	t_ptr	*ptr3;
	t_ptr	*ptr4;
	t_room	*room;

	printf("PATH\n");
	fflush(stdout);
	ptr = ant->path;
	ptr2 = ptr->room;
	room = ptr2->ptr_room;
	while (ptr != NULL)
	{
		printf("\n\n	PATH %d   POWER = %d   ID = ", ptr->id, ptr->power);
		fflush(stdout);
		ptr3 = ptr->id_path;
		while (ptr3 != NULL)
		{
			printf("{%d} ", ptr3->id);
			fflush(stdout);
			ptr3 = ptr3->next;
		}
	printf("\n");
	fflush(stdout);
		ptr2 = ptr->room;
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

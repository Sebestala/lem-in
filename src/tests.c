
#include "../includes/lem-in.h"
void		fct_test(t_ant *ant)
{
	t_tab	*ptr;
	t_room	*room;
	t_room	*room0;
	int		i;

	room0 = ant->room;
	ft_printf("\n ANT  =	%d \n", ant->nb_ant);
	while (room0 != NULL)
	{
		ft_printf(" NAME =	%s   LAST ROOM = %d\n", room0->name, room0->last_room);
		ptr = room0->tube;
		while (ptr != NULL)
		{
			i = 0;
			while (ptr->tab[i])
			{
				room = ptr->tab[i];
				ft_printf("	%s---%s\n", room0->name, room->name);
				i++;
			}
			ptr = ptr->next;
		}
	ft_printf("\n");
		room0 = room0->next;
	}
}
/*
void		fct_test3(t_ant *ant)
{
	t_pawn	*pawn;
	t_poss	*poss;
	t_ptr	*ptr;

fflush(stdout);
	poss = ant->best_poss;
	ptr = poss->id_path;
	while (ptr)
	{
		ft_printf("Path {%d}   Power = %d   ptr_path = %p    id_in_path = %d\n", ptr->id, ptr->ptr_path->power, ptr->ptr_path, ptr->ptr_path->id);
		fflush(stdout);
		ptr = ptr->next;
	}
	pawn = ant->pawn;
	ft_printf("\n\nPAWN\n");
	fflush(stdout);
	while (pawn != NULL)
	{
		ft_printf("L%d  check = %d  id-path = %d\n", pawn->id_pawn, pawn->check, pawn->path->id);
		fflush(stdout);
		pawn = pawn->next;
	}
	ft_printf("\n\n");
	fflush(stdout);

	t_room	*room;
	t_poss	*poss1;
	t_path	*path1;
	t_ptr	*ptr1;

	ft_printf("ID IN PTR TUBE ROOM\n");
	fflush(stdout);
	room = ant->room;
	while (room)
	{
		ptr1 = room->tube;
		while (ptr1)
		{
			ft_printf("ID = %d\n", ptr1->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		room = room->next;
	}
	ft_printf("ID IN PATH ROOM\n");
	fflush(stdout);
	path1 = ant->path;
	while (path1)
	{
		ptr1 = path1->room;
			ft_printf("ID PATH = %d \n", path1->id);
			fflush(stdout);
		while (ptr1)
		{
			ft_printf("ID = %d \n", ptr1->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		path1 = path1->next;
	}
	ft_printf("ID IN POSS ID_PATH\n");
	fflush(stdout);
	poss1 = ant->poss;
	while (poss1)
	{
		ptr1 = poss1->id_path;
			ft_printf("ID POSS = %d \n", poss1->id_poss);
			fflush(stdout);
		while (ptr1)
		{
			ft_printf("ID = %d ID IN PATH = %d\n", ptr1->id, ptr1->ptr_path->id);
			fflush(stdout);
			ptr1 = ptr1->next;
		}
		poss1 = poss1->next;
	}

}
*/
void		fct_test2(t_ant *ant)
{
	t_ptr	*ptr;
	t_poss	*poss;

	poss = ant->poss;
	ft_printf("\n				POSSIBILITY\n");
	while (poss != NULL)
	{
		ptr = poss->id_path;
		ft_printf("\n	POSS N°%d	NB PATH = %d	POWER = %d\n\n	 id paths ="
		, poss->id_poss, poss->nb_path, poss->total_power);
		while (ptr != NULL)
		 {
			ft_printf(" {%d} ", ptr->id);
			ptr = ptr->next;
		}
		ft_printf("\n\n");
		poss = poss->next;
	}
	ft_printf("  BEST POSSIBILITY ===>    ID N°%d	NB PATH = %d	TOTAL POWER"
	"= %d\n", ant->best_poss->id_poss, ant->best_poss->nb_path,
	ant->best_poss->total_power);
	ft_printf("\n\n			-----------------------------\n");
}

void		fct_test1_1(t_path *path, t_tab *tab, int l, int i)
{
	t_room	*room;

	ft_printf("\n\n	PATH %d   POWER = %d   ID = ", path->id, path->power);
	while (path->id_path[i])
	{
		if (path->id_path[i] == '1')
			ft_printf("{%d} ", i);
		i++;
	}
	ft_printf("\n\n");
	tab = path->room;
	while (tab->tab[l])
	{
		i = 0;
		room = tab->tab[l];
		ft_printf("	%s   id = ", room->name);
		while (room->id_path[i])
		{
			if (room->id_path[i] == '1')
				ft_printf("{%d} ", i);
			i++;
		}
		l++;
	ft_printf("\n\n");
	}
}

void		fct_test1(t_ant *ant)
{
	t_tab2	*tab2;
	int		k = 0;
	int		l = 0;

	ft_printf("START =	name = %s\n", ant->start->name);
	ft_printf("END   =	name = %s\n", ant->end->name);
	ft_printf("\n\n			-----------------------------\n");
	ft_printf("\n				   PATHS\n");
	while (ant->path[k])
	{
		tab2 = ant->path[k];
		l = 0;
		while (tab2->tab2[l])
		{
			fct_test1_1(tab2->tab2[l], NULL, l, 0);
			l++;
		}
		k++;
	}
	ft_printf("\n			-----------------------------\n");
}

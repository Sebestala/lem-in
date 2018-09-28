
#include "../includes/lem-in.h"

void		delete_last_path2(t_tab *tab)
{
	t_tab	*ptr;

	while (tab != NULL)
	{
		ptr = tab;
		tab = tab->next;
		memdel_zero(ptr, sizeof(t_tab));
	}
}

void		delete_last_path(t_ant *ant, t_path *ptr1)
{
	t_tab2	*tab2;

	ft_strdel(&ptr1->id_path);
	delete_last_path2(ptr1->room);
	tab2 = ant->path[(ant->path_end->id - 1) / 1000];
	tab2->tab2[(ant->path_end->id - 1) % 1000] = NULL;
	if (ptr1->id == 1)
		ant->path_end = NULL;
	else
		ant->path_end = tab2->tab2[(ant->path_end->id - 2) % 1000];
	memdel_zero(ptr1, sizeof(t_path));
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


#include "../includes/lem-in.h"

void		put_path_in_tab2(t_ant *ant, t_path *path)
{
	t_tab2	*tab;
	int		i;

	i = ant->path_end->id;
	if (i % 1000 == 0)
	{
		tab = memalloc_sterr(sizeof(t_tab2), "make_tab2");
		ant->path[i / 1000] = tab;
	}
	tab = ant->path[i / 1000];
	tab->tab2[i % 1000] = path;
}

void		make_tab2(t_ant *ant, t_path *path)
{
	t_tab2	*tab;

	tab = memalloc_sterr(sizeof(t_tab2), "make_tab2");
	ant->path[0] = tab;
	tab->tab2[0] = path;
}

t_room		*room_in_path_room(t_ant *ant)
{
	t_tab	*tab;

	tab = ant->path_end->room;
	while (tab->next)
		tab = tab->next;
	return (tab->tab[ant->path_end->room_end % 100]);
}

t_room		*room_in_tab_tube(t_room *room)
{
	t_tab	*tab;
	int		nb;

	if (!room)
		return (NULL);
	nb = room->check;
	tab = room->tube;
	while (nb > 99)
	{
		tab = tab->next;
		nb -= 100;
	}
	return (tab->tab[nb]);
}

t_room		*ptr_room(t_ant *ant, t_room *room)
{
	t_room	*ptr;

	ptr = room_in_tab_tube(room);
	if (ptr && ant->path_end->room_end > 1 && ptr->last_room == -1)
	{
		room->check++;
		ptr = ptr->next;
	}
	return (ptr);
}


#include "../includes/lem_in.h"

t_ant		start_poss(t_ant ant)
{
	t_poss	poss;

	ft_bzero(&poss, sizeof(t_poss));
	ant.poss = &poss;
	poss.id_poss = 1;
	poss.nb_path = 1;
	poss.total_power = 0;
	return (ant);
}

t_ant		possibility(t_ant ant)
{
	while (ant.path->next != NULL)
		ant.path = ant.path->next;
	ant.nb_path = ant.path->ptr_path->id;
	ant = start_poss(ant);
	while (ant.poss->nb_path != 0)
	{
		ant.i = ant.path->id;



	}
}

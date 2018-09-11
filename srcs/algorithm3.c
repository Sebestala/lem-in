/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:38:41 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/10 21:52:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		new_ptr_id(t_ant *ant, t_path *path)
{
printf("new_ptr_id    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;
	t_poss	*poss;
	t_ptr	*ptr1;

	poss = ant->poss;
	ptr1 = poss->id_path;
	ptr = memalloc_sterr(sizeof(t_ptr), "new_ptr_id");
	while (poss->next != NULL)
		poss = poss->next;
printf("2   ptr = %p   ptr_poss = %p\n", ptr1, ant->poss);
fflush(stdout);
	if (!ptr1)
		poss->id_path = ptr;
	else
	{
		while (ptr1 && ptr1->next != NULL)
		{
	printf("3\n");
	fflush(stdout);
			ptr1 = ptr1->next;
		}
		ptr->back = ptr1;
		ptr1->next = ptr;
	}
	ptr->ptr_path = path;
	ptr->id = path->id;
}

static t_ant	*new_poss2(t_ant *ant)
{
printf("new_poss2    algorithm3\n");
fflush(stdout);
	t_poss	*poss2;
	t_poss	*poss;

	poss = ant->poss;
	poss2 = memalloc_sterr(sizeof(t_poss), "new_poss2");
	while (poss->next != NULL)
		poss = poss->next;
	poss->next = poss2;
	poss2->id_poss = poss->id_poss + 1;
	poss2->nb_path = poss->nb_path;
	poss2->total_power = poss->total_power;
	return (ant);
}

static t_ant	*start_poss(t_ant *ant)
{
printf("start_poss    algorithm3\n");
fflush(stdout);
	t_poss		*poss;

	poss = memalloc_sterr(sizeof(t_poss), "start_poss");
	ant->poss = poss;
	ant->poss_begin = poss;
	poss->id_poss = 1;
	poss->nb_path = 1;
	poss->total_power = ant->path->ptr_path->power;
	new_ptr_id(ant, ant->path->ptr_path);//utile ?
	ant = new_poss2(ant);// utile ?
	return (ant);
}

static t_poss	*new_value(t_ant *ant, t_poss *poss)
{
printf("new_value    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;

	ptr = poss->id_path;
	ant->i++;
	ant->i = 0;
	poss->nb_path = 0;
	poss->total_power = 0;
	while (ptr != NULL)
	{
		poss->nb_path++;
		poss->total_power += ptr->ptr_path->power;
		ptr = ptr->next;
	}
	return (poss);
}

static t_poss	*modif_tab(t_ant *ant, t_poss *poss, int id)
{
printf("modif_tab    algorithm3\n");
fflush(stdout);
	int		i;
	t_ptr	*ptr;
	t_ptr	*ptr1;

	ptr = poss->id_path;
	ptr1 = ptr->ptr_path->id_path;
	i = 0;
	while (i < id)
	{
		ant->tab_id[i] = 1;
		i++;
	}
	while (ptr != NULL)
	{
		while (ptr1 != NULL)
		{
			ant->tab_id[ptr1->id] = 1;
			ptr1 = ptr1->next;
		}
		ptr = ptr->next;
	}
	return (poss);
}

static t_ant	*del_path(t_ant *ant, t_poss *poss)
{
printf("del_path    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;
	t_ptr	*ptr1;

	ptr1 = poss->id_path;
	while (ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	ptr = ptr1->next;
	ptr1->next = NULL;
	memdel_zero(ptr, sizeof(t_ptr));
	ant->j = ptr1->ptr_path->id + 1;
	return (ant);
}

static void		new_poss(t_ant *ant, int id)
{
printf("new_poss    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;

	ptr = ant->path;
	while (ptr->ptr_path->id != id)
		ptr = ptr->next;
	new_ptr_id(ant, ptr->ptr_path);
	ant = new_poss2(ant);
}

t_ant			*possibility(t_ant *ant)
{
printf("possibility    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;

	ptr = ant->path;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ant->nb_path = ptr->ptr_path->id;
	ant = start_poss(ant);
	while (ant->poss->nb_path != 0)
	{
		ant->poss = new_value(ant, ant->poss);
		ant->poss = modif_tab(ant, ant->poss, ant->j);
		while (1)
		{
			if (ant->tab_id[ant->i] == 0)
			{
				new_poss(ant, ant->i);
				ant->poss = ant->poss->next;
				break ;
			}
			ant->i++;
			if (ant->i > ant->nb_path + 1)
			{
				ant = del_path(ant, ant->poss);
				break ;
			}
		}
	}
	return (ant);
}

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
	ptr = memalloc_sterr(sizeof(t_ptr), "new_ptr_id");
	while (poss->next != NULL)
		poss = poss->next;
	ptr1 = poss->id_path;
	if (!ptr1)
		poss->id_path = ptr;
	else
	{
		while (ptr1 && ptr1->next != NULL)
			ptr1 = ptr1->next;
		ptr->back = ptr1;
		ptr1->next = ptr;
	}
	ptr->ptr_path = path;
	ptr->id = path->id;
}

static t_poss	*new_value(t_ant *ant, t_poss *poss)
{
printf("new_value    algorithm3\n");
fflush(stdout);
	t_ptr	*ptr;

	ptr = poss->id_path;
	ant->i = 1;
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

static t_ant	*copy_poss(t_ant *ant)
{
printf("copy_poss    algorithm3\n");
fflush(stdout);
	t_poss	*copy;
	t_poss	*poss;
	t_ptr	*ptr;

	poss = ant->poss;
	copy = memalloc_sterr(sizeof(t_poss), "new_poss2");
	while (poss->next != NULL)
		poss = poss->next;
	poss = new_value(ant, poss);
	poss->next = copy;
	copy->id_poss = poss->id_poss + 1;
	copy->nb_path = poss->nb_path;
	copy->total_power = poss->total_power;
	ptr = poss->id_path;
	while (ptr != NULL)
	{
		new_ptr_id(ant, ptr->ptr_path);
		ptr = ptr->next;
	}
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
	new_ptr_id(ant, ant->path->ptr_path);
	ant = copy_poss(ant);
	return (ant);
}

static t_poss	*modif_tab(t_ant *ant, t_poss *poss, int id)
{
printf("\n\nmodif_tab    algorithm3    ant-j = %d    i = %d\n\n\n\n", id, poss->id_poss);
fflush(stdout);
	int		i;
	t_ptr	*ptr;
	t_ptr	*ptr2;

	ptr = poss->id_path;
	i = 0;
	while (ant->tab_id[i])
		ant->tab_id[i++] = 0;
	i = 0;
	while (i <= id || i <= poss->id_path->id)
	{
		ant->tab_id[i] = 1;
		i++;
	}
	while (ptr != NULL)
	{
		ptr2 = ptr->ptr_path->id_path;
		while (ptr2 != NULL)
		{
			ant->tab_id[ptr2->id] = 1;
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (poss);
}

static t_ant	*del_path(t_ant *ant, t_poss *poss)
{
printf("del_path    algorithm3      nb_path = %d\n", poss->nb_path);
fflush(stdout);
	t_ptr	*ptr;
	t_ptr	*ptr1;

	poss = new_value(ant, poss);
	ptr1 = poss->id_path;
printf("del   nb_path = %d   ant-j = %d    ant-nbpath = %d    ptr1_id = %d\n", poss->nb_path, ant->j, ant->nb_path, ptr1->id);
fflush(stdout);
fct_test1(ant);
fct_test2(ant);
	if (poss->nb_path == 1/* && ((ant->j >= ant->nb_path) || (ant->j == ptr1->id) || ant->j == 0)*/)
	{
printf("123\n");
fflush(stdout);
		ptr1->id++;
		if (ptr1->id > ant->nb_path)
		{
			poss->nb_path = 0;
			return (ant);
		}
		ptr = ant->path;
		while (ptr && ptr1->id != ptr->ptr_path->id)
			ptr = ptr->next;
		ptr1->ptr_path = ptr->ptr_path;
		ant->j = ptr1->id;
		ant = copy_poss(ant);
		return (ant);
	}
printf("del\n");
fflush(stdout);
	while (ptr1->next->next != NULL)
		ptr1 = ptr1->next;
	ptr = ptr1->next;
	ant->j = ptr->id;
	ptr1->next = NULL;
	memdel_zero(ptr, sizeof(t_ptr));
	return (ant);
}

static void		new_poss(t_ant *ant, int id)
{
printf("new_poss    algorithm3      id = %d\n", id);
fflush(stdout);
	t_ptr	*ptr;

	ptr = ant->path;
	while (ptr->ptr_path->id != id)
		ptr = ptr->next;
	new_ptr_id(ant, ptr->ptr_path);
	ant = copy_poss(ant);
}

t_ant			*possibility(t_ant *ant)
{
printf("possibility    algorithm3\n");
fflush(stdout);
	t_poss	*poss;
	t_ptr	*ptr;

	ptr = ant->path;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ant->nb_path = ptr->ptr_path->id;
	ant->tab_id = memalloc_sterr((ant->nb_path * 50) * sizeof(int), "main");
	ant = start_poss(ant);
	poss = ant->poss->next;
	while (poss->nb_path != 0)
	{
		poss = modif_tab(ant, poss, ant->j);
		ant->i = 1;
		while (1)
		{
			if (ant->tab_id[ant->i] == 0)
			{
				new_poss(ant, ant->i);
				break ;
			}
			ant->i++;
			if (ant->i > ant->nb_path)
			{
				ant = del_path(ant, poss);
				break ;
			}
		}
		if (poss->next != NULL)
			poss = poss->next;
	}
	return (ant);
}

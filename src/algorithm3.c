/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:38:41 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/12 16:45:17 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

static t_path	*del_path2(t_ant *ant, int id)
{
//	printf("del_path2\n");
	t_tab2	*tab2;
	t_path	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j >= 0 && ant->path[i])
	{
		j = 0;
		tab2 = ant->path[i];
		while (j >= 0 && tab2->tab2[j])
		{
			path = tab2->tab2[j];
			if (id == path->id)
				j = -2;
			j++;
		}
		i++;
	}
	return (path);
}

static void		new_ptr_id(t_ant *ant, t_path *path)
{
//	printf("new_ptr_id\n");
	t_ptr	*ptr;
	t_poss	*poss;
	t_ptr	*ptr1;

//	printf("TESTEUH   PATH ID = %d\n", path->id);
//	fflush(stdout);
	poss = ant->poss_end;
	ptr = memalloc_sterr(sizeof(t_ptr), "new_ptr_id");
	ptr1 = poss->id_path;
	while (ptr1 && ptr1->next)
		ptr1 = ptr1->next;
	if (!ptr1)
		poss->id_path = ptr;
	else
		ptr1->next = ptr;
	ptr->ptr_path = path;
	ptr->id = path->id;
}

static t_poss	*new_value(t_ant *ant, t_poss *poss)
{
//	printf("new_value\n");
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
//	printf("copy_poss\n");
	t_poss	*copy;
	t_poss	*poss;
	t_ptr	*ptr;

	poss = ant->poss_end;
	copy = memalloc_sterr(sizeof(t_poss), "new_poss2");
	poss = new_value(ant, poss);
	poss->next = copy;
	ant->poss_end = copy;
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
//	printf("start_poss\n");
	t_poss		*poss;
	t_path		*path;
	t_tab2		*tab2;

	tab2 = ant->path[0];
	path = tab2->tab2[0];
	poss = memalloc_sterr(sizeof(t_poss), "start_poss");
	ant->poss = poss;
	ant->poss_end = poss;
	poss->id_poss = 1;
	poss->nb_path = 1;
//	printf("TEST  id = %d     power = %d\n", path->id, path->power);
//	fflush(stdout);
	poss->total_power = path->power;
	new_ptr_id(ant, path);
	ant = copy_poss(ant);
	return (ant);
}

static t_poss	*modif_tab(t_ant *ant, t_poss *poss, int id)
{
//	printf("modif_tab\n");
	int		i;
	t_ptr	*ptr;

	ptr = poss->id_path;
	i = 0;
	while (i <= ant->nb_path)
		ant->tab_id[i++] = '0';
//	printf("TAB = |%s|   ID = %d     ID_PATH = %d\n", ant->tab_id, id, poss->id_path->id);
//	fflush(stdout);
	i = 0;
	while (i <= id || i <= poss->id_path->id)
		ant->tab_id[i++] = '1';
//	printf("TAB = |%s|   ID = %d     ID_PATH = %d\n", ant->tab_id, id, poss->id_path->id);
//	fflush(stdout);
	while (ptr != NULL)
	{
		i = 0;
		while (ptr->ptr_path->id_path[i])
		{
			if (ptr->ptr_path->id_path[i] == '1')
				ant->tab_id[i] = '1';
			i++;
		}
		ptr = ptr->next;
	}
//	printf("TAB = |%s|   ID = %d     ID_PATH = %d\n", ant->tab_id, id, poss->id_path->id);
//	fflush(stdout);
	return (poss);
}

static t_ant	*del_path(t_ant *ant, t_poss *poss)
{
//	printf("del_path\n");
	t_path	*ptr;
	t_ptr	*ptr1;
	t_ptr	*ptr3;

	poss = new_value(ant, poss);
	ptr1 = poss->id_path;
	if (poss->nb_path == 1)
	{
		ptr1->id++;
		if (ptr1->id > ant->nb_path)
		{
			poss->nb_path = 0;
			return (ant);
		}
		ptr = del_path2(ant, ptr1->id);
		ptr1->ptr_path = ptr;
		ant->j = ptr1->id;
		ant = copy_poss(ant);
		return (ant);
	}
	ptr1 = poss->id_path;
	while (ptr1 && ptr1->next->next)
		ptr1 = ptr1->next;
	ptr3 = ptr1->next;
	ant->j = ptr3->id;
	ptr1->next = NULL;
	memdel_zero(ptr3, sizeof(t_ptr));
	return (ant);
}

static void		new_poss(t_ant *ant, int id)
{
//	printf("new_poss   ANT->I = %d\n", id);
	t_path	*path;
	t_tab2	*tab2;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	ant->j = ant->i;
	while (j >= 0 && ant->path[i])
	{
		j = 0;
		tab2 = ant->path[i];
		while (j >= 0 && tab2->tab2[j])
		{
			path = tab2->tab2[j];
			if (path->id == id)
				j = -2;
			j++;
		}
		i++;
	}
	new_ptr_id(ant, path);
	ant = copy_poss(ant);
}

t_ant			*possibility(t_ant *ant)
{
	t_poss	*poss;

	ant->tab_id = memalloc_sterr((ant->nb_path + 1) * sizeof(char), "main");
	ant = start_poss(ant);
	poss = ant->poss->next;
	while (poss->nb_path != 0)
	{
		poss = modif_tab(ant, poss, ant->j);
		ant->i = 1;
		while (1)
		{
			if (ant->tab_id[ant->i] == '0')
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

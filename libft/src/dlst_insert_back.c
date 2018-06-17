/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_insert_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:52:00 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 21:07:29 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_insert_back(t_node *dlst, int id, char *name)
{
	t_node		*element;
	t_node		*tmp;

	element = ft_memalloc(sizeof(*element));
	if (!element)
		exit_str("Erreur : probleme allocation dynamique.");
	element->name = ft_strdup(name);
	element->id = id;
	element->next = NULL;
	if (dlst_is_empty(dlst))
		return (element);
	tmp = dlst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (dlst);
}

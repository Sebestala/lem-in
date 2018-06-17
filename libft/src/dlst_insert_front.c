/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_insert_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:52:10 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 21:07:39 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_insert_front(t_node *dlst, int id, char *name)
{
	t_node		*element;
	t_node		*tmp;

	element = ft_memalloc(sizeof(element));
	if (!element)
		exit_str("Erreur : probleme allocation dynamique.");
	element->name = ft_strdup(name);
	element->id = id;
	if (dlst_is_empty(dlst))
		element->next = NULL;
	else
		element->next = dlst;
	return (dlst);
}

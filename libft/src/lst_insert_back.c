/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:40 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/15 17:56:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*lst_insert_back(t_lst *lst, int id, char *name)
{
	t_lst		*element;
	t_lst		*tmp;

	element = ft_memalloc(sizeof(*element));
	element->content = name;
	element->id = id;
	element->next = NULL;
	if (lst_is_empty(lst))
		return (element);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

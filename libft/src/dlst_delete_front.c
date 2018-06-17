/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_delete_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:51:46 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 21:07:20 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_delete_front(t_node *dlst)
{
	t_node		*element;

	if (dlst_is_empty(dlst))
		return (NULL);
	element = ft_memalloc(sizeof(element));
	if (!element)
		exit_str("Erreur : probleme allocation dynamique.");
	element = dlst->next;
	free(dlst);
	dlst = NULL;
	return (element);
}

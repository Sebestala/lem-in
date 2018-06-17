/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:36 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/15 18:26:23 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lst_delete_front(t_lst **lst)
{
	t_lst		*element;

	if (lst_is_empty(*lst))
		return ;
	element = ft_memalloc(sizeof(*element));
	if (!element)
		exit_str("Erreur : probleme allocation dynamique.");
	element = *lst;
	*lst = (*lst)->next;
	free(element);
	element = NULL;
}

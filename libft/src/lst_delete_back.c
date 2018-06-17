/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:31 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/15 18:24:34 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		lst_delete_back(t_lst **lst)
{
	t_lst		*before;
	t_lst		*tmp;

	if (lst_is_empty(*lst))
		return ;
	if ((*lst)->next == NULL)
	{
		free(lst);
		lst = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	free(tmp);
	tmp = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_delete_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:51:19 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 20:51:23 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_delete_back(t_node *dlst)
{
	t_node		*before;
	t_node		*tmp;

	if (dlst_is_empty(dlst))
		return (NULL);
	if (dlst->next == NULL)
	{
		free(dlst);
		dlst = NULL;
		return (NULL);
	}
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	free(tmp);
	tmp = NULL;
	return (dlst);
}

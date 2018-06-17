/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:48:50 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 19:21:02 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			lstlen(t_lst *lst)
{
	int		size;

	size = 0;
	if (lst_is_empty(lst))
		return (size);
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

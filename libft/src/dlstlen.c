/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlstlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:52:26 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 20:52:28 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			dlstlen(t_node *dlst)
{
	int		size;

	size = 0;
	if (dlst_is_empty(dlst))
		return (size);
	while (dlst != NULL)
	{
		size++;
		dlst = dlst->next;
	}
	return (size);
}

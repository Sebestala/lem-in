/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:51:03 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 20:51:06 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node		*dlst_delete(t_node *dlst)
{
	if (dlst_is_empty(dlst))
		return (NULL);
	while (dlst != NULL)
		dlst = dlst_delete_front(dlst);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:25 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/15 18:28:11 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_delete(t_lst **lst)
{
	if (lst_is_empty(*lst))
		return ;
	while (*lst != NULL)
		lst_delete_front(lst);
	return ;
}

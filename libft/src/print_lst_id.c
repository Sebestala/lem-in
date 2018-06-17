/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:49:53 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 20:10:01 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_lst_id(t_lst *lst)
{
	if (lst_is_empty(lst))
	{
		ft_putstr("Rien a afficher, la liste est vide.\n");
		return ;
	}
	while (lst != NULL)
	{
		write (1, "[", 1);
		ft_putnbr(lst->id);
		write (1, "] ", 2);
		lst = lst->next;
	}
		write (1, "\n", 1);
}

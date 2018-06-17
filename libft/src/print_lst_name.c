/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:10:14 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/14 19:20:14 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_lst_name(t_lst *lst)
{
	if (lst_is_empty(lst))
	{
		ft_putstr("Rien a afficher, la liste est vide.\n");
		return ;
	}
	while (lst != NULL)
	{
		write (1, "[", 1);
		ft_putstr(lst->name);
		write (1, "] ", 2);
		lst = lst->next;
	}
		write (1, "\n", 1);
}

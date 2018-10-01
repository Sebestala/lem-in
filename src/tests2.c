/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 22:01:51 by sgarcia           #+#    #+#             */
/*   Updated: 2018/10/01 22:05:48 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			fct_test2(t_ant *ant)
{
	t_ptr	*ptr;
	t_poss	*poss;

	poss = ant->poss;
	ft_printf("\n				{-LINE-LIGHT}POSSIBILITY\n\n");
	while (poss != NULL && ant->poss_end->id_poss < 300)
	{
		ptr = poss->id_path;
		rainbow(poss->id_poss);
		ft_printf("\n	{-LIGHT-LINE}POSS N°%d\033[0m	", poss->id_poss);
		rainbow(poss->id_poss);
		ft_printf("NB PATH = %d	POWER = %d\n\n	 {-SHADOW}id paths ="
		, poss->id_poss, poss->nb_path, poss->total_power);
		while (ptr != NULL)
		{
			ft_printf(" \033[0m{-GREEN}{{-YELLOW}%d{-GREEN}} ", ptr->id);
			ptr = ptr->next;
		}
		ft_printf("\n\n");
		poss = poss->next;
	}
	ft_printf("\033[0m {-LINE-ITALIC-LIGHT-GREEN}BEST POSSIBILITY ===>   ID "
	"N°%d	NB PATH = %d	TOTAL POWER = %d\n"
	, ant->best_poss->id_poss, ant->best_poss->nb_path,
	ant->best_poss->total_power);
}

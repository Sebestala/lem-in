/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 19:09:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/10/01 17:49:15 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant			*init_room2(t_ant *ant)
{
	char	*str;

	str = ant->line;
	ant->i++;
	if (str[ant->i] && str[ant->i] >= '0' && str[ant->i] <= '9')
		ant->j++;
	while (str[ant->i] && str[ant->i] >= '0' && str[ant->i] <= '9')
		ant->i++;
	if (str[ant->i] && str[ant->i] == ' ')
		ant->j++;
	if (str[ant->i] && str[ant->i] == ' ')
		ant->i++;
	if (str[ant->i] && str[ant->i] >= '0' && str[ant->i] <= '9')
		ant->j++;
	while (str[ant->i] && str[ant->i] >= '0' && str[ant->i] <= '9')
		ant->i++;
	if (str[ant->i] != '\0' || ant->j != 3)
	{
		ft_putendl(str);
		exit_str("Error : room enter is incorrect");
	}
	ant = init_ant(ant);
	return (ant);
}

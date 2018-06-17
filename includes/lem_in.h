/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:34:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/17 16:31:15 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/src/libft.h"

typedef	struct		s_path
{
	char			*name;
	struct s_path	*next;
}					t_path;

typedef	struct		s_room
{
	int				nm_path;
	char			*name;
	t_path			*path;
	struct s_room	*next;
}					t_room;

typedef	struct		s_ant
{
	int				i;
	int				j;
	int				power;
	int				nb_ant;
	char			*line;
	t_room			*start;
	t_room			*end;
	t_room			*begin;
	t_room			*lst;
	t_room			*room;
}					t_ant;

int					main(void);
t_ant				init_room(t_ant ant);
t_ant				comment(t_ant ant);
int					verif_name(t_ant ant, char *str);

#endif

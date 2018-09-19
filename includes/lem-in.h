/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:34:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/19 19:56:42 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/src/libft.h"

typedef	struct		s_ptr t_ptr;
typedef	struct		s_room t_room;
typedef	struct		s_path t_path;
typedef	struct		s_ant t_ant;
typedef	struct		s_poss t_poss;
typedef	struct		s_pawn t_pawn;

typedef	struct		s_pawn
{
	int				id_pawn;
	int				check;
	t_path			*path;
	struct s_pawn	*next;
	struct s_pawn	*back;
}					t_pawn;

typedef	struct		s_poss
{
	int				id_poss;
	int				nb_path;
	int				total_power;
	t_ptr			*id_path;
	struct s_poss	*next;
}					t_poss;

typedef	struct		s_room
{
	int				check;
	int				last_room;
	char			*name;
	t_ptr			*id_path_end;
	t_ptr			*id_path;
	t_ptr			*tube_end;
	t_ptr			*tube;
}					t_room;

typedef	struct		s_ptr
{
	int				id;
	t_room			*ptr_room;
	t_path			*ptr_path;
	struct s_ptr	*back;
	struct s_ptr	*next;
}					t_ptr;

typedef	struct		s_path
{
	int				id;
	int				power;
	t_ptr			*id_path_end;
	t_ptr			*id_path;
	t_ptr			*room_end;
	t_ptr			*room;
}					t_path;

typedef	struct		s_ant
{
	int				i;
	int				j;
	int				power;
	int				check;
	int				firewall;
	int				nb_ant;
	int				nb_path;
	int				*tab_id;
	char			*line;
	t_poss			*poss;
	t_poss			*best_poss;
	t_room			*start;
	t_room			*end;
	t_ptr			*path;
	t_ptr			*path_end;
	t_ptr			*room;
	t_pawn			*pawn;
}					t_ant;


int					main(void);
t_ant				*init_room(t_ant *ant);
t_ant				*comment(t_ant *ant);
t_ant				*command(t_ant *ant, t_ptr *ptr);
int					verif_name(t_ant *ant, char *name2);
t_ant				*init_ant(t_ant *ant);
t_ant				*find_final_room(t_ant *ant);
t_ant				*deep_way(t_ant *ant);
t_ant				*put_id_path(t_ant *ant);
t_ant				*possibility(t_ant *ant);
t_ant				*choose_best_poss(t_ant *ant);
t_ant				*begin_answer(t_ant *ant);
t_ant				*answer(t_ant *ant);
void				delete_last_path(t_ant *ant, t_ptr *ptr1);
void				delete_last_poss(t_ant *ant);
int					finish(t_ant *ant);
void				delete_lemin(t_ant *ant);
void				fct_test(t_ant *ant);
void				fct_test1(t_ant *ant);
void				fct_test2(t_ant *ant);
void				fct_test3(t_ant *ant);

#endif

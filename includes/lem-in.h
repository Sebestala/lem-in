/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:34:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/09/30 19:12:42 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define MAX_PATH 100000
# include "../libft/src/libft.h"
# include "../libft/src/ft_printf/include/ft_printf.h"

typedef	struct		s_ptr t_ptr;
typedef	struct		s_room t_room;
typedef	struct		s_path t_path;
typedef	struct		s_ant t_ant;
typedef	struct		s_poss t_poss;
typedef	struct		s_pawn t_pawn;
typedef	struct		s_tab t_tab;

typedef	struct		s_tab2
{
	void			*tab2[1001];
}					t_tab2;

typedef	struct		s_tab
{
	void			*tab[101];
	struct s_tab	*next;
}					t_tab;

typedef	struct		s_path
{
	int				id;
	int				power;
	char			*id_path;
	int				room_end;
	t_tab			*room;
}					t_path;

typedef	struct		s_pawn
{
	int				id_pawn;
	int				check;
	t_path			*path;
	struct s_pawn	*next;
	struct s_pawn	*back;
}					t_pawn;

typedef	struct		s_room
{
	int				id;
	int				check;
	int				last_room;
	char			*name;
	char			*id_path;
	int				tube_end;
	t_tab			*tube;
	struct s_room	*next;
}					t_room;

typedef	struct		s_ptr
{
	int				id;
	t_path			*ptr_path;
	struct s_ptr	*next;
}					t_ptr;

typedef	struct		s_poss
{
	int				id_poss;
	int				nb_path;
	int				total_power;
	t_ptr			*id_path;
	struct s_poss	*next;
}					t_poss;

typedef	struct		s_ant
{
	int				i;
	int				j;
	int				power;
	int				bonus;
	int				check;
	int				nb_ant;
	int				nb_path;
	int				*verif;
	char			*tab_id;
	char			*line;
	t_room			*room;
	t_room			*room_end;
	t_room			*start;
	t_room			*end;
	t_tab2			*path[MAX_PATH];
	t_path			*path_end;
	t_poss			*poss;
	t_poss			*poss_end;
	t_poss			*best_poss;
	t_pawn			*pawn;
}					t_ant;


int					main(void);
t_ant				*init_room(t_ant *ant);
t_ant				*comment(t_ant *ant);
t_ant				*command(t_ant *ant);
int					verif_name(t_ant *ant, char *name2);
t_ant				*init_ant(t_ant *ant);
t_ant				*find_final_room(t_ant *ant, int i);
t_ant				*deep_way(t_ant *ant);
t_ant				*put_id_path(t_ant *ant, int j, int k);
t_ant				*possibility(t_ant *ant, t_poss *poss);
t_ant				*choose_best_poss(t_ant *ant);
t_ant				*begin_answer(t_ant *ant);
t_ant				*answer(t_ant *ant);
void				delete_last_path(t_ant *ant, t_path *ptr1);
void				delete_last_poss(t_ant *ant);
int					finish(t_ant *ant);
void				delete_lemin(t_ant *ant);
t_room				*room_in_tab_tube(t_room *room);
t_room				*room_in_path_room(t_ant *ant);
void				make_tab2(t_ant *ant, t_path *path);
t_room				*ptr_room(t_ant *ant, t_room *room);
void				put_path_in_tab2(t_ant *ant, t_path *path);
void				fct_test(t_ant *ant, int i);
void				fct_test1(t_ant *ant);
void				fct_test2(t_ant *ant);
t_ant				*on_end(t_ant *ant);
t_ant				*valid_path(t_ant *ant);
t_ant				*make_enter_path(t_ant *ant);
t_ant				*del_ptr_path(t_ant *ant);
t_ant				*make_ptr_path(t_ant *ant, t_room *ptr_room);
void				put_str_id_path(t_ant *ant, t_room *room, int i, int j);
t_ant				*start_poss(t_ant *ant);
t_ant				*copy_poss(t_ant *ant);
t_poss				*new_value(t_ant *ant, t_poss *poss);
void				new_ptr_id(t_ant *ant, t_path *path);
t_path				*del_path2(t_ant *ant, int id);
void				delete_last_path2(t_tab *tab);
t_ant				*init_struct_room(t_ant *ant);
t_ant				*init_room2(t_ant *ant);
t_ant				*find_end(t_ant *ant, t_room *ptr, t_room *element);

#endif

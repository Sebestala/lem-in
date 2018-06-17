/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:26:43 by sgarcia           #+#    #+#             */
/*   Updated: 2018/06/17 16:31:30 by sgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_dlst
{
	int				len;
	struct s_node	*begin;
	struct s_node	*end;
}					t_dlst;

typedef	struct		s_node
{
	int				id;
	int				statut;
	char			*name;
	struct s_node	*next;
	struct s_node	*back;
}					t_node;

typedef	struct		s_lst
{
	int				id;
	int				statut;
	char			*name;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_bzero(void *s, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putchar_fd(int fd, char c);
void				ft_putnbr(int n);
void				ft_putstr_fd(int fd, char const *s);
void				ft_putstr(char const *s);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_putendl_fd(int fd, char const *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(int fd, int n);
void				ft_lstadd(t_list **alst, t_list *ne);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*strdup_free(char *s1);
int					first_occ_of_char(char *str, char c);
char				*strjoin_free(char const *s1, char const *s2);
char				*strjoin_free1(char *s1, char *s2);
char				*strjoin_free2(char const *s1, char const *s2);
int					get_next_line(const int fd, char **line, int start);
int					atoi_end_index(char **str);
int					atoi_my(char *str);
int					atoi_start_index(char **str);
char				**tabnew(int x, int y);
void				printab(char **tab);
void				printab_fd(char **tab, int fd);
void				tabfree(char ***tab);
char				**tabdup(char **tab);
int					calc_val_absolue(int nb1, char op, int nb2);
int					is_str_on(char *str1, char *str2);
int					is_strn_on(char *str1, char *str2, int len);
void				rainbow(int index);
void				rainbow_back(int index);
void				slow_down(int time);
int					lst_is_empty(t_lst *lst);
void				print_lst_name(t_lst *lst);
int					lstlen(t_lst *lst);
void				print_lst_id(t_lst *lst);
t_lst				*lst_insert_front(t_lst *lst, int id, char *name);
t_lst				*lst_insert_back(t_lst *lst, int id, char *name);
void				lst_delete_front(t_lst **lst);
void				lst_delete_back(t_lst **lst);
void				lst_delete(t_lst **lst);
int					dlst_is_empty(t_node *dlst);
t_node				*dlst_delete_front(t_node *dlst);
void				exit_str(char *str);

#endif

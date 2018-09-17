# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 13:58:01 by sgarcia           #+#    #+#              #
#    Updated: 2018/09/10 18:27:58 by sgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

DIR_S = src/

SRC =		ft_bzero.c				\
			ft_memset.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memcmp.c				\
			ft_atoi.c				\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_strlen.c				\
			ft_strdup.c				\
			ft_strcpy.c				\
			ft_strncpy.c			\
			ft_strcat.c				\
			ft_strncat.c			\
			ft_strlcat.c			\
			ft_strchr.c				\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strnstr.c			\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_strnew.c				\
			ft_strdel.c				\
			ft_strclr.c				\
			ft_striter.c			\
			ft_striteri.c			\
			ft_strequ.c				\
			ft_strnequ.c			\
			ft_strsub.c				\
			ft_strjoin.c			\
			ft_strtrim.c			\
			ft_strsplit.c			\
			ft_itoa.c				\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_lstadd.c				\
			ft_lstnew.c				\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstiter.c			\
			ft_lstmap.c				\
			strdup_free.c			\
			first_occ_of_char.c		\
			strdup_free.c			\
			strjoin_free1.c			\
			strjoin_free2.c			\
			get_next_line.c			\
			atoi_end_index.c		\
			atoi_start_index.c		\
			atoi_my.c				\
			tabnew.c				\
			printab.c				\
			printab_fd.c			\
			tabfree.c				\
			tabdup.c				\
			calc_val_absolue.c		\
			is_str_on.c				\
			is_strn_on.c			\
			rainbow.c				\
			rainbow_back.c			\
			slow_down.c				\
			lst_is_empty.c			\
			print_lst_name.c		\
			lstlen.c				\
			print_lst_id.c			\
			lst_insert_front.c		\
			lst_insert_back.c		\
			lst_delete_front.c		\
			lst_delete_back.c		\
			lst_delete.c			\
			exit_str.c				\
			memalloc_sterr.c		\
			memdel_zero.c			\
			strnew_del.c

DIR_PRINTF = src/ft_printf/

PRINTF	 = libftprintf.a

OBJS = $(addprefix $(DIR_S), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_S)%.o: $(DIR_S)%.c $(DIR_S)libft.h $(DIR_S)get_next_line.h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) -o $@ -c $<

$(PRINTF) :
	make -C $(DIR_PRINTF)
	cp $(DIR_PRINTF)/$(PRINTF) ./$(NAME)
clean:
	make -C $(DIR_PRINTF) clean
	@rm -f $(OBJS)

fclean: clean
	make -C $(DIR_PRINTF) fclean
	@rm -f $(NAME)

re: fclean all

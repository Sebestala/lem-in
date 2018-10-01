# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/30 18:54:40 by sgarcia           #+#    #+#              #
#    Updated: 2018/10/01 22:03:04 by sgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft.a

DLIB = libft/

DSRC = src/

SRC = 	main.c			\
		algorithm.c		\
		algorithm0.c	\
		algorithm0_1.c	\
		algorithm2.c	\
		algorithm2_1.c	\
		algorithm3.c	\
		algorithm3_1.c	\
		algorithm4.c	\
		algorithm4_1.c	\
		parsing.c		\
		parsing2.c		\
		parsing3.c		\
		free_lemin.c	\
		free_lemin2.c	\
		tests.c			\
		tests2.c

OBJ = $(addprefix $(DSRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@cd $(DLIB) && cp $< ../lem-in.a
	@ar rc $(NAME).a $(OBJ)
	@ranlib $(NAME).a
	@$(CC) $(FLAGS) -o $@ $(NAME).a

$(DSRC)%.o : $(DSRC)%.c includes/lem_in.h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIB) : 
	make -C $(DLIB)

clean :
	make -C $(DLIB) clean
	rm -fr $(OBJ)

fclean : clean
	make -C $(DLIB) fclean
	rm -fr $(NAME)
	rm -fr $(NAME).a

re : fclean all

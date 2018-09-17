
NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft.a

DLIB = libft/

DSRC = src/

SRC = 	main.c		\
		algorithm.c	\
		algorithm2.c\
		algorithm3.c\
		algorithm4.c\
		parsing.c	\
		parsing2.c	\
		free_lemin.c

OBJ = $(addprefix $(DSRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	cd $(DLIB) && cp $< ../lem-in.a
	ar rc $(NAME).a $(OBJ)
	ranlib $(NAME).a
	$(CC) $(FLAGS) -o $@ $(NAME).a

$(DSRC)%.o: $(DSRC)%.c includes/$(NAME).h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) -o $@ -c $<

$(LIB): 
	make -C $(DLIB)

clean:
	make -C $(DLIB) clean
	rm -r $(OBJ)

fclean: clean
	make -C $(DLIB) fclean
	rm -r $(NAME)
	rm -r $(NAME).a

re: fclean all

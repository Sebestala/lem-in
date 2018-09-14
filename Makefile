
NAME = lem-in

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft

SRC = $(wildcard *.c)

OBJ = $(addprefix src/, $(SRC:.c=.o))

all : $(NAME)

obj/%.o : %.c include/$(NAME).h
	mkdir obj
	@echo "compilation de $< \033[32m ok \033[0m"
	$(CC) $(FLAGS) -o ./obj/$@ -c $<

$(NAME) : $(OBJ) $(LIB)
	$(CC) -o $@ ./obj/$^
	ranlib $@

$(LIB) : 
	make -C ./$@/
	cp ./$@/$@.a ./obj/

clean :
	make -C $(LIB)/ clean
	rm -rf obj/

fclean : clean
	make -C $(LIB)/ fclean
	rm -rf $(NAME)

re : fclean all

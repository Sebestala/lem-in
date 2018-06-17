C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

DIR_S = srcs/

HEADER = include/

SRC = ft_check_flag.c ft_init_bool.c ft_printf.c ft_stock_s.c ft_strcat_f.c\
	  ft_stock_c.c ft_stock_percent.c ft_stock_lc.c ft_stock_ls.c\
	  ft_stock_ls2.c ft_stock_d.c ft_itoa_base.c ft_stock_lx.c ft_stock_o.c\
	  ft_stock_x.c ft_stock_p.c ft_stock_d2.c ft_stock_u.c ft_stock_b.c\
	  ft_syntax.c ft_man_printf.c ft_man_printf2.c

OBJS = $(addprefix $(DIR_S), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(HEADER)
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(FLAGS) $< -o $@

norme:
	@norminette ./libft/
	@echo
	@norminette ./$(HEADER)/
	@echo
	@norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

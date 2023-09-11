NAME = push_swap

SRC = src/main.c src/split.c src/checks.c src/exit.c src/utils.c

OBJ = $(SRC:.c=.o)

LIBFT = Libft/libft.a

FLAGS = -Wall -Wextra -Werror

INC = includes/

GREEN = \033[38;5;47m
RESET = \033[0m

%.o:%.c
	cc $(FLAGS) -g -c $< -o $(<:.c=.o)

all: $(NAME)
	@echo "$(GREEN)$(NAME) executable created$(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	cc $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/
	make clean -C Libft/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
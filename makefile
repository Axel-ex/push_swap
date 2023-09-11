NAME = push_swap

SRC = src/main.c src/checks.c src/exit.c

OBJ = $(SRC:.c=.o)

LIBFT = Libft/libft.a

FLAGS = -Wall -Wextra -Werror

INC = includes/

%.o:%.c
	cc $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cc $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
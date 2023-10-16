NAME		= push_swap

OBJ_DIR		= obj

SRC_DIR		= src

SRC			= $(wildcard $(SRC_DIR)/*.c)

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIBFT		= Libft/libft.a

FLAGS		= -Wall -Wextra -Werror

INC			= includes/

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@cc $(FLAGS) -g -c $< -o $@
	@echo "[$(GREEN)compiling$(RESET)]: $<"

all: $(NAME)
	@echo "$(GREEN)$(NAME) executable created$(RESET)"

$(NAME): $(OBJ) $(LIBFT)
	@cc $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/
	make clean -C Libft/

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)Removing objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)removing $(NAME) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
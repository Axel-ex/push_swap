NAME		= push_swap

BONUS		= checker

OBJ_DIR		= obj

SRC_DIR		= src

SRC			= $(wildcard $(SRC_DIR)/*.c)

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

OBJ_BONUS	:= $(filter-out obj/main.o, $(OBJ))

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

bonus: $(OBJ_BONUS)
	@cc $(FLAGS) -g bonus/checker.c $(OBJ_BONUS) $(LIBFT) -o checker
	@echo "[$(GREEN)compiling$(RESET)]: checker.c"
	
$(OBJ_DIR):
	@mkdir obj/

$(NAME): $(OBJ) $(LIBFT)
	@cc $(FLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C Libft/
	@make clean -C Libft/

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Removing objects files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make fclean -C Libft/
	@echo "$(RED)removing $(NAME) executable$(RESET)"
	@echo "$(RED)removing $(BONUS) executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re
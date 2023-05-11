NAME = push_swap
NAME_BONUS = checker
FLAGS = -Wall -Werror -Wextra
SRC_DIR = sources
SRC_BONUS_DIR = sources_bonus
SRCS = 	bfs_add_utils.c bfs_cleanup.c bfs_length_utils.c bfs_prune.c \
		breadth_first_search.c define_cheapest_route.c main.c \
		operations_base.c operations_execute.c parsing.c push_back_to_a.c \
		push_to_b.c small_sets.c spaced_arguments.c stack_utils.c validations.c
SRCS_BONUS = 	checker_bonus.c operations_execute.c operations_base.c \
				validations.c parsing.c stack_utils.c spaced_arguments.c debug_utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))
LIBFT_DIR = libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFTNAME):
	@$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_DIR)/$(LIBFTNAME)
	$(CC) $(FLAGS) $^ -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus

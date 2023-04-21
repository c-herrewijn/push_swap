NAME = push_swap
# FLAGS = -Wall -Werror -Wextra
FLAGS = -Wall -Wextra -g
SRC_DIR = sources
SRCS = bfs_add_utils.c bfs_length_utils.c bfs_prune.c breadth_first_search.c debug_utils.c main.c operations.c parsing.c stack_utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIBFT_DIR = libft
LIBFTNAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFTNAME)
	$(CC) $(FLAGS) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFTNAME):
	@$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: test.out
	@./test.out
	@rm ./unit_tests/*.o
	@rm test.out

TEST_SRCS = run_tests.c test_bfs.c test_isinteger.c test_basic_operations.c test_get_staying_numbers.c
TEST_OBJS = $(addprefix unit_tests/, $(TEST_SRCS:.c=.o))

BASE_SRCS = bfs_add_utils.c bfs_length_utils.c bfs_prune.c breadth_first_search.c debug_utils.c operations.c parsing.c stack_utils.c
BASE_OBJS = $(addprefix $(OBJ_DIR)/, $(BASE_SRCS:.c=.o))

unit_tests/%.o: unit_tests/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(FLAGS) $< -o $@

test.out: $(TEST_OBJS) $(BASE_OBJS) $(LIBFT_DIR)/$(LIBFTNAME)
	@$(CC) $(FLAGS) $^ -o test.out

.PHONY: all clean fclean re test

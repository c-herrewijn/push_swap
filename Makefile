NAME = push_swap
FLAGS = -Wall -Werror -Wextra
SRC_DIR = sources
SRCS = main.c utils.c
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

TEST_SRCS = $(addprefix unit_tests/, run_tests.c test_isinteger.c)
TEST_OBJS = $(TEST_SRCS:.c=.o)
test.out: $(TEST_OBJS) $(LIBFT_DIR)/$(LIBFTNAME)
	@$(CC) $(FLAGS) sources/utils.c $^ -o test.out

.PHONY: all clean fclean re test

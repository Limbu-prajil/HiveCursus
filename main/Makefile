# Paths
LIBFT_DIR = ../libft
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_AR = $(LIBFT_DIR)/libft.a

TEST_SRC = $(wildcard test_*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_BIN = $(TEST_SRC:.c=)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Target to create libft.a
$(LIBFT_AR): $(LIBFT_OBJ)
	@ar rcs $@ $^
	@echo "libft.a created in $(LIBFT_DIR)"

# Compile libft sources into object files
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile test sources into object files
%.o: %.c $(LIBFT_AR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Link tests with libft.a
%: %.o $(LIBFT_AR)
	@$(CC) $(CFLAGS) $< -L$(LIBFT_DIR) -lft -o $@

# Run all tests and print results
all_tests: $(LIBFT_AR) $(TEST_BIN)
	@for test in $(TEST_BIN); do \
		echo "Running $$test..."; \
		./$$test; \
	done

# Run specific test
run_test: $(LIBFT_AR)
	@read -p "Enter test file name (without 'test_' prefix): " test_name; \
	test_exec="test_$$test_name"; \
	if [ -x "$$test_exec" ]; then \
		echo "Running $$test_exec..."; \
		./$$test_exec; \
	else \
		echo "Test file '$$test_exec' not found or not compiled."; \
	fi

# Clean object files and test binaries
clean:
	@rm -f $(LIBFT_OBJ) $(TEST_OBJ) $(TEST_BIN)
	@echo "Cleaned object files and test binaries."

# Clean all, including libft.a
fclean: clean
	@rm -f $(LIBFT_AR)
	@echo "Cleaned libft.a."

# Rebuild everything
re: fclean all_tests

.PHONY: all_tests run_test clean fclean re


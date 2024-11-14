# Paths
LIBFT_DIR = ../libft
LIBFT_SRC = ${wildcard ${LIBFT_DIR}/*.c}
LIBFT_OBJ = ${LIBFT_SRC:.c=.o}
LIBFT_AR = ${LIBFT_DIR}/libft.a
LIBFT_HEADER = ${LIBFT_DIR}/libft.h

TEST_SRC = ${wildcard test_*.c}
TEST_OBJ = ${TEST_SRC:.c=.o}
TEST_BIN = ${TEST_SRC:.c=}

CC = cc
CFLAGS = -Wall -Wextra -Werror -I${LIBFT_DIR}

# Target to create libft.a
${LIBFT_AR}: ${LIBFT_OBJ}
	@ar rcs $@ ${LIBFT_OBJ}
	@echo "libft.a created in ${LIBFT_DIR}"

# Compile libft sources into object files
${LIBFT_DIR}/%.o: ${LIBFT_DIR}/%.c ${LIBFT_HEADER}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "Compiled $< to $@"

# Compile each test binary, linking directly with libft.a
${TEST_BIN}: %: %.c ${LIBFT_AR}
	@${CC} ${CFLAGS} $< ${LIBFT_AR} -o $@  # Link each test with libft.a
	@echo "Linked $@ with libft.a"

# Run all tests and print results with line-by-line output for each test
all_tests: ${LIBFT_AR} ${TEST_BIN}
	@for test in ${TEST_BIN}; do \
		echo "Running $$test...................."; \
		./$$test | tee /dev/stderr; \
	done

# Run specific test
run_test: ${LIBFT_AR}
	@read -p "Enter test file name (without 'test_' prefix): " test_name; \
	test_exec="test_$$test_name"; \
	if [ -x "$$test_exec" ]; then \
		echo "Running $$test_exec....................."; \
		./$$test_exec; \
	else \
		echo "Test file '$$test_exec' not found or not compiled."; \
	fi

# Clean object files and test binaries
clean:
	@rm -f ${LIBFT_OBJ} ${TEST_OBJ) ${TEST_BIN}
	@rm -rf *.dSYM
	@echo "Cleaned object files, test binaries, and .dSYM directories."

# Clean all, including libft.a
fclean: clean
	@rm -f ${LIBFT_AR} ${TEST_BIN}
	@echo "Cleaned libft.a and test executables."

# Rebuild everything
re: fclean all_tests

.PHONY: all_tests run_test clean fclean re

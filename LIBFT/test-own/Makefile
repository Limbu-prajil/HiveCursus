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

# Compile libft sources into object files
${LIBFT_DIR}/%.o: ${LIBFT_DIR}/%.c ${LIBFT_HEADER}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "Compiled $< to $@"

# Create static library with libft object files
${LIBFT_AR}: ${LIBFT_OBJ}
	@ar rcs $@ ${LIBFT_OBJ}
	@echo "libft.a created in ${LIBFT_DIR}"

# Compile each test source code (*.c) into test executables (test_exec), linking each directly with libft.a
${TEST_BIN}: %: %.c ${LIBFT_AR}
	@${CC} ${CFLAGS} $< ${LIBFT_AR} -o $@
	@echo "Linked $@ with libft.a"

# Run all tests and save ouput to test_output.log file
all_tests: ${TEST_BIN}
	@echo "Executng all tests and capturing results in test_output.log ..."
	@rm -f test_outut.log
	@for test in ${TEST_BIN}; do \
		echo "Executing $$test......" | tee -a test_output.log; \
		./$$test | tee -a test_output.log; \
	done
	@echo "All tests completed. Check test_output.log for full results."

# Run each specific test
one_test: ${LIBFT_AR} ${TEST_BIN}
	@read -p "Enter test_file_name (without 'test_' prefix): " test_name; \
	test_exec="test_$$test_name"; \
	if [ -x "$$test_exec" ]; then \
		echo "Executing $$test_exec......"; \
		./$$test_exec ${LIBFT_AR}; \
	else \
		echo "Test file '$$test_exec' not found or not compiled."; \
	fi

# Clean object files and test binaries
clean:
	@rm -f ${LIBFT_OBJ} ${TEST_OBJ} ${TEST_BIN} *.log
	@rm -rf *.dSYM
	@echo "Cleaned object files, test executables, and .dSYM directories."

# Clean all, including libft.a
fclean: clean
	@rm -f ${LIBFT_AR}
	@echo "Cleaned libft.a"

# Rebuild after cleaning everything
re: fclean all_tests

# Phony targets
.PHONY: all_tests one_test clean fclean re

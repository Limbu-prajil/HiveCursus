CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = /home/plimbu/Desktop/42Cursus/libft
TESTS_DIR = /home/plimbu/Desktop/42Cursus/libft-tester/src
NORM_OUTPUT = /home/plimbu/Desktop/42Cursus/libft-tester/util/norm_output.txt
HEADER_OUTPUT = /home/plimbu/Desktop/42Cursus/libft-tester/util/head_output.txt

# Library and header
LIBFT = $(LIBFT_DIR)/libft.a
HEADER = $(LIBFT_DIR)/libft.h
TESTER_HEADER = /home/plimbu/Desktop/42Cursus/libft-tester/util/tester.h

# Test files .c
TEST_FILES = $(wildcard $(TESTS_DIR)/test_ft_*.c)

# Funtion file .c
FUNTION_FILES = $(wildcard $(LIBFT_DIR)/ft_*.c)

# Funtion file .c
HEADER_FILES = $(wildcard $(LIBFT_DIR)/*.h)

# exe Names
TEST_EXECUTABLES = $(TEST_FILES:$(TESTS_DIR)/%.c=%)

# Rule for exe
$(TEST_EXECUTABLES): %: $(TESTS_DIR)/%.c $(LIBFT)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(TESTS_DIR) $< -L$(LIBFT_DIR) -lft -o $@

# Colors styling
RED = \033[31m
GREEN = \033[32m
RESET = \033[0m
BLUE = \033[34m
BOLD = \033[1m
CYAN = \033[36m
YELLOW = \033[33m
MAGENTA = \033[35m

# Rule to run all tests and display results
.PHONY: test
test: $(TEST_EXECUTABLES) 
	@echo "$(BOLD)$(CYAN)╔════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║     Running all tests...   $(RESET)║"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════╝$(RESET)"
	@start_time=$$(date +%s%3N); 
	@echo "Start time $$(date)";
	@echo "";
	@results=0; \
	total_tests=$$(echo $(TEST_EXECUTABLES) | wc -w); \
	for test_exec in $^; do \
		echo "$(BOLD)$(BLUE)Running $$test_exec...$(RESET)"; \
		./$$test_exec; \
		if [ $$? -ne 0 ]; then \
			echo "$(RED)=========================$(RESET)"; \
			echo "$(RED)║ $$test_exec failed ║$(RESET)"; \
			echo "$(RED)=========================$(RESET)"; \
			results=$$((results + 1)); \
		else \
			echo "$(GREEN)==========================$(RESET)"; \
			echo "$(BOLD)$(GREEN)║ $$test_exec passed ║$(RESET)"; \
			echo "$(GREEN)==========================$(RESET)"; \
		fi; \
		echo ""; \
	done; \
	echo "$(BOLD)Total tests executed: $(CYAN)$$((total_tests))$(RESET)"; \
	echo "$(BOLD)Total tests failed: $(RED) $$(($$results)) $(RESET)"; \
	echo ""; \
	echo ""; \

# Rule for testing norminette
.PHONY: norm
norm:
	@echo "$(BOLD)$(CYAN)╔════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║   Running norminette...    ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════╝$(RESET)"
	@norminette $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h > $(NORM_OUTPUT) 2>&1; \
	NORM_ERR_COUNT=$$(grep -c 'Error!' $(NORM_OUTPUT)); \
	if [ "$$NORM_ERR_COUNT" -eq 0 ]; then \
		echo "$(GREEN)Norminette check: All files are OK!$(RESET)"; \
	else \
		echo "$(BOLD)Norminette check: $(RED)$$NORM_ERR_COUNT Error found!!$(RESET)"; \
		echo ""; \
		echo "$(RED)FIX THIS:$(RESET)"; \
		echo ""; \
		grep 'Error' $(NORM_OUTPUT) | awk -F 'Error: ' '{print $2}' | sed 's|$(LIBFT_DIR)/||; s|^[[:space:]]*||; s|Error: [A-Z_]* *||' | while read -r line; do \
		echo "$(BOLD)$(MAGENTA)$$line$(RESET)"; \
	done; \
	fi;
	@echo ""

# Rule to run all tests and display results
.PHONY: sum
sum: $(TEST_EXECUTABLES)
	@echo "$(BOLD)$(CYAN)╔════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║           Summary          ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════╝$(RESET)"
	@start_time=$(shell date +%s); 
	@echo "Start time $$(date)";
	@echo "";
	@results=0; \
	leaks=0; \
	norm=0; \
	head=0; \
	total_tests=$$(echo $(TEST_EXECUTABLES) | wc -w); \
	for test_exec in $^; do \
		echo "$(BOLD)$(BLUE)$$test_exec$(RESET)" > /dev/null; \
		./$$test_exec > /dev/null; \
		if [ $$? -ne 0 ]; then \
			test_result="$(RED)[KO]$(RESET)"; \
			results=$$((results + 1)); \
		else \
			test_result="$(GREEN)[OK]$(RESET)"; \
		fi; \
		valgrind --leak-check=full --error-exitcode=69 ./$$test_exec > /dev/null 2>&1; \
		if [ $$? -eq 69 ]; then \
			leak_status="$(RED)LEAKING 💧$(RESET)"; \
			leaks=$$((leaks + 1)); \
		else \
            		leak_status="$(GREEN)[NO LEAK]$(RESET)"; \
		fi; \
		echo "$(BOLD)$$test_exec 	$$test_result	$$leak_status	$(RESET)" | sed 's/test_//'; \
	done; \
	norminette $(FUNTION_FILES) > $(NORM_OUTPUT) /dev/null 2>&1; \
		NORM_ERR_COUNT=$$(grep -c 'Error!' $(NORM_OUTPUT)); \
		if [ "$$NORM_ERR_COUNT" -eq 1 ]; then \
			norm=$$((norm + 1)); \
		fi; \
	norminette -R CheckForbiddenSourceHeader $(HEADER_FILES) > $(HEADER_OUTPUT) /dev/null 2>&1; \
		HEAD_ERR_COUNT=$$(grep -c 'Error!' $(HEADER_OUTPUT)); \
		if [ "$$HEAD_ERR_COUNT" -ne 0 ]; then \
			head=$$((head + 1)); \
		fi; \
	echo ""; \
	echo "$(BOLD)Total tests executed:		$(CYAN)[$$((total_tests))]$(RESET)"; \
	echo "$(BOLD)Total tests failed:		$(RED)[$$(($$results))]$(RESET)"; \
	echo "$(BOLD)Total memory leaks:		$(RED)[$$(($$leaks))]$(RESET)"; \
	echo "$(BOLD)Total norminette error:		$(RED)[$$(($$norm))]$(RESET)"; \
	echo "$(BOLD)Total header error:		$(RED)[$$(($$head))]$(RESET)"; \
	echo "$(RESET)"; \
	echo ""; \
	rm -f $(TEST_EXECUTABLES)
	
.PHONY: clean
clean:
	@rm -f $(TEST_EXECUTABLES)

.PHONY: fclean
fclean: clean
	@rm -f $(LIBFT)

.PHONY: re
re: fclean test

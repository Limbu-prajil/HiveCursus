SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .o
NAME = push_swap
NAME_BON = checker
ifeq ($(BONUS), 1)
NAME = $(NAME_BON)
endif

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -D BONUS=$(BONUS)
DEPFLAGS = -MT $@ -MMD -MP 
LDFLAGS = -Llibft
LDLIBS = -lft

man = main.c init_stack.c do_sort3.c do_push.c push.c swap.c rot.c rerot.c swap.c get_index_min.c get_index_dest.c  whatif_push_ab.c sort.c
bon = main_bonus.c check_bonus.c init_stack.c push.c swap.c rot.c rerot.c swap.c

ifeq ($(DEBUG), 1)
CFLAGS += -g -O0
endif

obj_common = $(common:%.c=%.o)
obj_man = $(man:%.c=%.o)
obj_bon = $(bon:%.c=%.o)

dep = $(obj_common:.o=.d) $(obj_macro:.o=.d) $(obj_man:.o=.d)
dep_bonus = $(obj_common:.o=.d) $(obj_macro:.o=.d) $(obj_bon:.o=.d)


.PHONY: all clean fclean re bonus
.PHONY: FORCE test

all: $(NAME)

#call make in SUBDIR only for its default target: all
#prerequisite FORCE is crucial, as it causes the recipe to be run everytime
#the target is considered -- we have to run libft's make every time, as we have
#to check for changes in its src; the target itself however must not be a
#phony target, otherwise the "calling" rule's recipe would also be run every
#time
libft/libft.a : FORCE
	$(MAKE) -C libft

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

%.o : %.c
#$(directory)/%.o : %.c $(directory)/%.d
%.o : %.c %.d libft/libft.a
	$(COMPILE.c) $(OUTPUT_OPTION) $<


ifeq ($(BONUS), 1)
objects = $(obj_common) $(obj_macro) $(obj_bon)
else
$(obj_macro) : $(obj_man) 
objects = $(obj_common) $(obj_macro) $(obj_man)
endif

$(NAME) : $(objects)
ifeq ($(TEST), 1)
	$(CC) $^ -o $(NAME) $(LDFLAGS) $(LDLIBS) -LLeakSanitizer -llsan
else
	$(CC) $^ -o $(NAME) $(LDFLAGS) $(LDLIBS)
endif

bonus:
	$(MAKE) BONUS=1


clean:
	-$(MAKE) -C libft clean 2> /dev/null
	-rm -f $(obj_common) $(obj_man) $(obj_bon) $(dep) $(dep_bonus)

fclean: clean
	-$(MAKE) -C libft fclean 2> /dev/null
	-rm $(NAME) $(NAME_BON)
	@-rm -rf LeakSanitizer

re: fclean all 

test:
	git clone --recursive https://github.com/mhahnFr/LeakSanitizer.git
	make -C LeakSanitizer

$(dep): 

$(dep_bonus): 

-include $(wildcard $(dep) $(dep_bonus))

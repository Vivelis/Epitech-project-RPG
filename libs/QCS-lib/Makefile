##
## EPITECH PROJECT, 2021
## The Marvelous Libmy
## File description:
## Makefile
##

#library name
LIB	=	libqcs.a

#copy path
HDRDIR	=	../../include

#library sources
SRC	=	sources/chained_list/c_list_index.c	\
		sources/chained_list/c_list.c		\
		sources/my_queue/my_queue.c			\
		sources/my_stack/my_stack.c			\
		sources/qcs_utility.c
HDR	=	includes/c_list.h	\
		includes/my_queue.h	\
		includes/my_stack.h	\
		includes/qcs_utility.h

#Compiler and Linker
CC	= cc
OBJ	=	$(SRC:.c=.o)

#obj file path
BUILDDIR=	obj
SRCDIR	=	my

#tests data
TESTBIN	=	qcs_tests
TESTSRC	=	tests/c_list_unit_tests.c	\
			tests/my_queue_unit_tests.c	\
			tests/my_stack_unit_tests.c
TESTOBJ	=	$(TESTSRC:.c=.o)

#flags
CFLAGS	=	-Wall -Werror -Wextra
IFLAGS	=	-Iincludes
DEBUGFLAGS	=	-g3
TESTFLAGS	=	-lcriterion

#------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#------------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m]% 50s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m]% 50s\n" $< |  tr ' ' '.'

all: $(LIB)

$(LIB): $(OBJ)
	-@cp $(HDR) $(HDRDIR)
	@ar rc $(LIB) $(OBJ)
	@printf "\e[1;36mFinished compiling library\e[0m\n"

clean:
	@rm -f *~
	@rm -f *#
	@rm -f $(OBJ)
	@rm -f $(TESTOBJ)
	@printf "\e[0;33mDeleted all .o in $(LIB)\e[0m\n"

fclean: clean
	@rm -f $(LIB)
	@rm -f $(TESTBIN)
	@printf "\e[0;33mDeleted $(LIB)\e[0m\n"
	-@rm -f $(addprefix $(HDRDIR), $(notdir $(HDR)))
	@printf "\e[1;32mDeleted all .o in $(LIB) and $(LIB)\e[0m\n"

re: fclean all

debug: fclean $(OBJ)
	@$(CC) -o $(LIB) $(OBJ) $(IFLAGS) $(CFLAGS) $(DEBUGFLAGS)
	@echo -e "\e[1;36mFinished compiling $(LIB) $@\e[0m"

lib_unit_tests: $(OBJ) $(TESTOBJ)
	@$(CC) -o $(TESTBIN) $(OBJ) $(TESTOBJ) $(IFLAGS) $(CFLAGS) $(TESTFLAGS)
	@echo -e "\e[1;36mFinished compiling $(TESTBIN) $@\e[0m"

lib_run_tests: lib_unit_tests
	./$(TESTBIN)

.PHONY: all clean fclean re

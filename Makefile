##
## EPITECH PROJECT, 2021
## A Fantastic Epitech Project
## File description:
## Makefile
##

## path for each scripts
SRC			=	$(addprefix src/,				\
				create_things.c					\
				events.c						\
				main_menu.c						\
				pause_menu.c					\
				my_rpg.c						\
				settings.c						\
				increase_pause.c				\
				increase_menu_button.c			\
				manage_button_settings.c		\
				do_rpg.c						\
				manage_files/open_file.c		\
				manage_files/read_file.c		\
				manage_files/write_in_file.c	\
				manage_files/config/config.c	\
				manage_status_menu.c			\
				destroy_things.c				\
				manage_files/saves/get_stats.c		\
				manage_files/saves/get_inventory.c	\
				manage_files/saves/write_item.c		\
				get_map_eh.c						\
				get_map_fc.c						\
				getmap.c							\
				my_str_to_word_array.c				\
				str_array.c							\
				display_map.c						\
				manage_player.c						\
				manage_camera.c						\
				colision.c							\
				manage_enemy.c						\
				movement.c							\
				interact_in_front.c					\
				message.c							\
				stats_text.c						\
				deplacement.c						\
				math.c								\
				manage_heal.c						\
				my_itoa.c							\
				manage_files/saves/save_game.c		\
				special_interaction.c				\
				game_over_menu.c					\
				player_anim.c						\
				step_particles.c					\
				blood_particles.c					\
				)
MAIN		=	src/main.c
TEST		=	tests/unit_test.c
INCLUDEPATH	=	include
TESTOBJ		=	$(TEST:.c=.o)
OBJ			=	$(SRC:.c=.o)
MAINOBJ		=	$(MAIN:.c=.o)

## import lib options
LIBS	=	$(addprefix libs/,	\
			libmy/libmy.a		\
			QCS-lib/libqcs.a	\
			)

## name of the binaries
EXEC		=	my_rpg
DEBUGBIN	=	my_rpg
TESTBIN		=	unit_test

## flags
CFLAGS		=	-Wextra -Wall $(addprefix -I, $(INCLUDEPATH)) -lcsfml-graphics\
				-lcsfml-audio -lcsfml-system -lcsfml-window -lm
LDFLAGS		=	$(foreach lib, $(LIBS), $(addprefix -L, $(dir $(lib)))\
				$(addprefix -l, $(subst lib,,$(basename $(notdir $(lib))))))
DEBUGFLAGS	=	-g3
TESTFLAGS	=	-lcriterion

## compilator
$(CC)	=	gcc

#-------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#-------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m] % 29s\n" $< |  tr ' ' '.'

all: do_libs $(EXEC)

$(EXEC): $(OBJ) $(MAINOBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)
	@echo -e "\e[1;36mFinished compiling $@\e[0m"

do_libs:
	@$(foreach lib, $(LIBS), $(MAKE) -C $(dir $(lib));)

clean:
	@rm -f *#
	@rm -f *~
	@rm -f $(OBJ)
	@rm -f $(MAINOBJ)
	@rm -f $(TESTOBJ)
	@printf "\e[0;33mDeleted all .o of $(EXEC)\e[0m\n"
	@$(foreach lib, $(LIBS), $(MAKE) -C $(dir $(lib)) clean;)
	@echo -e "\e[1;36mDeleted all temporary files\e[0m"

fclean: clean
	@rm -f $(EXEC)
	@rm -f $(DEBUGBIN)
	@rm -f $(TESTBIN)
	@printf "\e[0;33mDeleted $(EXEC) binary\e[0m\n"
	$(foreach lib, $(LIBS), $(MAKE) -C $(dir $(lib)) fclean;)
	@echo -e "\e[1;36mDeleted all temporary files\e[0m"

re: fclean all

debug: CFLAGS += $(DEBUGFLAGS)
debug: fclean do_libs $(OBJ) $(MAINOBJ)
	@$(CC) -o $(DEBUGBIN) $(OBJ) $(MAINOBJ) $(LDFLAGS) $(CFLAGS)
	@echo -e "\e[1;36mFinished compiling $(DEBUGBIN) $@\e[0m"

unit_tests: fclean do_libs $(OBJ)
	@$(CC) -o $(TESTBIN) $(OBJ) $(TEST OBJ) $(LDFLAGS) $(CFLAGS) $(TESTFLAGS)
	@echo -e "\e[1;36mFinished compiling $(TESTBIN) $@\e[0m"

run_tests: unit_tests
	./$(TESTBIN)

update_libmy:
	./update_libmy

.PHONY:	all	do_libs	clean	fclean	re	debug	unit_tests	run_tests	update_libmy

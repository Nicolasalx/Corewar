##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MAIN		=	src/main.c \
				src/op.c \
				src/check_arg_validity.c \
				src/ini_champion_data.c \
				src/create_ref_champion.c

GRAPHICAL	=	src/graphical/create_all_data.c \
				src/graphical/create_window.c \
				src/graphical/update_visualization.c \
				src/graphical/lauch_menu.c \
				src/graphical/create_champion/create_champion.c \
				src/graphical/declaration_graphical.c \
				src/graphical/get_nb_of_champion_processus.c

PARSING 	=	src/parsing/detect_flags.c \
				src/parsing/default_values.c \
				src/parsing/get_info_file.c \
				src/parsing/get_each_option.c

CONVERT		=	src/convert/define_is_little_endian.c \
				src/convert/decode_int.c \
				src/convert/int_to_hex.c \
				src/convert/byte_to_hex.c \
				src/convert/encode_int.c \
				src/convert/pc_arithm.c \
				src/convert/write_int_in_core.c \
				src/convert/core_to_mem.c \
				src/convert/get_int_from_core.c

INSTRUCTION	=	src/instruction/my_sti.c \
				src/instruction/my_live.c \
				src/instruction/my_ld.c \
				src/instruction/my_zjmp.c \
				src/instruction/my_st.c \
				src/instruction/my_add.c \
				src/instruction/my_sub.c \
				src/instruction/my_and.c \
				src/instruction/my_or.c \
				src/instruction/my_xor.c \
				src/instruction/my_ldi.c \
				src/instruction/my_fork.c \
				src/instruction/my_lld.c \
				src/instruction/my_lldi.c \
				src/instruction/my_lfork.c \
				src/instruction/my_aff.c \
				src/instruction/compute_carry.c \
				src/instruction/compute_instruction_arg_value.c \
				src/instruction/is_valid_instruction_arg.c

VM			=	src/vm/lauch_vm.c \
				src/vm/dump_mem_vm.c \
				src/vm/create_all_champion.c \
				src/vm/declaration_vm.c \
				src/vm/place_champion_in_vm.c \
				src/vm/ini_vm.c \
				src/vm/is_champion_alive.c \
				src/vm/kill_all_dead_champion.c \
				src/vm/lauch_simulation.c \
				src/vm/check_dead_champion.c \
				src/vm/declare_alive_champion.c \
				src/vm/execute_instruction.c \
				src/vm/is_instruction_exist.c \
				src/vm/get_param_type.c \
				src/vm/get_instruction.c \
				src/vm/is_valid_reg.c \
				src/vm/set_cooldown_next_instruction.c \
				src/vm/update_champion_pc.c

SRC 		= 	$(MAIN) \
				$(PARSING) \
				$(CONVERT) \
				$(VM) \
				$(INSTRUCTION) \
				$(GRAPHICAL)

# ? -DMY_WARNING
# ? -DSET_NULL_AFTER_FREE
MY_FLAG		=	-DSET_NULL_AFTER_FREE

CFLAGS		=	-W -Wall -Wextra -I ./include -I ./../../include/lib \
				$(MY_FLAG) -lcsfml-system -lcsfml-graphics -lcsfml-window

NAME		=	corewar

LIBPATH		=	../../lib/

LIBNAME		=	../../lib/my_lib.a

SRC_TESTS	=	

RUN_TEST	=	--coverage -lcriterion

NAME_TESTS	=	unit_tests

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	cd $(LIBPATH) && $(MAKE)
	gcc -o $(NAME) $(OBJ) $(LIBNAME) $(CFLAGS)

all: $(NAME)

clean:
	cd $(LIBPATH) && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f gmon.out

fclean: clean
	cd $(LIBPATH) && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all

unit_tests:	SRC := $(patsubst src/main.c%,%,$(SRC))
unit_tests: fclean
	cd $(LIBPATH) && $(MAKE)
	gcc -o $(NAME_TESTS) $(SRC_TESTS) $(SRC) $(LIBNAME) $(CFLAGS) $(RUN_TEST)

tests_run: unit_tests
	./$(NAME_TESTS) --quiet

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

## ? USAGE : make profiling arg="arg_for_my_prog"
profiling: CFLAGS += -pg
profiling: re
	@printf "\e[0m------------------------------\e[0m\n"
	./$(NAME) $(arg)
	@printf "\e[0m------------------------------\e[0m\n"
	gprof $(NAME) gmon.out

debug: CFLAGS += -g3
debug: re
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" --args $(NAME) $(arg)

std_func_used:
	cd $(LIBPATH) && $(MAKE) std_func_used
	$(MAKE) re
	@printf "\n----------| PROGRAM |----------\e[1;96m\n"
	@symbols=$$(nm -D $(NAME) | awk '$$NF ~ /@GLIBC/ {print $$NF}'); \
	for symbol in $$symbols; do \
		if [[ "$$symbol" =~ ^__.* ]]; then \
			continue; \
		elif [ "$$symbol" = "puts@GLIBC_2.2.5" ]; then \
			printf "%s\e[0;1m <- \e[1;91mused in printf\e[1;96m\n" \
			"$${symbol%@*}"; \
		else \
			printf "%s\n" "$${symbol%@*}"; \
		fi; \
	done
	@printf "\e[0m-------------------------------\n\n"

.PHONY: all clean fclean re unit_tests tests_run gcovr profiling debug \
		std_func_used

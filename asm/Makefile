##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	src/main.c \
				src/check_arg_validity.c \
				src/lauch_compilation.c \
				src/get_file_content.c \
				src/remove_all_comment.c \
				src/get_champion_header.c \
				src/find_champion_name.c \
				src/find_champion_comment.c \
				src/is_empty_line.c \
				src/remove_useless_line.c \
				src/check_code_content_validity.c \
				src/interpret_program.c \
				src/define_endian_type.c \
				src/get_label.c \
				src/op.c \
				src/encode_int.c \
				src/compute_size_instruction.c \
				src/get_instruction.c \
				src/get_instruction_arg_value.c \
				src/compute_size_program.c \
				src/write_header_in_file.c \
				src/write_program_in_file.c \
				src/compute_label_value.c \
				src/get_result_file_name.c

# ? -DSET_NULL_AFTER_FREE
# ? -DMY_WARNING
MY_FLAG		=	-DSET_NULL_AFTER_FREE

CFLAGS		=	-W -Wall -Wextra -I ./../include -I ./../include/lib $(MY_FLAG)

NAME		=	asm

LIBPATH		=	../lib/

LIBNAME		=	../lib/my_lib.a

SRC_TESTS	=	../tests/tests_interface.c \
				../tests/tests_asm_error_handling.c \
				../tests/test_main_asm.c \
				../tests/tests_asm_with_weird_file.c \
				../tests/tests_asm_file_content.c

RUN_TEST	=	--coverage -lcriterion

NAME_TESTS	=	unit_tests
INPUT_COR_PATH	=	../tests/input/
CORRECT_COR_PATH=	../tests/correct/

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
	rm -f *.cor
	rm -f $(INPUT_COR_PATH)*.cor
	rm -f $(CORRECT_COR_PATH)*.cor
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
	gcovr --exclude ../tests/
	gcovr --exclude ../tests/ --branches

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

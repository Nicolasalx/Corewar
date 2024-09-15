##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib_Makefile
##

SRCERROR		=	error/error_declaration.c \
					error/my_puterror.c \
					error/my_exit.c \
					error/print_fatal_error_and_exit.c

SRCWARNING		=	warning/my_free_db.c \
					warning/free_board_db.c

SRCBITSHIFT		=	bit_shift/get_bit_value.c \
					bit_shift/set_all_bit_to_zero.c \
					bit_shift/set_bit_to_one.c \
					bit_shift/set_bit_to_zero.c \
					bit_shift/my_memset.c \
					bit_shift/my_memcpy.c \
					bit_shift/my_swap.c

SRCFILE			=	file/count_nb_line.c \
					file/count_lines_size.c \
					file/my_file_to_str.c \
					file/my_filelen.c \
					file/open_file.c \
					file/is_a_dir.c \
					file/my_stat.c

SRCLINKEDLIST	=	linked_list/create_node.c \
					linked_list/append_node.c \
					linked_list/delete_node.c \
					linked_list/remove_node.c \
					linked_list/my_listlen.c \
					linked_list/insert_node.c \
					linked_list/free_linked_list.c \
					linked_list/delete_node_wm.c \
					linked_list/free_linked_list_wm.c \
					linked_list/print_linked_list_wm.c \
					linked_list/for_each_node.c

SRCMANAGEALLOC	=	manage_alloc/register_alloc.c \
					manage_alloc/declaration_alloc.c \
					manage_alloc/free_all_alloc.c \
					manage_alloc/create_container.c \
					manage_alloc/free_all_container.c \
					manage_alloc/force_register_alloc.c

SRCMALLOC		=	malloc/my_malloc.c \
					malloc/malloc_board.c \
					malloc/free_board_fm.c \
					malloc/malloc_str.c \
					malloc/my_str_to_board.c \
					malloc/malloc_array.c \
					malloc/my_str_to_word.c \
					malloc/malloc_adv_board.c \
					malloc/count_size_word.c \
					malloc/my_strdup.c \
					malloc/my_boarddup.c \
					malloc/my_adv_strcat.c \
					malloc/my_adv_strcpy.c \
					malloc/count_size_word_wm.c \
					malloc/my_str_to_word_wm.c \
					malloc/my_calloc.c \
					malloc/malloc_gn_adv_board.c \
					malloc/my_free_fm.c \
					malloc/malloc_gn_board.c

SRCCHAR			=	char/is_alpha.c \
					char/is_alphanum.c \
					char/is_digit.c \
					char/is_lower.c \
					char/is_upper.c \
					char/to_upper.c \
					char/to_lower.c

SRCNUMBER		=	number/my_pow.c \
					number/my_get_nb.c \
					number/get_min_value.c \
					number/get_max_value.c \
					number/count_nb_digit.c \
					number/my_sort.c \
					number/my_put_array.c \
					number/my_put_nb.c \
					number/sum_array.c \
					number/my_nb_to_str.c \
					number/ini_array.c \
					number/my_put_double.c \
					number/my_abs.c \
					number/max_value.c \
					number/min_value.c \
					number/my_delta.c \
					number/my_put_bool.c \
					number/my_double_to_str.c \
					number/my_bool_to_str.c

SRCMANAGEBUFFER	=	manage_buffer/declaration_buffer.c \
					manage_buffer/print_buffer.c \
					manage_buffer/flush_buffer.c

SRCSTRING		=	string/my_putstr.c \
					string/my_strcat.c \
					string/my_strcmp.c \
					string/my_strcpy.c \
					string/my_strlen.c \
					string/is_in_str.c \
					string/my_str_only_cont.c \
					string/my_str_cont_atleast.c \
					string/count_occur.c \
					string/count_nb_word.c \
					string/my_revstr.c \
					string/my_putboard.c \
					string/my_putchar.c \
					string/my_strncmp.c \
					string/shift_str_to_left.c \
					string/my_boardlen.c \
					string/count_nb_word_wm.c \
					string/my_put_fd.c \
					string/my_put_fd_fm.c \
					string/my_strncpy.c \
					string/my_strncat.c \
					string/build_str_fm.c \
					string/my_strchr.c

SRC				=	$(SRCLINKEDLIST) \
					$(SRCMANAGEALLOC) \
					$(SRCMALLOC) \
					$(SRCCHAR) \
					$(SRCNUMBER) \
					$(SRCMANAGEBUFFER) \
					$(SRCSTRING) \
					$(SRCFILE) \
					$(SRCBITSHIFT) \
					$(SRCWARNING) \
					$(SRCERROR)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I../include/lib -O2 -fno-builtin

LIBFLAG		=

NAME		=	my_lib.a

%.o : %.c
	@ gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@ && \
	printf "[\e[92mOK\e[0m] gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@\n" || \
	printf "[\e[1;91mKO\e[0m] gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@\n"

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ) && \
	printf "[\e[92mLINKING OK\e[0m] ar rc $(NAME) $(OBJ)\n" || \
	printf "[\e[1;91mLINKING KO\e[0m] ar rc $(NAME) $(OBJ)\n"

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

shared: LIBFLAG += -fPIC
shared: re clean
	gcc -shared -o $(NAME) $(OBJ)

std_func_used: shared
	@printf "\n------------| LIB |------------\e[1;96m\n"
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
	@rm -f $(NAME)

.PHONY: all clean fclean re shared std_func_used

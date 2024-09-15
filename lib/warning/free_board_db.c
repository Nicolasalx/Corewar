/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** db_free_board
*/

#include "my_error.h"
#include "my_bitshift.h"
#include "my_def.h"
#include "my_malloc.h"
#include "internal/my_container.h"
#include <stdlib.h>

void free_board_db(void **board, char *file, char *line, char *var_name)
{
    if (board != NULL && free_all_alloc_call == false) {
        for (int i = 0; board[i] != NULL; ++i) {
            my_free(board[i]);
        }
        my_free(board);
    } else {
        if (board == NULL) {
            print_error(BOLD_MAGENTA("warning: "), BOLD(file), ":",
            BOLD(line), ": ", BOLD_RED(var_name," is already free\n"));
        }
        if (free_all_alloc_call == true) {
            print_error(BOLD_MAGENTA("warning: "), BOLD(file), ":",
            BOLD(line), ": ", BOLD_RED("free after call 'free_all_alloc'\n"));
        }
    }
}

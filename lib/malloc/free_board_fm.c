/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** free_board
*/

#include "my_malloc.h"
#include <stdlib.h>

void free_board_fm(void **board)
{
    if (board != NULL) {
        for (int i = 0; board[i] != NULL; ++i) {
            my_free(board[i]);
        }
        my_free(board);
    }
}

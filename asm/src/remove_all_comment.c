/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** remove_all_comment
*/

#include "asm.h"
#include "op.h"

static void delete_comment_from_line(
    char **file_content, int i, int *j, bool *in_quote)
{
    if (file_content[i][*j] == '\"') {
        *in_quote = !*in_quote;
    }
    if (not *in_quote && file_content[i][*j] == COMMENT_CHAR) {
        for (; file_content[i][*j] != '\0'; ++*j) {
            file_content[i][*j] = '\0';
        }
    }
}

void remove_all_comment(char **file_content)
{
    bool in_quote = false;

    for (int i = 0; file_content[i] != NULL; ++i) {
        for (int j = 0; file_content[i][j] != '\0'; ++j) {
            delete_comment_from_line(file_content, i, &j, &in_quote);
        }
        in_quote = false;
    }
}

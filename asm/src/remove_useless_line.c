/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** remove_useless_line
*/

#include "asm.h"

static void build_new_file_content(char ***file_content,
    int nb_line, int new_nb_line)
{
    char **new_file_content = my_malloc(sizeof(char *) * (new_nb_line + 1));
    int j = 0;

    for (int i = 0; i < nb_line; ++i) {
        if ((*file_content)[i] != NULL) {
            new_file_content[j] = (*file_content)[i];
            ++ j;
        }
    }
    new_file_content[new_nb_line] = NULL;
    my_free(*file_content);
    *file_content = new_file_content;
}

void remove_useless_line(char ***file_content)
{
    int nb_line = my_boardlen(*file_content);
    int new_nb_line = 0;

    for (int i = 0; (*file_content)[i] != NULL; ++i) {
        if (is_empty_line((*file_content)[i])) {
            my_free((*file_content)[i]);
        } else {
            ++ new_nb_line;
        }
    }
    build_new_file_content(file_content, nb_line, new_nb_line);
}

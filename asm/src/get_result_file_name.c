/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_result_file_name
*/

#include "asm.h"

char *get_result_file_name(const char *src_file_name)
{
    int size_file_name = my_strlen(src_file_name);
    char *result_file = my_calloc(size_file_name +
        my_strlen(RESULT_FILE_EXTENSION) + 1);

    my_strcpy(result_file, src_file_name);
    if (size_file_name >= 2 && result_file[size_file_name - 1] == 's'
        && result_file[size_file_name - 2] == '.') {
        result_file[size_file_name - 1] = '\0';
        result_file[size_file_name - 2] = '\0';
        my_strcat(result_file, RESULT_FILE_EXTENSION);
    }
    return result_file;
}

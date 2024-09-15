/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_a_dir
*/

#include "my_error.h"
#include "my_managealloc.h"
#include "my_file.h"
#include <sys/stat.h>
#include <stdbool.h>

bool is_a_dir(const char *path)
{
    struct stat st;

    if (my_stat(path, &st) != 0) {
        free_all_alloc();
        print_fatal_error_and_exit(STAT_FAIL);
    }
    return S_ISDIR(st.st_mode);
}

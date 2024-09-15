/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_db_free
*/

#include "my_error.h"
#include "my_bitshift.h"
#include "my_def.h"
#include "internal/my_container.h"
#include <stdlib.h>

void my_free_db(void *data, char *file, char *line, char *var_name)
{
    void **register_ptr;

    if (data != NULL && free_all_alloc_call == false) {
        data -= sizeof(void *);
        my_memcpy(&register_ptr, data, sizeof(void *));
        *register_ptr = NULL;
        free(data);
        data = NULL;
    } else {
        if (data == NULL) {
            print_error(BOLD_MAGENTA("warning: "), BOLD(file), ":",
            BOLD(line), ": ", BOLD_RED(var_name," is already free\n"));
        }
        if (free_all_alloc_call == true) {
            print_error(BOLD_MAGENTA("warning: "), BOLD(file), ":",
            BOLD(line), ": ", BOLD_RED("free after call 'free_all_alloc'\n"));
        }
    }
}

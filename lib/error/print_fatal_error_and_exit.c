/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** print_fatal_error_and_exit
*/

#include "my_error.h"
#include "my_def.h"

void print_fatal_error_and_exit(int error)
{
    if (error >= 0 && error < size_error_info) {
        print_error("Fatal error: ", RED(error_info[error].message), "\n");
    } else {
        my_puterror("Unnamed error\n");
    }
    my_exit(error_info[error].return_value);
}

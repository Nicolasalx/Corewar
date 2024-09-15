/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_puterror
*/

#include "my_string.h"
#include <unistd.h>

void my_puterror(const char *str)
{
    write(2, str, my_strlen(str));
}

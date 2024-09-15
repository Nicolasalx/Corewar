/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_put_fd
*/

#include <unistd.h>
#include "my_string.h"

void my_put_fd(int fd, char *str)
{
    write(fd, str, my_strlen(str));
}

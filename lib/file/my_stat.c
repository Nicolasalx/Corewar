/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_stat
*/

#include <sys/stat.h>
#include <stdint.h>

int my_stat(const char *path, struct stat *buff)
{
    long int result;

    __asm__ (
        "syscall;"
        : "=a" (result)
        : "a" (0x04), "D" (path), "S" (buff)
        : "rcx", "r11", "memory"
    );
    return result;
}

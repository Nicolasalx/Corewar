/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strncmp
*/

#include "my_string.h"
#include "my_number.h"

int my_strncmp(const char *str1, const char *str2, int n)
{
    int size_str1 = my_strlen(str1);
    int size_str2 = my_strlen(str2);
    int size_str = min_value(size_str1, size_str2);

    if (size_str < n) {
        return 84;
    }
    for (int i = 0; i < n; ++i) {
        if (str1[i] > str2[i]) {
            return 1;
        } if (str1[i] < str2[i]) {
            return -1;
        }
    }
    return 0;
}

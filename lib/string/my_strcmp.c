/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include "my_string.h"
#include "my_number.h"

int my_strcmp(const char *str1, const char *str2)
{
    int size_str1 = my_strlen(str1);
    int size_str2 = my_strlen(str2);
    int size_str = min_value(size_str1, size_str2);

    for (int i = 0; i < size_str; ++i) {
        if (str1[i] > str2[i]) {
            return 1;
        } if (str1[i] < str2[i]) {
            return -1;
        }
    }
    if (size_str1 > size_str2) {
        return 1;
    } else if (size_str1 < size_str2) {
        return -1;
    } else {
        return 0;
    }
}

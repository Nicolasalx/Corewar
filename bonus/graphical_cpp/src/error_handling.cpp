/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** error_handling
*/

#include <string>
#include "my.hpp"

int error_handling(int argc)
{
    if (argc != 2) {
        put_error("Failed to get file.");
        return 84;
    }
    return 0;
}

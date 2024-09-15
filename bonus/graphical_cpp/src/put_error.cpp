/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** put_error
*/

#include <string>
#include "my.hpp"
#include <iostream>

void put_error(const std::string &message)
{
    std::cerr << message << "\n";
}


/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** get_buffer_file
*/

#include "my.hpp"
#include <string>
#include <fstream>
#include <iostream>

std::string get_buffer_from_file(const std::string &filename)
{
    std::ifstream file(filename);
    std::string content;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        
        file.close();
    } else {
        std::cout << "Failed to open the file: " << filename << "\n";
    }

    return content;
}

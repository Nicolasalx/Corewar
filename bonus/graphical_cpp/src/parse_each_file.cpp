/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** parse_each_file
*/

#include <string>
#include "my.hpp"

void parse_each_file(const std::string filepath, my_linked_list_t &my_linked_list)
{
    const std::string filename = filepath;
    std::string file_content = get_buffer_from_file(filename);
    list_len = 0;
    add_linked_file_content(my_linked_list, file_content);
    my_linked_list.parse_each_line();

    if (info_program[index_info_prog].name.size() <= 1) {
        put_error("Failed to get name");
        exit(84);
    }

    if (info_program[index_info_prog].comment.size() <= 1) {
        put_error("Failed to get comment.");
        exit(84);
    }

    info_program[index_info_prog].filepath = filepath;

    for (int i = 0; i < list_len; ++i) {
        my_linked_list.remove();
    }
    ++index_info_prog;
}

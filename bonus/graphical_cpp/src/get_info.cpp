/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** get_info
*/

#include <string>
#include "my.hpp"

static std::string get_info_name(const std::string str)
{
    std::string name = "";
    name = extract_string_beetween_quotes(str);
    return name;
}

static std::string get_info_comment(const std::string str)
{
    std::string comment = "";
    comment = extract_string_beetween_quotes(str);
    return comment;
}

static void search_info(const std::string str)
{
    std::string name = ".name";
    std::string comment = ".comment";

    size_t position_name = str.find(name);
    size_t position_comment = str.find(comment);

    if (position_name != std::string::npos) {
        info_program[index_info_prog].name = get_info_name(str);
        return;
    }
    if (position_comment != std::string::npos) {
        info_program[index_info_prog].comment = get_info_comment(str);
        return;
    }

    info_program[index_info_prog].instruction.push_back(str);
}

void my_linked_list_t::parse_each_line(void)
{
    node *current = head;
    while (current != nullptr) {
        search_info(current->data);
        current = current->next;
    }
}

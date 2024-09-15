/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** linked
*/

#include <iostream>
#include <string>
#include "my.hpp"
#include <sstream>

node::node(const std::string &value)
{
    data = value;
    next = nullptr;
}

my_linked_list_t::my_linked_list_t(void)
{
    head = nullptr;
}

void my_linked_list_t::insert(const std::string &value)
{
    node *new_node = new node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void my_linked_list_t::remove(void)
{
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    
    node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    
    delete current->next;
    current->next = nullptr;
}

void my_linked_list_t::printList(void)
{
    node *current = head;
    while (current != nullptr) {
        std::cout << current->data << "\n";
        current = current->next;
    }
    std::cout << "\n";
}

void add_linked_file_content(my_linked_list_t &my_linked_list, std::string file_content)
{
    std::istringstream iss(file_content);
    std::string line;
    while (std::getline(iss, line, '\n')) {
        my_linked_list.insert(line);
        ++list_len;
    }
}

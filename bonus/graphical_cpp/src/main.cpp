/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** parser
*/

#include "my.hpp"

int main(int argc, char *argv[])
{
    my_linked_list_t my_linked_list;

    if (error_handling(argc) != 0) {
        return 84;
    }
    choose_random_player(argv, my_linked_list);
    setup_game();
    return 0;
}
/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_each_option
*/

#include "corewar.h"

void get_nb_cycle(const char *str)
{
    if (parsing_corewar.already_dump == true) {
        my_puterror("You have already put a nb of cycle.\n");
        my_exit(84);
    }
    if (str == NULL) {
        my_puterror("Failed to get string of nb cycle.\n");
        my_exit(84);
    }
    parsing_corewar.nbr_cycle = my_get_nb(str);
    if (parsing_corewar.nbr_cycle < 0) {
        my_puterror("Invalid number of cycle.\n");
        my_exit(84);
    }
    if (parsing_corewar.nbr_cycle == 0 && my_strcmp(str, "0") != 0) {
        my_puterror("Failed to get_nbr.\n");
        my_exit(84);
    }
    parsing_corewar.already_dump = true;
}

void get_nb_prog_number(const char *str)
{
    if (str == NULL) {
        my_puterror("Failed to get string of nb prog.\n");
        my_exit(84);
    }
    tmp_parsing.prog_number = my_get_nb(str);
    if (tmp_parsing.prog_number <= 0) {
        my_puterror("Invalid number of prog.\n");
        my_exit(84);
    }
    if (tmp_parsing.prog_number == 0 && my_strcmp(str, "0") != 0) {
        my_puterror("Failed to get_nbr.\n");
        my_exit(84);
    }
    parsing_corewar.have_prog_nb = true;
}

void get_load_address(const char *str)
{
    if (str == NULL) {
        my_puterror("Failed to get string of nb adress.\n");
        my_exit(84);
    }
    tmp_parsing.load_adress = my_get_nb(str);
    if (tmp_parsing.load_adress <= 0) {
        my_puterror("Invalid number of adress.\n");
        my_exit(84);
    }
    if (tmp_parsing.load_adress == 0 && my_strcmp(str, "0") != 0) {
        my_puterror("Failed to get_nbr.\n");
        my_exit(84);
    }
    parsing_corewar.have_load_adress = true;
}

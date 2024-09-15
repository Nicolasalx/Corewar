/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_champion_header
*/

#include "asm.h"

static int is_right_nb_of_quote(char **file_content)
{
    int nb_quote = 0;
    int sum_quote = 0;

    for (int i = 0; file_content[i] != NULL; ++i) {
        nb_quote = count_occur(file_content[i], '\"');
        sum_quote += nb_quote;
        if (nb_quote != 2 && nb_quote != 0) {
            print_error(RED("Bad number of quote"),
            " (line ", INT(i + 1), "): ", file_content[i], "\n");
            my_exit(84);
        }
        nb_quote = 0;
    }
    if (sum_quote != 4 && sum_quote != 2) {
        print_error(RED("Invalid number of quote\n"));
        my_exit(84);
    }
    return sum_quote;
}

static void ini_champion_header(header_t *header)
{
    my_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
    my_memset(header->comment, 0, COMMENT_LENGTH + 1);
    header->magic = COREWAR_EXEC_MAGIC;
    header->prog_size = 0;
}

void get_champion_header(char **file_content, header_t *header)
{
    int nb_quote = is_right_nb_of_quote(file_content);
    bool name_found = false;
    bool comment_found = false;

    ini_champion_header(header);
    for (int i = 0; file_content[i] != NULL
        && ((nb_quote == 4 && (not name_found || not comment_found))
        || (nb_quote == 2 && not name_found)); ++i) {
        if (name_found == false) {
            find_champion_name(file_content[i],
                &name_found, header->prog_name);
        } else {
            find_champion_comment(file_content[i],
                &comment_found, header->comment);
        }
    }
    if (nb_quote == 2) {
        print_error(WARNING_MSG, "no comment specified.\n");
    }
}

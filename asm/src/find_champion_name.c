/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** find_champion_name
*/

#include "asm.h"

static void verify_line_syntax(char *line)
{
    int nb_word = count_nb_word(line, " \t\n");
    int *size_word = count_size_word(line, " \t\n", nb_word);
    char **word = my_str_to_word(line, " \t\n", nb_word, size_word);

    if (nb_word < 2 || my_strcmp(word[0], NAME_CMD_STRING) != 0
    || word[nb_word - 1][size_word[nb_word - 1] - 1] != '\"'
    || word[1][0] != '\"') {
        print_error(SYNTAX_ERROR_MSG, line, "\n");
        my_exit(84);
    }
}

static void get_name_content(char *line,
    bool *name_found, char *prog_name)
{
    int name_size = 0;

    for (int i = my_strchr(line, '\"') + 1;
        line[i] != '\0' && line[i] != '\"'; ++i) {
        if (name_size >= PROG_NAME_LENGTH) {
            print_error("The program name is too long: ", line, "\n");
            my_exit(84);
        }
        prog_name[name_size] = line[i];
        ++ name_size;
    }
    my_memset(line, 0, sizeof(char) * my_strlen(line));
    *name_found = true;
}

void find_champion_name(char *line, bool *name_found, char *prog_name)
{
    int index_name = my_strchr(line, '.');
    char *name_ptr = &line[index_name];

    if (index_name == -1) {
        if (not is_empty_line(line)) {
            print_error("The name of your program "
            "must be the first line but it was: ", line, "\n");
            my_exit(84);
        }
        return;
    }
    if (my_strncmp(name_ptr, NAME_CMD_STRING,
        my_strlen(NAME_CMD_STRING)) != 0) {
        print_error("The name of your program "
        "must be the first line but it was: ", line, "\n");
        my_exit(84);
    }
    verify_line_syntax(line);
    get_name_content(line, name_found, prog_name);
}

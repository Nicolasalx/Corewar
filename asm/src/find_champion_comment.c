/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** find_champion_comment
*/

#include "asm.h"

static void verify_line_syntax(char *line)
{
    int nb_word = count_nb_word(line, " \t\n");
    int *size_word = count_size_word(line, " \t\n", nb_word);
    char **word = my_str_to_word(line, " \t\n", nb_word, size_word);

    if (nb_word < 2 || my_strcmp(word[0], COMMENT_CMD_STRING) != 0
    || word[nb_word - 1][size_word[nb_word - 1] - 1] != '\"'
    || word[1][0] != '\"') {
        print_error(SYNTAX_ERROR_MSG, line, "\n");
        my_exit(84);
    }
}

static void get_comment_content(char *line,
    bool *comment_found, char *comment)
{
    int comment_size = 0;

    for (int i = my_strchr(line, '\"') + 1;
        line[i] != '\0' && line[i] != '\"'; ++i) {
        if (comment_size >= COMMENT_LENGTH) {
            print_error("The comment is too long: ", line, "\n");
            my_exit(84);
        }
        comment[comment_size] = line[i];
        ++ comment_size;
    }
    my_memset(line, 0, sizeof(char) * my_strlen(line));
    *comment_found = true;
}

void find_champion_comment(char *line,
    bool *comment_found, char *comment)
{
    int index_comment = my_strchr(line, '.');
    char *comment_ptr = &line[index_comment];

    if (index_comment == -1) {
        if (not is_empty_line(line)) {
            print_error(SYNTAX_ERROR_MSG, line, "\n");
            my_exit(84);
        }
        return;
    }
    if (my_strncmp(comment_ptr, COMMENT_CMD_STRING,
        my_strlen(COMMENT_CMD_STRING)) != 0) {
        print_error("The comment of your program "
        "must be just after the name but it was: ", line, "\n");
        my_exit(84);
    }
    verify_line_syntax(line);
    get_comment_content(line, comment_found, comment);
}

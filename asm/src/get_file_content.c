/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** get_file_content
*/

#include "asm.h"
#include <unistd.h>

static char **get_file_as_board(char *buff)
{
    int nb_line = count_nb_line(buff);
    int *size_line = count_lines_size(buff, nb_line);
    char **file_conent = my_str_to_board(buff, nb_line, size_line);

    my_free(size_line, buff);
    return file_conent;
}

char **get_file_content(const char *file_path)
{
    int fd = open_file(file_path);
    char *buff;

    if (fd == -1) {
        print_error(RED(file_path, ": No such file or directory.\n"));
        my_exit(84);
    }
    if (is_a_dir(file_path)) {
        print_error(RED(file_path, ": is directory.\n"));
        close(fd);
        my_exit(84);
    }
    buff = my_file_to_str(fd, my_filelen(file_path));
    close(fd);
    return get_file_as_board(buff);
}

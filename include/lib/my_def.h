/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_def
*/

#ifndef MY_DEF_H_
    #define MY_DEF_H_

    #define INVERT_COLOR "\e[7m"
    #define RESET_COLOR "\e[0m"
    #define BOLD(...) "\e[1m", __VA_ARGS__ ,"\e[0m"
    #define UNDERLINE(...) "\e[4m", __VA_ARGS__ ,"\e[0m"

    #define RED(...) "\e[91m", __VA_ARGS__ ,"\e[0m"
    #define GREEN(...) "\e[92m", __VA_ARGS__ ,"\e[0m"
    #define YELLOW(...) "\e[93m", __VA_ARGS__ ,"\e[0m"
    #define BLUE(...) "\e[94m", __VA_ARGS__ ,"\e[0m"
    #define MAGENTA(...) "\e[95m", __VA_ARGS__ ,"\e[0m"
    #define CYAN(...) "\e[96m", __VA_ARGS__ ,"\e[0m"

    #define BOLD_RED(...) "\e[1;91m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_GREEN(...) "\e[1;92m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_YELLOW(...) "\e[1;93m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_BLUE(...) "\e[1;94m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_MAGENTA(...) "\e[1;95m", __VA_ARGS__ ,"\e[0m"
    #define BOLD_CYAN(...) "\e[1;96m", __VA_ARGS__ ,"\e[0m"

    #define UNUSED(var) (void) (var)

    #define ADD_QUOTE(value) #value
    #define STR(value) ADD_QUOTE(value)

    #define NB_ELEM(data) (sizeof(data) / sizeof(*data))

    #define BOARDIFY(type, ...) ((type *[]) {__VA_ARGS__, NULL})

    #define CAST_BACK(data, type) ((type *) data)

    #define SET_NULL(var) var = NULL

    #define not !

#endif /* !MY_DEF_H_ */

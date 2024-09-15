/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_error
*/

#ifndef MY_ERROR
    #define MY_ERROR

    #include "my_def.h"
    #include "internal/my_vaarg.h"

    #define print_error(...) EXECUTE(FOR_EACH(CALL_PRINT_ERROR, __VA_ARGS__))
    #define CALL_PRINT_ERROR(arg) my_puterror(arg);

typedef enum error_code_enum {
    NO_ERROR,
    MALLOC_FAIL,
    STAT_FAIL,
    READ_FAIL,
    OPEN_FAIL
} error_code_enum;

typedef struct error_t {
    int code;
    const char *message;
    int return_value;
} error_t;

extern const error_t error_info[];
extern const int size_error_info;

void my_puterror(const char *str);
void print_fatal_error_and_exit(int error);
void my_exit(long int exit_value);

#endif /* !MY_ERROR */

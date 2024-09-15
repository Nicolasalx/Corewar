/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_warning
*/

#ifndef MY_WARNING_H_
    #define MY_WARNING_H_

    #include "../my_def.h"

    #define DB_ARG(arg) __FILE__, STR(__LINE__), STR(arg)

#ifdef SET_NULL_AFTER_FREE
    #define NULLIFY(arg) SET_NULL(arg);
#else
    #define NULLIFY(arg)
#endif

#ifdef MY_WARNING
    #define CALL_MY_FREE(arg) \
        my_free_db(arg, DB_ARG(arg)); \
        SET_NULL(arg);

    #define CALL_FREE_BOARD(arg) \
        free_board_db((void **) arg, DB_ARG(arg)); \
        SET_NULL(arg);
#else
    #define CALL_MY_FREE(arg) my_free_fm(arg); NULLIFY(arg)
    #define CALL_FREE_BOARD(arg) free_board_fm((void **) arg); NULLIFY(arg)
#endif

void my_free_db(void **data, char *file, char *line, char *var_name);
void free_board_db(void **board, char *file, char *line, char *var_name);

#endif /* !MY_WARNING_H_ */

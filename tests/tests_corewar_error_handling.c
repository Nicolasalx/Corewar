/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** tests_corewar_error_handling
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my_importall.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int test_main_corewar(int argc, const char **argv);

static void exec_corewar(int argc, char **argv, int expected_return_value)
{
    pid_t pid = fork();

    if (pid == 0) {
        test_main_corewar(argc, (const char **) argv);
        exit(0);
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), expected_return_value);
    } else {
        exit(1);
    }
}

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite(Test_error_handling_corewar, .init=redirect_all_stdout);

Test(Test_error_handling_corewar, test_1)
{
    int argc = 3;
    char *argv[] = {"./corewar", "../tests/tests_cor/jon.cor", "../tests/tests_cor/jon.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_2)
{
    int argc = 2;
    char *argv[] = {"./corewar", "../tests/tests_cor/ebola.cor", NULL};
    exec_corewar(argc, argv, 84);
}

Test(Test_error_handling_corewar, test_3)
{
    int argc = 1;
    char *argv[] = {"./corewar", NULL};
    exec_corewar(argc, argv, 84);
}

Test(Test_error_handling_corewar, test_4)
{
    int argc = 2;
    char *argv[] = {"./corewar", "../tests/input/abel.s", NULL};
    exec_corewar(argc, argv, 84);
}

Test(Test_error_handling_corewar, test_5)
{
    int argc = 2;
    char *argv[] = {"./corewar", "unknow_file", NULL};
    exec_corewar(argc, argv, 84);
}

Test(Test_error_handling_corewar, test_6)
{
    int argc = 2;
    char *argv[] = {"./corewar", "../corewar", NULL};
    exec_corewar(argc, argv, 84);
}

Test(Test_error_handling_corewar, test_7)
{
    int argc = 3;
    char *argv[] = {"./corewar", "../tests/tests_cor/42.cor", "../tests/tests_cor/42.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_8)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "2000", "../tests/tests_cor/abel.cor", "../tests/tests_cor/abel.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_9)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "2000", "../tests/tests_cor/bill.cor", "../tests/tests_cor/bill.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_10)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "2000", "../tests/tests_cor/jon.cor", "../tests/tests_cor/jon.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_11)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "2000", "../tests/tests_cor/pdd.cor", "../tests/tests_cor/pdd.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_12)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "10000", "../tests/tests_cor/tyron.cor", "../tests/tests_cor/tyron.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_13)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "10000", "../tests/tests_cor/all_op.cor", "../tests/tests_cor/all_op.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_14)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "10000", "../tests/tests_cor/fluttershy.cor", "../tests/tests_cor/helltrain.cor", NULL};
    exec_corewar(argc, argv, 0);
}

Test(Test_error_handling_corewar, test_15)
{
    int argc = 5;
    char *argv[] = {"./corewar", "-dump", "10000", "../tests/tests_cor/fluttershy.cor", "../tests/tests_cor/bigzork.cor", NULL};
    exec_corewar(argc, argv, 0);
}

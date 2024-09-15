/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** tests_interface
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/hooks.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE_BAR (30)

ReportHook(PRE_ALL)(struct criterion_test_set *tests)
{
    (void) tests;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    printf("\n----------------------------------------------------\n"
            "\t\t    Test Results\n"
            "----------------------------------------------------\n\n");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats)
{
    double percentage_pass = ((double) stats->tests_passed / (double) stats->nb_tests) * 100.0;
    printf("\nPass rate: [");
    char color_code[] = "\033[91m";
    if (percentage_pass >= 75.0) {
        strcpy(color_code, "\033[92m");
    } else if (percentage_pass >= 25.0) {
        strcpy(color_code, "\033[93m");
    }
    for (int i = 0; i < SIZE_BAR; ++i) {
        if (i < (int) (percentage_pass * ((double) SIZE_BAR / 100.0))) {
            printf("%s█\033[0m", color_code);
        } else {
            printf("\033[0;37m▒\033[0m");
        }
        usleep(30000);
    }
    printf("] \033[1m%s%.1f%%\033[0m\n\n", color_code, percentage_pass);
    printf("----------------------------------------------------\n");
    printf("\033[1mTested: \033[94m%ld\033[0m\033[1m"
    " | Passing: \033[92m%ld\033[0m\033[1m | Failing: \033[91m%ld\033[0m\033[1m | Crashing: \033[91m%ld\033[0m\n",
    stats->nb_tests, stats->nb_tests - (stats->asserts_failed + stats->tests_skipped + stats->tests_crashed),
    stats->asserts_failed, stats->tests_skipped + stats->tests_crashed);
    printf("----------------------------------------------------\n\n");
}

ReportHook(POST_FINI)(struct criterion_test_stats *test)
{
    static int count_test = 1;
    if (test->test_status == CR_STATUS_PASSED) {
        printf("Test %3d : [\033[92mPASS\033[0m] in %.2f sec\n", count_test, test->elapsed_time);
    } else if (test->test_status == CR_STATUS_FAILED) {
        printf("Test %3d : [\033[91mFAIL\033[0m] \e[1m%s\e[0m:\e[91m%d\e[0m: %s\n",
        count_test, test->file, test->asserts->line, test->asserts->message);
        printf("\t   [\e[94m----\e[0m] \e[96m%s\e[0m::\e[94m%s\e[0m\n", test->test->category, test->test->name);
    } else {
        printf("Test %3d : [\033[91mCRASH\033[0m] \033[93m%s %s %s\033[0m:\033[91m%d\033[0m \033[1m%s\033[0m\n",
        count_test, test->file, test->test->category, test->test->name, test->asserts->line, test->asserts->message);
    }
    ++ count_test;
}

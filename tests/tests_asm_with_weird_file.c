/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** tests_asm_with_weird_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my_importall.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int test_main_asm(int argc, const char *argv[]);

static bool is_files_exist(char *input_file)
{
    char *output_file = my_strdup(input_file);
    output_file[my_strlen(output_file) - 2] = '\0';
    char output_file_asm[1000] = {0};
    char ref_output_file_asm[1000] = {0};

    build_str(output_file_asm, output_file, ".cor");
    build_str(ref_output_file_asm, "../tests/input/", output_file, ".cor");

    if ((open_file(output_file_asm) == -1 && open_file(ref_output_file_asm) == -1)
     || (open_file(output_file_asm) != -1 && open_file(ref_output_file_asm) != -1)) {
        return true;
    } else {
        return false;
    }
}

static bool is_file_differ(char *input_file)
{
    int return_value;
    char *output_file = my_strdup(input_file);
    output_file[my_strlen(output_file) - 2] = '\0';
    char ref_arg[1000] = {0};

    build_str(ref_arg, "diff ../tests/input/", output_file, ".cor ", output_file, ".cor");

    return_value = system(ref_arg);

    if (WIFEXITED(return_value)) {
        if (WEXITSTATUS(return_value) == 0) {
            return false;
        } else if (WEXITSTATUS(return_value) == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        return -1;
    }
}

static int exec_ref_asm(const char *input_file)
{
    int return_value;
    char ref_arg[1000] = {0};

    build_str(ref_arg, "./../tests/binaire_ref/asm ../tests/input/", input_file);

    return_value = system(ref_arg);

    if (WIFEXITED(return_value)) {
        return WEXITSTATUS(return_value);
    } else {
        return -1;
    }
}

static void exec_asm(char *input_file, int expected_return_value)
{
    pid_t pid = fork();
    int argc = 2;
    char file_full_path[1000] = {0};
    build_str(file_full_path, "../tests/input/", input_file);
    const char *argv[] = {"./asm", file_full_path, NULL};

    if (pid == 0) {
        test_main_asm(argc, argv);
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

TestSuite(Test_weird_file, .init = redirect_all_stdout);

Test(Test_weird_file, test_abel)
{
    exec_asm("abel.s", exec_ref_asm("abel.s"));
    cr_expect(is_files_exist("abel.s") == true);
    cr_expect(is_file_differ("abel.s") == false);
}

Test(Test_weird_file, test_aurollan)
{
    exec_asm("aurollan.s", exec_ref_asm("aurollan.s"));
    cr_expect(is_files_exist("aurollan.s") == true);
    cr_expect(is_file_differ("aurollan.s") == false);
}

Test(Test_weird_file, test_bigzork)
{
    exec_asm("bigzork.s", exec_ref_asm("bigzork.s"));
    cr_expect(is_files_exist("bigzork.s") == true);
    cr_expect(is_file_differ("bigzork.s") == false);
}

Test(Test_weird_file, test_bill)
{
    exec_asm("bill.s", exec_ref_asm("bill.s"));
    cr_expect(is_files_exist("bill.s") == true);
    cr_expect(is_file_differ("bill.s") == false);
}

Test(Test_weird_file, test_Car)
{
    exec_asm("Car.s", exec_ref_asm("Car.s"));
    cr_expect(is_files_exist("Car.s") == true);
    cr_expect(is_file_differ("Car.s") == false);
}

Test(Test_weird_file, test_cepalle2)
{
    exec_asm("cepalle2.s", exec_ref_asm("cepalle2.s"));
    cr_expect(is_files_exist("cepalle2.s") == true);
    cr_expect(is_file_differ("cepalle2.s") == false);
}

Test(Test_weird_file, test_cepalle)
{
    exec_asm("cepalle.s", exec_ref_asm("cepalle.s"));
    cr_expect(is_files_exist("cepalle.s") == true);
    cr_expect(is_file_differ("cepalle.s") == false);
}

Test(Test_weird_file, test_corruption)
{
    exec_asm("corruption.s", exec_ref_asm("corruption.s"));
    cr_expect(is_files_exist("corruption.s") == true);
    cr_expect(is_file_differ("corruption.s") == false);
}

Test(Test_weird_file, test_corup)
{
    exec_asm("corup.s", exec_ref_asm("corup.s"));
    cr_expect(is_files_exist("corup.s") == true);
    cr_expect(is_file_differ("corup.s") == false);
}

Test(Test_weird_file, test_ex)
{
    exec_asm("ex.s", exec_ref_asm("ex.s"));
    cr_expect(is_files_exist("ex.s") == true);
    cr_expect(is_file_differ("ex.s") == false);
}

Test(Test_weird_file, test_fluttershy)
{
    exec_asm("fluttershy.s", exec_ref_asm("fluttershy.s"));
    cr_expect(is_files_exist("fluttershy.s") == true);
    cr_expect(is_file_differ("fluttershy.s") == false);
}

Test(Test_weird_file, test_Gagnant)
{
    exec_asm("Gagnant.s", exec_ref_asm("Gagnant.s"));
    cr_expect(is_files_exist("Gagnant.s") == true);
    cr_expect(is_file_differ("Gagnant.s") == false);
}

Test(Test_weird_file, test_jumper)
{
    exec_asm("jumper.s", exec_ref_asm("jumper.s"));
    cr_expect(is_files_exist("jumper.s") == true);
    cr_expect(is_file_differ("jumper.s") == false);
}

Test(Test_weird_file, test_kroz)
{
    exec_asm("kroz.s", exec_ref_asm("kroz.s"));
    cr_expect(is_files_exist("kroz.s") == true);
    cr_expect(is_file_differ("kroz.s") == false);
}

Test(Test_weird_file, test_maxidef)
{
    exec_asm("maxidef.s", exec_ref_asm("maxidef.s"));
    cr_expect(is_files_exist("maxidef.s") == true);
    cr_expect(is_file_differ("maxidef.s") == false);
}

Test(Test_weird_file, test_mortel)
{
    exec_asm("mortel.s", exec_ref_asm("mortel.s"));
    cr_expect(is_files_exist("mortel.s") == true);
    cr_expect(is_file_differ("mortel.s") == false);
}

Test(Test_weird_file, test_Octobre_Rouge_V4)
{
    exec_asm("Octobre_Rouge_V4.s", exec_ref_asm("Octobre_Rouge_V4.s"));
    cr_expect(is_files_exist("Octobre_Rouge_V4.s") == true);
    cr_expect(is_file_differ("Octobre_Rouge_V4.s") == false);
}

Test(Test_weird_file, test_pdd)
{
    exec_asm("pdd.s", exec_ref_asm("pdd.s"));
    cr_expect(is_files_exist("pdd.s") == true);
    cr_expect(is_file_differ("pdd.s") == false);
}

Test(Test_weird_file, test_ppichier)
{
    exec_asm("ppichier.s", exec_ref_asm("ppichier.s"));
    cr_expect(is_files_exist("ppichier.s") == true);
    cr_expect(is_file_differ("ppichier.s") == false);
}

Test(Test_weird_file, test_slider2)
{
    exec_asm("slider2.s", exec_ref_asm("slider2.s"));
    cr_expect(is_files_exist("slider2.s") == true);
    cr_expect(is_file_differ("slider2.s") == false);
}

Test(Test_weird_file, test_sujet)
{
    exec_asm("sujet.s", exec_ref_asm("sujet.s"));
    cr_expect(is_files_exist("sujet.s") == true);
    cr_expect(is_file_differ("sujet.s") == false);
}

Test(Test_weird_file, test_toto)
{
    exec_asm("toto.s", exec_ref_asm("toto.s"));
    cr_expect(is_files_exist("toto.s") == true);
    cr_expect(is_file_differ("toto.s") == false);
}

Test(Test_weird_file, test_tyron)
{
    exec_asm("tyron.s", exec_ref_asm("tyron.s"));
    cr_expect(is_files_exist("tyron.s") == true);
    cr_expect(is_file_differ("tyron.s") == false);
}

Test(Test_weird_file, test_comment_of_size_2048)
{
    exec_asm("comment_of_size_2048.s", exec_ref_asm("comment_of_size_2048.s"));
    cr_expect(is_files_exist("comment_of_size_2048.s") == true);
    cr_expect(is_file_differ("comment_of_size_2048.s") == false);
}

Test(Test_weird_file, test_comment_too_too_long)
{
    exec_asm("comment_too_too_long.s", exec_ref_asm("comment_too_too_long.s"));
    cr_expect(is_files_exist("comment_too_too_long.s") == true);
    cr_expect(is_file_differ("comment_too_too_long.s") == false);
}

Test(Test_weird_file, test_name_of_size_128)
{
    exec_asm("name_of_size_128.s", exec_ref_asm("name_of_size_128.s"));
    cr_expect(is_files_exist("name_of_size_128.s") == true);
    cr_expect(is_file_differ("name_of_size_128.s") == false);
}

Test(Test_weird_file, test_name_too_too_long)
{
    exec_asm("name_too_too_long.s", exec_ref_asm("name_too_too_long.s"));
    cr_expect(is_files_exist("name_too_too_long.s") == true);
    cr_expect(is_file_differ("name_too_too_long.s") == false);
}

Test(Test_weird_file, test_weird_nb_1)
{
    exec_asm("weird_nb_1.s", exec_ref_asm("weird_nb_1.s"));
    cr_expect(is_files_exist("weird_nb_1.s") == true);
    cr_expect(is_file_differ("weird_nb_1.s") == false);
}

Test(Test_weird_file, test_weird_nb_2)
{
    exec_asm("weird_nb_2.s", exec_ref_asm("weird_nb_2.s"));
    cr_expect(is_files_exist("weird_nb_2.s") == true);
    cr_expect(is_file_differ("weird_nb_2.s") == false);
}

Test(Test_weird_file, test_weird_nb_3)
{
    exec_asm("weird_nb_3.s", exec_ref_asm("weird_nb_3.s"));
    cr_expect(is_files_exist("weird_nb_3.s") == true);
    cr_expect(is_file_differ("weird_nb_3.s") == false);
}

Test(Test_weird_file, test_weird_nb_4)
{
    exec_asm("weird_nb_4.s", exec_ref_asm("weird_nb_4.s"));
    cr_expect(is_files_exist("weird_nb_4.s") == true);
    cr_expect(is_file_differ("weird_nb_4.s") == false);
}

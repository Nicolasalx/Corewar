/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** tests_asm_file_content
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my_importall.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int test_main_asm(int argc, const char *argv[]);

static bool is_file_differ(char *input_file)
{
    int return_value;
    char *output_file = my_strdup(input_file);
    output_file[my_strlen(output_file) - 2] = '\0';
    char ref_arg[1000] = {0};

    build_str(ref_arg, "diff ../tests/correct/", output_file, ".cor ", output_file, ".cor");

    return_value = system(ref_arg);

    if (WIFEXITED(return_value)) {
        if (WEXITSTATUS(return_value) == 0) {
            return false;
        } else if (WEXITSTATUS(return_value) == 1) {
            return true;
        } else {
            return true;
        }
    } else {
        return -1;
    }
}

static int exec_ref_asm(const char *input_file)
{
    int return_value;
    char ref_arg[1000] = {0};

    build_str(ref_arg, "./../tests/binaire_ref/asm ../tests/correct/", input_file);

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
    build_str(file_full_path, "../tests/correct/", input_file);
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

TestSuite(Test_asm_file_content, .init = redirect_all_stdout);

Test(Test_asm_file_content, test_rabel)
{
    exec_asm("rabel.s", exec_ref_asm("rabel.s"));
    cr_expect(is_file_differ("rabel.s") == false);
}

Test(Test_asm_file_content, test_raurollan)
{
    exec_asm("raurollan.s", exec_ref_asm("raurollan.s"));
    cr_expect(is_file_differ("raurollan.s") == false);
}

Test(Test_asm_file_content, test_rbigzork)
{
    exec_asm("rbigzork.s", exec_ref_asm("rbigzork.s"));
    cr_expect(is_file_differ("rbigzork.s") == false);
}

Test(Test_asm_file_content, test_rbill)
{
    exec_asm("rbill.s", exec_ref_asm("rbill.s"));
    cr_expect(is_file_differ("rbill.s") == false);
}

Test(Test_asm_file_content, test_rCar)
{
    exec_asm("rCar.s", exec_ref_asm("rCar.s"));
    cr_expect(is_file_differ("rCar.s") == false);
}

Test(Test_asm_file_content, test_rcepalle2)
{
    exec_asm("rcepalle2.s", exec_ref_asm("rcepalle2.s"));
    cr_expect(is_file_differ("rcepalle2.s") == false);
}

Test(Test_asm_file_content, test_rcepalle)
{
    exec_asm("rcepalle.s", exec_ref_asm("rcepalle.s"));
    cr_expect(is_file_differ("rcepalle.s") == false);
}

Test(Test_asm_file_content, test_rcorruption)
{
    exec_asm("rcorruption.s", exec_ref_asm("rcorruption.s"));
    cr_expect(is_file_differ("rcorruption.s") == false);
}

Test(Test_asm_file_content, test_rcorup)
{
    exec_asm("rcorup.s", exec_ref_asm("rcorup.s"));
    cr_expect(is_file_differ("rcorup.s") == false);
}

Test(Test_asm_file_content, test_rex)
{
    exec_asm("rex.s", exec_ref_asm("rex.s"));
    cr_expect(is_file_differ("rex.s") == false);
}

Test(Test_asm_file_content, test_rfluttershy)
{
    exec_asm("rfluttershy.s", exec_ref_asm("rfluttershy.s"));
    cr_expect(is_file_differ("rfluttershy.s") == false);
}

Test(Test_asm_file_content, test_rGagnant)
{
    exec_asm("rGagnant.s", exec_ref_asm("rGagnant.s"));
    cr_expect(is_file_differ("rGagnant.s") == false);
}

Test(Test_asm_file_content, test_rjumper)
{
    exec_asm("rjumper.s", exec_ref_asm("rjumper.s"));
    cr_expect(is_file_differ("rjumper.s") == false);
}

Test(Test_asm_file_content, test_rkroz)
{
    exec_asm("rkroz.s", exec_ref_asm("rkroz.s"));
    cr_expect(is_file_differ("rkroz.s") == false);
}

Test(Test_asm_file_content, test_rmaxidef)
{
    exec_asm("rmaxidef.s", exec_ref_asm("rmaxidef.s"));
    cr_expect(is_file_differ("rmaxidef.s") == false);
}

Test(Test_asm_file_content, test_rmortel)
{
    exec_asm("rmortel.s", exec_ref_asm("rmortel.s"));
    cr_expect(is_file_differ("rmortel.s") == false);
}

Test(Test_asm_file_content, test_rOctobre_Rouge_V4)
{
    exec_asm("rOctobre_Rouge_V4.s", exec_ref_asm("rOctobre_Rouge_V4.s"));
    cr_expect(is_file_differ("rOctobre_Rouge_V4.s") == false);
}

Test(Test_asm_file_content, test_rpdd)
{
    exec_asm("rpdd.s", exec_ref_asm("rpdd.s"));
    cr_expect(is_file_differ("rpdd.s") == false);
}

Test(Test_asm_file_content, test_rppichier)
{
    exec_asm("rppichier.s", exec_ref_asm("rppichier.s"));
    cr_expect(is_file_differ("rppichier.s") == false);
}

Test(Test_asm_file_content, test_rslider2)
{
    exec_asm("rslider2.s", exec_ref_asm("rslider2.s"));
    cr_expect(is_file_differ("rslider2.s") == false);
}

Test(Test_asm_file_content, test_rsujet)
{
    exec_asm("rsujet.s", exec_ref_asm("rsujet.s"));
    cr_expect(is_file_differ("rsujet.s") == false);
}

Test(Test_asm_file_content, test_rtoto)
{
    exec_asm("rtoto.s", exec_ref_asm("rtoto.s"));
    cr_expect(is_file_differ("rtoto.s") == false);
}

Test(Test_asm_file_content, test_rtyron)
{
    exec_asm("rtyron.s", exec_ref_asm("rtyron.s"));
    cr_expect(is_file_differ("rtyron.s") == false);
}

Test(Test_asm_file_content, test_ronly_name)
{
    exec_asm("ronly_name.s", exec_ref_asm("ronly_name.s"));
    cr_expect(is_file_differ("ronly_name.s") == false);
}

Test(Test_asm_file_content, test_ronly_name_comment)
{
    exec_asm("ronly_name_comment.s", exec_ref_asm("ronly_name_comment.s"));
    cr_expect(is_file_differ("ronly_name_comment.s") == false);
}

/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "my_importall.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int test_main_asm(int argc, const char *argv[]);

static bool is_files_not_exist(char *input_file)
{
    char *output_file = my_strdup(input_file);
    output_file[my_strlen(output_file) - 2] = '\0';
    char output_file_asm[1000] = {0};
    char ref_output_file_asm[1000] = {0};

    build_str(output_file_asm, output_file, ".cor");
    build_str(ref_output_file_asm, "../tests/input_error/", output_file, ".cor");

    if ((open_file(output_file_asm) == -1 && open_file(ref_output_file_asm) == -1)) {
        return true;
    } else {
        return false;
    }
}

static int exec_ref_asm(const char *input_file)
{
    int return_value;
    char ref_arg[1000] = {0};

    build_str(ref_arg, "./../tests/binaire_ref/asm ../tests/input_error/", input_file);

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
    build_str(file_full_path, "../tests/input_error/", input_file);
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

TestSuite(Test_error_handling_asm, .init=redirect_all_stdout);

Test(Test_error_handling_asm, test_aurollan)
{
    exec_asm("aurollan.s", exec_ref_asm("aurollan.s"));
    cr_expect(is_files_not_exist("aurollan.s") == true);
}

Test(Test_error_handling_asm, test_empty)
{
    exec_asm("empty.s", exec_ref_asm("empty.s"));
    cr_expect(is_files_not_exist("empty.s") == true);
}

Test(Test_error_handling_asm, test_lexer_direct_number1)
{
    exec_asm("lexer_direct_number1.s", exec_ref_asm("lexer_direct_number1.s"));
    cr_expect(is_files_not_exist("lexer_direct_number1.s") == true);
}

Test(Test_error_handling_asm, test_lexer_direct_number2)
{
    exec_asm("lexer_direct_number2.s", exec_ref_asm("lexer_direct_number2.s"));
    cr_expect(is_files_not_exist("lexer_direct_number2.s") == true);
}

Test(Test_error_handling_asm, test_lexer_direct_number3)
{
    exec_asm("lexer_direct_number3.s", exec_ref_asm("lexer_direct_number3.s"));
    cr_expect(is_files_not_exist("lexer_direct_number3.s") == true);
}

Test(Test_error_handling_asm, test_lexer_direct)
{
    exec_asm("lexer_direct.s", exec_ref_asm("lexer_direct.s"));
    cr_expect(is_files_not_exist("lexer_direct.s") == true);
}

Test(Test_error_handling_asm, test_lexer_dot)
{
    exec_asm("lexer_dot.s", exec_ref_asm("lexer_dot.s"));
    cr_expect(is_files_not_exist("lexer_dot.s") == true);
}

Test(Test_error_handling_asm, test_lexer_indirect_number1)
{
    exec_asm("lexer_indirect_number1.s", exec_ref_asm("lexer_indirect_number1.s"));
    cr_expect(is_files_not_exist("lexer_indirect_number1.s") == true);
}

Test(Test_error_handling_asm, test_lexer_indirect_number2)
{
    exec_asm("lexer_indirect_number2.s", exec_ref_asm("lexer_indirect_number2.s"));
    cr_expect(is_files_not_exist("lexer_indirect_number2.s") == true);
}

Test(Test_error_handling_asm, test_lexer_indirect_number3)
{
    exec_asm("lexer_indirect_number3.s", exec_ref_asm("lexer_indirect_number3.s"));
    cr_expect(is_files_not_exist("lexer_indirect_number3.s") == true);
}

Test(Test_error_handling_asm, test_lexer_indirect_number4)
{
    exec_asm("lexer_indirect_number4.s", exec_ref_asm("lexer_indirect_number4.s"));
    cr_expect(is_files_not_exist("lexer_indirect_number4.s") == true);
}

Test(Test_error_handling_asm, test_lexer_label1)
{
    exec_asm("lexer_label1.s", exec_ref_asm("lexer_label1.s"));
    cr_expect(is_files_not_exist("lexer_label1.s") == true);
}

Test(Test_error_handling_asm, test_lexer_unexpected_char)
{
    exec_asm("lexer_unexpected_char.s", exec_ref_asm("lexer_unexpected_char.s"));
    cr_expect(is_files_not_exist("lexer_unexpected_char.s") == true);
}

Test(Test_error_handling_asm, test_parser_bad_number_param)
{
    exec_asm("parser_bad_number_param.s", exec_ref_asm("parser_bad_number_param.s"));
    cr_expect(is_files_not_exist("parser_bad_number_param.s") == true);
}

Test(Test_error_handling_asm, test_parser_bad_param)
{
    exec_asm("parser_bad_param.s", exec_ref_asm("parser_bad_param.s"));
    cr_expect(is_files_not_exist("parser_bad_param.s") == true);
}

Test(Test_error_handling_asm, test_parser_more_3_param)
{
    exec_asm("parser_more_3_param.s", exec_ref_asm("parser_more_3_param.s"));
    cr_expect(is_files_not_exist("parser_more_3_param.s") == true);
}

Test(Test_error_handling_asm, test_parser_name_empty)
{
    exec_asm("parser_name_empty.s", exec_ref_asm("parser_name_empty.s"));
    cr_expect(is_files_not_exist("parser_name_empty.s") == true);
}

Test(Test_error_handling_asm, test_parser_need_param)
{
    exec_asm("parser_need_param.s", exec_ref_asm("parser_need_param.s"));
    cr_expect(is_files_not_exist("parser_need_param.s") == true);
}

Test(Test_error_handling_asm, test_parser_no_comment)
{
    exec_asm("parser_no_comment.s", exec_ref_asm("parser_no_comment.s"));
    cr_expect(is_files_not_exist("parser_no_comment.s") == true);
}

Test(Test_error_handling_asm, test_parser_no_eof_into_cmd)
{
    exec_asm("parser_no_eof_into_cmd.s", exec_ref_asm("parser_no_eof_into_cmd.s"));
    cr_expect(is_files_not_exist("parser_no_eof_into_cmd.s") == true);
}

Test(Test_error_handling_asm, test_parser_no_label_dec)
{
    exec_asm("parser_no_label_dec.s", exec_ref_asm("parser_no_label_dec.s"));
    cr_expect(is_files_not_exist("parser_no_label_dec.s") == true);
}

Test(Test_error_handling_asm, test_parser_no_name)
{
    exec_asm("parser_no_name.s", exec_ref_asm("parser_no_name.s"));
    cr_expect(is_files_not_exist("parser_no_name.s") == true);
}

Test(Test_error_handling_asm, test_parser_no_param)
{
    exec_asm("parser_no_param.s", exec_ref_asm("parser_no_param.s"));
    cr_expect(is_files_not_exist("parser_no_param.s") == true);
}

Test(Test_error_handling_asm, test_parser)
{
    exec_asm("parser.s", exec_ref_asm("parser.s"));
    cr_expect(is_files_not_exist("parser.s") == true);
}

Test(Test_error_handling_asm, test_parser_same_label_dec2)
{
    exec_asm("parser_same_label_dec2.s", exec_ref_asm("parser_same_label_dec2.s"));
    cr_expect(is_files_not_exist("parser_same_label_dec2.s") == true);
}

Test(Test_error_handling_asm, test_parser_same_label_dec)
{
    exec_asm("parser_same_label_dec.s", exec_ref_asm("parser_same_label_dec.s"));
    cr_expect(is_files_not_exist("parser_same_label_dec.s") == true);
}

Test(Test_error_handling_asm, test_parser_too_many_label_dec)
{
    exec_asm("parser_too_many_label_dec.s", exec_ref_asm("parser_too_many_label_dec.s"));
    cr_expect(is_files_not_exist("parser_too_many_label_dec.s") == true);
}

Test(Test_error_handling_asm, test_parser_two_comment)
{
    exec_asm("parser_two_comment.s", exec_ref_asm("parser_two_comment.s"));
    cr_expect(is_files_not_exist("parser_two_comment.s") == true);
}

Test(Test_error_handling_asm, test_parser_two_name)
{
    exec_asm("parser_two_name.s", exec_ref_asm("parser_two_name.s"));
    cr_expect(is_files_not_exist("parser_two_name.s") == true);
}

Test(Test_error_handling_asm, test_parser_unclose_string2)
{
    exec_asm("parser_unclose_string2.s", exec_ref_asm("parser_unclose_string2.s"));
    cr_expect(is_files_not_exist("parser_unclose_string2.s") == true);
}

Test(Test_error_handling_asm, test_parser_unclose_string)
{
    exec_asm("parser_unclose_string.s", exec_ref_asm("parser_unclose_string.s"));
    cr_expect(is_files_not_exist("parser_unclose_string.s") == true);
}

Test(Test_error_handling_asm, test_parser_unexpected_token2)
{
    exec_asm("parser_unexpected_token2.s", exec_ref_asm("parser_unexpected_token2.s"));
    cr_expect(is_files_not_exist("parser_unexpected_token2.s") == true);
}

Test(Test_error_handling_asm, test_parser_unexpected_token3)
{
    exec_asm("parser_unexpected_token3.s", exec_ref_asm("parser_unexpected_token3.s"));
    cr_expect(is_files_not_exist("parser_unexpected_token3.s") == true);
}

Test(Test_error_handling_asm, test_parser_unexpected_token)
{
    exec_asm("parser_unexpected_token.s", exec_ref_asm("parser_unexpected_token.s"));
    cr_expect(is_files_not_exist("parser_unexpected_token.s") == true);
}

Test(Test_error_handling_asm, test_parser_unknow_cmd)
{
    exec_asm("parser_unknow_cmd.s", exec_ref_asm("parser_unknow_cmd.s"));
    cr_expect(is_files_not_exist("parser_unknow_cmd.s") == true);
}

Test(Test_error_handling_asm, test_too_long_name)
{
    exec_asm("too_long_name.s", exec_ref_asm("too_long_name.s"));
    cr_expect(is_files_not_exist("too_long_name.s") == true);
}

Test(Test_error_handling_asm, test_too_long_comment)
{
    exec_asm("too_long_comment.s", exec_ref_asm("too_long_comment.s"));
    cr_expect(is_files_not_exist("too_long_comment.s") == true);
}

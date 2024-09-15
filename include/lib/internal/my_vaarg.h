/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_vaarg
*/

#ifndef MY_VAARG_H_
    #define MY_VAARG_H_

    #define MERGE_IMPL(x, y) x##y
    #define MERGE(x, y) MERGE_IMPL(x, y)

    #define EXECUTE(...) do {__VA_ARGS__} while (0)

    #define COUNT_ARGS(...) COUNT_ARGS_IMPL(__VA_ARGS__, \
        25, 24, 23, 22, 21, 20, 19, 18, 17, 16, \
        15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

    #define COUNT_ARGS_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
        _21, _22, _23, _24, _25, N, ...) N

    #define FOR_EACH_1(WHAT, X) WHAT(X)
    #define FOR_EACH_2(WHAT, X, ...) WHAT(X) FOR_EACH_1(WHAT, __VA_ARGS__)
    #define FOR_EACH_3(WHAT, X, ...) WHAT(X) FOR_EACH_2(WHAT, __VA_ARGS__)
    #define FOR_EACH_4(WHAT, X, ...) WHAT(X) FOR_EACH_3(WHAT, __VA_ARGS__)
    #define FOR_EACH_5(WHAT, X, ...) WHAT(X) FOR_EACH_4(WHAT, __VA_ARGS__)
    #define FOR_EACH_6(WHAT, X, ...) WHAT(X) FOR_EACH_5(WHAT, __VA_ARGS__)
    #define FOR_EACH_7(WHAT, X, ...) WHAT(X) FOR_EACH_6(WHAT, __VA_ARGS__)
    #define FOR_EACH_8(WHAT, X, ...) WHAT(X) FOR_EACH_7(WHAT, __VA_ARGS__)
    #define FOR_EACH_9(WHAT, X, ...) WHAT(X) FOR_EACH_8(WHAT, __VA_ARGS__)
    #define FOR_EACH_10(WHAT, X, ...) WHAT(X) FOR_EACH_9(WHAT, __VA_ARGS__)
    #define FOR_EACH_11(WHAT, X, ...) WHAT(X) FOR_EACH_10(WHAT, __VA_ARGS__)
    #define FOR_EACH_12(WHAT, X, ...) WHAT(X) FOR_EACH_11(WHAT, __VA_ARGS__)
    #define FOR_EACH_13(WHAT, X, ...) WHAT(X) FOR_EACH_12(WHAT, __VA_ARGS__)
    #define FOR_EACH_14(WHAT, X, ...) WHAT(X) FOR_EACH_13(WHAT, __VA_ARGS__)
    #define FOR_EACH_15(WHAT, X, ...) WHAT(X) FOR_EACH_14(WHAT, __VA_ARGS__)
    #define FOR_EACH_16(WHAT, X, ...) WHAT(X) FOR_EACH_15(WHAT, __VA_ARGS__)
    #define FOR_EACH_17(WHAT, X, ...) WHAT(X) FOR_EACH_16(WHAT, __VA_ARGS__)
    #define FOR_EACH_18(WHAT, X, ...) WHAT(X) FOR_EACH_17(WHAT, __VA_ARGS__)
    #define FOR_EACH_19(WHAT, X, ...) WHAT(X) FOR_EACH_18(WHAT, __VA_ARGS__)
    #define FOR_EACH_20(WHAT, X, ...) WHAT(X) FOR_EACH_19(WHAT, __VA_ARGS__)
    #define FOR_EACH_21(WHAT, X, ...) WHAT(X) FOR_EACH_20(WHAT, __VA_ARGS__)
    #define FOR_EACH_22(WHAT, X, ...) WHAT(X) FOR_EACH_21(WHAT, __VA_ARGS__)
    #define FOR_EACH_23(WHAT, X, ...) WHAT(X) FOR_EACH_22(WHAT, __VA_ARGS__)
    #define FOR_EACH_24(WHAT, X, ...) WHAT(X) FOR_EACH_23(WHAT, __VA_ARGS__)
    #define FOR_EACH_25(WHAT, X, ...) WHAT(X) FOR_EACH_24(WHAT, __VA_ARGS__)
    #define FOR_EACH_N(N, WHAT, ...) MERGE(FOR_EACH_, N) (WHAT, __VA_ARGS__)

    #define FOR_EACH(WHAT, ...) \
        FOR_EACH_N(COUNT_ARGS(__VA_ARGS__), WHAT, __VA_ARGS__)

#endif /* !MY_VAARG_H_ */

/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** int_to_hex
*/

void int_to_hex(int num, char *hex)
{
    const char hex_digit[] = "0123456789abcdef";
    int j = 0;

    for (int i = (sizeof(int) * 2) - 1; i >= 0; --i) {
        hex[j] = hex_digit[(num >> (i * 4)) & 0x0F];
        ++ j;
    }
}

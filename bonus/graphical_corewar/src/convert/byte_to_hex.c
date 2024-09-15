/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** byte_to_hex
*/

void byte_to_hex(unsigned char byte, char *hex)
{
    const char hex_digit[] = "0123456789abcdef";

    hex[0] = hex_digit[(byte >> 4) & 0x0F];
    hex[1] = hex_digit[byte & 0x0F];
}

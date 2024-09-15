/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** set_bit_to_zero
*/

void set_bit_to_zero(unsigned char *c, int index_bit)
{
    *c &= ~(1 << index_bit);
}
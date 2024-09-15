/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** extract_str_quote
*/

#include <string>
#include "my.hpp"

std::string extract_string_beetween_quotes(const std::string &texte)
{
    std::size_t start = texte.find('"');
    std::size_t end = texte.find('"', start + 1);

    if (start != std::string::npos && end != std::string::npos) {
        std::size_t longueur = end - start - 1;
        std::string sous_chaine = texte.substr(start + 1, longueur);
        return sous_chaine;
    }

    return "";
}

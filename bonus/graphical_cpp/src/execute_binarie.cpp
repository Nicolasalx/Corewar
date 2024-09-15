/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** execute_binarie
*/

#include <string>
#include <cstdlib>
#include "my.hpp"

void execute_binarie(void)
{
    std::string asmm = "./asm";
    std::string corewar = "./corewar";
    std::string line_asm;
    std::string line_cor;
    std::string champ[4] = {
        info_program[0].filepath,
        info_program[1].filepath,
        info_program[2].filepath,
        info_program[3].filepath
    };

    for (int i = 0; i < 4; ++i) {
        line_asm = "";
        line_asm += asmm;
        line_asm += " ";
        line_asm += info_program[i].filepath;
        std::system(line_asm.c_str());
    }

    line_cor = corewar;
    for (int i = 0; i < 4; ++i) {
        size_t lastDotIndex = info_program[i].filepath.find_last_of('.');
        if (lastDotIndex != std::string::npos) {
            info_program[i].filepath = info_program[i].filepath.substr(0, lastDotIndex) + ".cor";
        }
        line_cor += " ";
        line_cor += info_program[i].filepath;
    }
    std::system(line_cor.c_str());
}

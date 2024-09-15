/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** choose_random_player
*/

#include <filesystem>
#include <random>
#include "my.hpp"

void choose_random_player(char *argv[], my_linked_list_t my_linked_list)
{
    std::string folderPath = argv[1];
    if (!std::filesystem::is_directory(folderPath)) {
        put_error("Path is not a directory.\n");
        exit(84);
    }
    std::vector<std::string> filepaths;
    for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".s") {
            filepaths.push_back(entry.path().string());
        }
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, filepaths.size() - 1);
    std::vector<std::string> randomFilepaths;
    for (int i = 0; i < 4; i++) {
        int randomIndex = dist(gen);
        randomFilepaths.push_back(filepaths[randomIndex]);
    }
    for (const auto& filepath : randomFilepaths) {
        parse_each_file(filepath, my_linked_list);
    }
}

/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** setup_game
*/

#include <iostream>
#include "my.hpp"

void setup_each_champion(info_ui_t info_ui[4], sf::Font &font)
{
    int pos_x = 10;
    int pos_y = 150;
    sf::Vector2f pos(30, 150);

    for (int i = 0; i < 4; ++i) {
        char name[1000];
        int j;
        int index_str = 0;
        for (j = 0; info_program[i].name[j] != '\0'; ++j) {
            if (j % 30 == 0 && j > 1) {
                name[index_str] = '\n';
            } else {
                name[index_str] = info_program[i].name[j];
            }
            ++index_str;
        }
        name[index_str] = '\0';

        char comment[1000];
        index_str = 0;
        for (j = 0; info_program[i].comment[j] != '\0'; ++j) {
            if (j % 30 == 0 && j > 1) {
                comment[index_str] = info_program[i].comment[j];
                comment[index_str + 1] = '\n';
                ++index_str;
            } else {
                comment[index_str] = info_program[i].comment[j];
            }
            ++index_str;
        }
        comment[index_str] = '\0';

        char instruction[10000];
        index_str = 0;
        for (const auto &line : info_program[i].instruction) {
            for (int j = 0; line[j] != '\0'; ++j) {
                instruction[index_str] = line[j];
                ++index_str;
            }
            instruction[index_str] = '\n';
            ++index_str;
        }
        instruction[index_str] = '\0';
        info_ui[i].name.setString(name);
        info_ui[i].name.setFont(font);
        info_ui[i].name.setCharacterSize(30);
        info_ui[i].name.setFillColor(sf::Color::White);
        info_ui[i].name.setPosition(pos);

        pos.y += 50;
        info_ui[i].comment.setString(comment);
        info_ui[i].comment.setFont(font);
        info_ui[i].comment.setCharacterSize(20);
        info_ui[i].comment.setFillColor(sf::Color::White);
        info_ui[i].comment.setPosition(pos);

        pos.y += 50;
        info_ui[i].instruction.setString(instruction);
        info_ui[i].instruction.setFont(font);
        info_ui[i].instruction.setCharacterSize(20);
        info_ui[i].instruction.setFillColor(sf::Color::White);
        info_ui[i].instruction.setPosition(pos);

        pos.y = 150;
        pos.x += 450;
    }
}

void setup_text_launch_sim(launch_sim_t &launch_sim, sf::Font &font)
{
    launch_sim.rectangle.setSize(sf::Vector2f(400.f, 120.f));
    launch_sim.rectangle.setPosition(sf::Vector2f(1500.f, 20.f));
    launch_sim.rectangle.setFillColor(sf::Color(128, 128, 128));
    launch_sim.rectangle.setOutlineColor(sf::Color::White);
    launch_sim.rectangle.setOutlineThickness(2.f);

    launch_sim.desc.setString("Launch Simulation");
    launch_sim.desc.setFont(font);
    launch_sim.desc.setCharacterSize(30);
    launch_sim.desc.setFillColor(sf::Color::White);
    launch_sim.desc.setPosition(sf::Vector2f(1550.f, 60.f));

    launch_sim.corewar.setString("Corewar");
    launch_sim.corewar.setFont(font);
    launch_sim.corewar.setCharacterSize(100);
    launch_sim.corewar.setFillColor(sf::Color::Yellow);
    launch_sim.corewar.setPosition(sf::Vector2f(700.f, 0.f));
}

void setup_game(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
    sf::Font font;
    if (!font.loadFromFile("font/DroidSansMono.ttf")) {
        std::cerr << "Failed to load font file: font/DroidSansMono.ttf" << std::endl;
        exit(84);
    }
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("assets/background.jpg"))
        exit(84);
    sf::Sprite background(background_texture);
    background.setColor(sf::Color(255, 255, 255, 100));
    background.scale(sf::Vector2f{7, 10});
    launch_sim_t launch_sim;
    setup_text_launch_sim(launch_sim, font);
    info_ui_t info_ui[4];
    sf::View view(window.getDefaultView());

    setup_each_champion(info_ui, font);
    game_loop(window, view, info_ui, launch_sim, background);
}

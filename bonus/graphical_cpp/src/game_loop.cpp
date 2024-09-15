/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** game_loop
*/

#include "my.hpp"

void game_loop(sf::RenderWindow &window, sf::View view, info_ui_t info_ui[4], launch_sim_t launch_sim, sf::Sprite background)
{
    float height = 100.0f;
    sf::Event event;
    while (window.isOpen()) {
        manage_event(window, event, height, view, launch_sim);
        window.clear();
        window.setView(view);
        window.draw(background);
        for (int i = 0; i < 4; ++i) {
            window.draw(info_ui[i].name);
            window.draw(info_ui[i].comment);
            window.draw(info_ui[i].instruction);
            window.draw(launch_sim.rectangle);
            window.draw(launch_sim.desc);
            window.draw(launch_sim.corewar);
        }
        window.display();
    }
}
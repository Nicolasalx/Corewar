/*
** EPITECH PROJECT, 2023
** graphical_cpp
** File description:
** manage_event
*/

#include "my.hpp"

void manage_event(sf::RenderWindow &window, sf::Event &event, float &height, sf::View &view, launch_sim_t &launch_sim)
{
    float movementSpeed = 10.0f;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up && height > 100.0f) {
                view.move(0, -movementSpeed);
                height -= 10.0f;
            }
            else if (event.key.code == sf::Keyboard::Down && height < 3000.0f) {
                view.move(0, movementSpeed);
                height += 10.0f;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (launch_sim.rectangle.getGlobalBounds().contains(sf::Vector2f(mousePosition))) {
                    launch_sim.rectangle.setFillColor(sf::Color::Green);
                    execute_binarie();
                }
            }
        }
    }
}
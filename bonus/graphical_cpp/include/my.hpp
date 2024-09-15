/*
** EPITECH PROJECT, 2023
** parser_cpp
** File description:
** my
*/

#ifndef MY_HPP_
    #define MY_HPP_

    #include <string>
    #include <vector>
    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>

class node {
public:
    std::string data;
    node* next;

    node(const std::string& value);
};

class my_linked_list_t {
private:
    node* head;

public:
    my_linked_list_t(void);
    void insert(const std::string& value);
    void printList(void);
    void parse_each_line(void);
    void remove(void);
};

typedef struct {
    std::string name;
    std::string comment;
    std::vector<std::string> instruction;
    std::string filepath;
} info_program_t;

typedef struct {
    sf::Text name;
    sf::Text comment;
    sf::Text instruction;
} text_ui_t;

typedef struct {
    text_ui_t text_ui;
} ui_champions_t;

typedef struct {
    sf::Text name;
    sf::Text comment;
    sf::Text instruction;
} info_ui_t;

typedef struct {
    sf::Text corewar;
    sf::Text desc;
    sf::RectangleShape rectangle;
} launch_sim_t;

extern sf::Text name_champ_1;

extern ui_champions_t ui_champions[4];

extern info_program_t info_program[4];

extern int index_info_prog;

extern int list_len;

void put_error(const std::string &message);

std::string get_buffer_from_file(const std::string &filename);

std::string extract_string_beetween_quotes(const std::string &texte);

int error_handling(int argc);

void add_linked_file_content(my_linked_list_t &my_linked_list, std::string file_content);

void execute_binarie(void);

void parse_each_file(const std::string filepath, my_linked_list_t &my_linked_list);

void manage_event(sf::RenderWindow &window, sf::Event &event, float &height, sf::View &view, launch_sim_t &launch_sim);

void game_loop(sf::RenderWindow &window, sf::View view, info_ui_t info_ui[4], launch_sim_t launch_sim, sf::Sprite background);

void setup_game(void);

void choose_random_player(char *argv[], my_linked_list_t my_linked_list);

#endif /* !MY_HPP_ */




/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** graphical
*/

#ifndef GRAPHICAL_H_
    #define GRAPHICAL_H_

    #include <SFML/Graphics.h>
    #include "my_importall.h"
    #include "corewar.h"

    #define FRAME_RATE 60

    #define GR_CORE_TEXT_SIZE 10
    #define GR_CORE_PER_LINE 64 + 32

    #define GR_SPACE_BETWEEN_LINE 12
    #define GR_SPACE_BETWEEN_CORE 16

    #define GR_CORE_INI_POS_X 370
    #define GR_CORE_INI_POS_Y 20
    #define GR_CORE_INI_POS GR_CORE_INI_POS_X, GR_CORE_INI_POS_Y

    #define COLOR_BG_BOX 50, 50, 50, 255
    #define THICKNESS_BOX 1

typedef struct {
    sfText *text;
    sfVector2f pos;
    char *text_write;
} text_ui_t;

typedef struct {
    sfRectangleShape *box;
    sfColor color_box;
    sfVector2f pos_box;
    sfVector2f size_box;

    text_ui_t text_name;
    text_ui_t text_comment;
    text_ui_t text_alive;
} ui_champion_t;

typedef struct {
    sfRectangleShape *box;
    sfColor color_box;
    sfVector2f pos_box;
    sfVector2f size_box;

    text_ui_t menu_text;
} menu_game_t;

typedef struct {
    sfRectangleShape *box;
    sfColor color_box;
    sfVector2f pos_box;
    sfVector2f size_box;

    sfText *text;
    sfVector2f pos;
    char text_write[50];
} cycle_ui_t;

typedef struct {
    sfRectangleShape *box;
    sfColor color_box;
    sfVector2f pos_box;
    sfVector2f size_box;
} gauge_box_percent_t;

typedef struct {
    text_ui_t name_champ;
    text_ui_t percent_champ;

    gauge_box_percent_t first_box;
    gauge_box_percent_t second_box;
    text_ui_t nb_processus;
} percent_each_champ_t;

typedef struct {
    sfRectangleShape *box;
    sfColor color_box;
    sfVector2f pos_box;
    sfVector2f size_box;

    text_ui_t title;
} box_percent_control_t;

extern menu_game_t menu_game[];

extern percent_each_champ_t *percent_each_champ;

extern box_percent_control_t box_percent_control;

extern cycle_ui_t cycle_ui;

extern ui_champion_t *ui_champion;

typedef struct {
    sfText *core[MEM_SIZE];
} gr_vm_t;

extern bool game_activated;

extern bool mouse_button_pressed;

extern sfVector2i mouse_pos;

extern gr_vm_t gr_vm;
extern sfFont *gr_font;

extern sfFont *techno_font;

extern sfColor gr_player_color[];

void create_all_data(node_t *head_vm);
void create_window(void);
void update_visualization(node_t *head_vm, int num_cycle);
void lauch_menu(void);
void game_menu(void);

void create_champion(void);

int get_nb_of_champion_processus(int index_champion);

extern sfRenderWindow *gr_window;

extern size_t NB_CYCLE_PER_FRAME;

#endif /* !GRAPHICAL_H_ */

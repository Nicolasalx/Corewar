/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** create_all_data
*/

#include "corewar.h"
#include "graphical.h"

static void create_gr_vm(node_t *head_vm)
{
    char hex[3] = {0};
    int nb_core_on_line = 1;
    sfVector2f pos = {GR_CORE_INI_POS};

    for (int i = 0; i < MEM_SIZE; ++i) {
        gr_vm.core[i] = sfText_create();
        if (not gr_font) {
            print_error(RED("Fail to create text\n"));
            my_exit(84);
        }
        sfText_setFont(gr_vm.core[i], gr_font);
        sfText_setCharacterSize(gr_vm.core[i], GR_CORE_TEXT_SIZE);
        sfText_setFillColor(gr_vm.core[i],
            gr_player_color[GET_DATA(head_vm, core_t)->num_player]);
        byte_to_hex(GET_DATA(head_vm, core_t)->data, hex);
        sfText_setString(gr_vm.core[i], hex);
        sfText_setPosition(gr_vm.core[i], pos);
        ++ nb_core_on_line;
        head_vm = head_vm->next;
        pos.x += GR_SPACE_BETWEEN_CORE;
        if (nb_core_on_line > GR_CORE_PER_LINE) {
            pos.x = GR_CORE_INI_POS_X;
            pos.y += GR_SPACE_BETWEEN_LINE;
            nb_core_on_line = 1;
        }
    }
}

cycle_ui_t cycle_ui = {
    .color_box = {128, 128, 128, 255},
    .pos_box = {10, 820},
    .size_box = {330, 180},
    .pos = {20, 900},
    .text_write = "Nb cycle = 0",
};

box_percent_control_t box_percent_control = {
    .color_box = {255, 255, 255, 255},
    .pos_box = {370, 820},
    .size_box = {1530, 180},
    .title.pos = {1000, 830},
    .title.text_write = "Percent Control"
};

void create_cycle_ui(void)
{
    cycle_ui.box = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(cycle_ui.box, THICKNESS_BOX);
    sfRectangleShape_setOutlineColor(cycle_ui.box, (sfColor) {255, 255, 255, 255});
    sfRectangleShape_setFillColor(cycle_ui.box, (sfColor) {COLOR_BG_BOX});
    sfRectangleShape_setPosition(cycle_ui.box, cycle_ui.pos_box);
    sfRectangleShape_setSize(cycle_ui.box, cycle_ui.size_box);

    cycle_ui.text = sfText_create();
    sfText_setFont(cycle_ui.text, gr_font);
    sfText_setPosition(cycle_ui.text, cycle_ui.pos);
    sfText_setString(cycle_ui.text, cycle_ui.text_write);
    sfText_setFillColor(cycle_ui.text, (sfColor) {255, 255, 255, 255});
    sfText_setCharacterSize(cycle_ui.text, 20);
}

void create_percent_control_byte(void)
{
    box_percent_control.box = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(box_percent_control.box, THICKNESS_BOX);
    sfRectangleShape_setOutlineColor(box_percent_control.box, (sfColor) {255, 255, 255, 255});
    sfRectangleShape_setFillColor(box_percent_control.box, (sfColor) {COLOR_BG_BOX});
    sfRectangleShape_setPosition(box_percent_control.box, box_percent_control.pos_box);
    sfRectangleShape_setSize(box_percent_control.box, box_percent_control.size_box);

    box_percent_control.title.text = sfText_create();
    sfText_setFont(box_percent_control.title.text, gr_font);
    sfText_setPosition(box_percent_control.title.text, box_percent_control.title.pos);
    sfText_setString(box_percent_control.title.text, box_percent_control.title.text_write);
    sfText_setFillColor(box_percent_control.title.text, (sfColor) {255, 255, 255, 255});
    sfText_setCharacterSize(box_percent_control.title.text, 20);
}

sfFont *techno_font;
percent_each_champ_t *percent_each_champ;

void create_percent_each_champion(void)
{
    percent_each_champ = my_malloc(sizeof(percent_each_champ_t) * nb_champion);
    int pos_x = 600;

    for (int i = 0; i < nb_champion; ++i) {
        percent_each_champ[i].name_champ.text = sfText_create();
        sfText_setFont(percent_each_champ[i].name_champ.text, gr_font);
        percent_each_champ[i].name_champ.pos = (sfVector2f) {pos_x, 860};
        sfText_setPosition(percent_each_champ[i].name_champ.text, percent_each_champ[i].name_champ.pos);
        sfText_setString(percent_each_champ[i].name_champ.text, ref_champion[i].header.prog_name);
        sfText_setFillColor(percent_each_champ[i].name_champ.text, gr_player_color[i]);
        sfText_setCharacterSize(percent_each_champ[i].name_champ.text, 30);

        percent_each_champ[i].percent_champ.text = sfText_create();
        sfText_setFont(percent_each_champ[i].percent_champ.text, gr_font);
        percent_each_champ[i].percent_champ.pos = (sfVector2f) {pos_x + 50, 905};
        sfText_setPosition(percent_each_champ[i].percent_champ.text, percent_each_champ[i].percent_champ.pos);
        sfText_setString(percent_each_champ[i].percent_champ.text, "abc");
        sfText_setFillColor(percent_each_champ[i].percent_champ.text, (sfColor) {255, 255, 255, 255});
        sfText_setCharacterSize(percent_each_champ[i].percent_champ.text, 30);

        percent_each_champ[i].first_box.box = sfRectangleShape_create();
        sfRectangleShape_setOutlineThickness(percent_each_champ[i].first_box.box, THICKNESS_BOX);
        sfRectangleShape_setOutlineColor(percent_each_champ[i].first_box.box, (sfColor) {255, 255, 255, 255});
        sfRectangleShape_setFillColor(percent_each_champ[i].first_box.box, (sfColor) {COLOR_BG_BOX});
        percent_each_champ[i].first_box.pos_box = (sfVector2f) {pos_x, 900};
        percent_each_champ[i].first_box.size_box = (sfVector2f) {200, 50};
        sfRectangleShape_setPosition(percent_each_champ[i].first_box.box, percent_each_champ[i].first_box.pos_box);
        sfRectangleShape_setSize(percent_each_champ[i].first_box.box, percent_each_champ[i].first_box.size_box);

        percent_each_champ[i].second_box.box = sfRectangleShape_create();
        sfRectangleShape_setOutlineThickness(percent_each_champ[i].second_box.box, THICKNESS_BOX);
        sfRectangleShape_setOutlineColor(percent_each_champ[i].second_box.box, (sfColor) {255, 255, 255, 255});
        sfRectangleShape_setFillColor(percent_each_champ[i].second_box.box, (sfColor) gr_player_color[i]);
        percent_each_champ[i].second_box.pos_box = (sfVector2f) {pos_x, 900};
        percent_each_champ[i].second_box.size_box = (sfVector2f) {200, 50};
        sfRectangleShape_setPosition(percent_each_champ[i].second_box.box, percent_each_champ[i].second_box.pos_box);
        sfRectangleShape_setSize(percent_each_champ[i].second_box.box, percent_each_champ[i].second_box.size_box);

        percent_each_champ[i].nb_processus.text = sfText_create();
        sfText_setFont(percent_each_champ[i].nb_processus.text, gr_font);
        percent_each_champ[i].nb_processus.pos = (sfVector2f) {pos_x, 955};
        sfText_setPosition(percent_each_champ[i].nb_processus.text, percent_each_champ[i].nb_processus.pos);
        sfText_setString(percent_each_champ[i].nb_processus.text, "abc");
        sfText_setFillColor(percent_each_champ[i].nb_processus.text, (sfColor) {255, 255, 255, 255});
        sfText_setCharacterSize(percent_each_champ[i].nb_processus.text, 30);

        pos_x += 300;
    }
}

bool game_activated = false;

menu_game_t menu_game[] = {
    {
        .pos_box = {0, 0},
        .size_box = {0, 0},

        .menu_text.pos = {600, 100},
        .menu_text.text_write = "Corewar"
    },
    {
        .pos_box = {420, 500},
        .size_box = {1100, 300},

        .menu_text.pos = {620, 580},
        .menu_text.text_write = "Launch Game"
    }
};

void create_menu_game(void)
{
    for (int i = 0; i < 2; ++i) {
        menu_game[i].box = sfRectangleShape_create();
        sfRectangleShape_setOutlineThickness(menu_game[i].box, 2);
        sfRectangleShape_setOutlineColor(menu_game[i].box, (sfColor) {255, 255, 255, 255});
        sfRectangleShape_setFillColor(menu_game[i].box, (sfColor) {0, 0, 0, 255});
        sfRectangleShape_setPosition(menu_game[i].box, menu_game[i].pos_box);
        sfRectangleShape_setSize(menu_game[i].box, menu_game[i].size_box);

        menu_game[i].menu_text.text = sfText_create();
        if (i == 0) {
            sfText_setFont(menu_game[i].menu_text.text, techno_font);
        } else {
            sfText_setFont(menu_game[i].menu_text.text, gr_font);
        }
        sfText_setPosition(menu_game[i].menu_text.text, menu_game[i].menu_text.pos);
        sfText_setString(menu_game[i].menu_text.text, menu_game[i].menu_text.text_write);
        if (i == 0) {
            sfText_setFillColor(menu_game[i].menu_text.text, (sfColor) {255, 255, 0, 255});
        } else {
            sfText_setFillColor(menu_game[i].menu_text.text, (sfColor) {255, 255, 255, 255});
        }
        sfText_setCharacterSize(menu_game[i].menu_text.text, 100);
    }
}

void create_all_data(node_t *head_vm)
{
    gr_font = sfFont_createFromFile("font/DroidSansMono.ttf");
    techno_font = sfFont_createFromFile("font/Technos-PKDZP.ttf");
    if (not gr_font) {
        print_error(RED("Fail to create font\n"));
        my_exit(84);
    }
    create_gr_vm(head_vm);
    create_cycle_ui();
    create_champion();
    create_menu_game();
    create_percent_control_byte();
    create_percent_each_champion();
}

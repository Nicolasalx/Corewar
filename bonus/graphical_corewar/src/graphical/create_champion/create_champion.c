/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** create_champion
*/

#include "corewar.h"
#include "graphical.h"

#define MARGIN_LEFT_TEXT_UI 20
#define CHARACTER_SIZE_UI 20

ui_champion_t *ui_champion;

void create_champion(void)
{
    static int pos_box_y = 25;
    ui_champion = my_malloc(sizeof(ui_champion_t) * nb_champion);

    for (int i = 0; i < nb_champion; ++i) {
        ui_champion[i].box = sfRectangleShape_create();
        ui_champion[i].pos_box = (sfVector2f) {10, pos_box_y};
        ui_champion[i].size_box = (sfVector2f) {330, 160};
        sfRectangleShape_setOutlineThickness(ui_champion[i].box, THICKNESS_BOX);
        sfRectangleShape_setOutlineColor(ui_champion[i].box, (sfColor) {255, 255, 255, 255});
        sfRectangleShape_setFillColor(ui_champion[i].box, (sfColor) {COLOR_BG_BOX});
        sfRectangleShape_setPosition(ui_champion[i].box, ui_champion[i].pos_box);
        sfRectangleShape_setSize(ui_champion[i].box, ui_champion[i].size_box);

        ui_champion[i].text_name.text = sfText_create();
        sfText_setFont(ui_champion[i].text_name.text, gr_font);
        ui_champion[i].text_name.pos = (sfVector2f) {MARGIN_LEFT_TEXT_UI, pos_box_y + 10};
        ui_champion[i].text_name.text_write = ref_champion[i].header.prog_name;
        pos_box_y += 50;
        sfText_setPosition(ui_champion[i].text_name.text, ui_champion[i].text_name.pos);
        sfText_setString(ui_champion[i].text_name.text, ui_champion[i].text_name.text_write);
        sfText_setFillColor(ui_champion[i].text_name.text, gr_player_color[i]);
        sfText_setCharacterSize(ui_champion[i].text_name.text, CHARACTER_SIZE_UI);

        ui_champion[i].text_comment.text = sfText_create();
        sfText_setFont(ui_champion[i].text_comment.text, gr_font);
        ui_champion[i].text_comment.pos = (sfVector2f) {MARGIN_LEFT_TEXT_UI, pos_box_y};
        ui_champion[i].text_comment.text_write = ref_champion[i].header.comment;
        pos_box_y += 50;
        sfText_setPosition(ui_champion[i].text_comment.text, ui_champion[i].text_comment.pos);
        sfText_setString(ui_champion[i].text_comment.text, ui_champion[i].text_comment.text_write);
        sfText_setFillColor(ui_champion[i].text_comment.text, gr_player_color[i]);
        sfText_setCharacterSize(ui_champion[i].text_comment.text, CHARACTER_SIZE_UI);

        ui_champion[i].text_alive.text = sfText_create();
        sfText_setFont(ui_champion[i].text_alive.text, gr_font);
        ui_champion[i].text_alive.pos = (sfVector2f) {MARGIN_LEFT_TEXT_UI, pos_box_y};
        ui_champion[i].text_alive.text_write = "Alive : True";
        pos_box_y += 100;
        sfText_setPosition(ui_champion[i].text_alive.text, ui_champion[i].text_alive.pos);
        sfText_setString(ui_champion[i].text_alive.text, ui_champion[i].text_alive.text_write);
        sfText_setFillColor(ui_champion[i].text_alive.text, (sfColor) {255, 255, 255, 255});
        sfText_setCharacterSize(ui_champion[i].text_alive.text, CHARACTER_SIZE_UI);
    }
}

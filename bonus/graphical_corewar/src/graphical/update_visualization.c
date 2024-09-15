/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-corewar-thibaud.cathala
** File description:
** update_visualization
*/

#include "graphical.h"
#include "corewar.h"

static void render_ui_champion(void)
{
    for (int i = 0; i < nb_champion; ++i) {
        sfRenderWindow_drawRectangleShape(gr_window, ui_champion[i].box, NULL);
        sfRenderWindow_drawText(gr_window, ui_champion[i].text_name.text, NULL);
        sfRenderWindow_drawText(gr_window, ui_champion[i].text_comment.text, NULL);
        ui_champion[i].text_alive.text_write = my_calloc(sizeof(char) * 50);
        if (head_all_champion[i] != NULL) {
            build_str(ui_champion[i].text_alive.text_write, ui_champion[i].text_name.text_write, " is alive");
        } else {
            sfText_setFillColor(ui_champion[i].text_alive.text, (sfColor) {255, 0, 0, 255});
            build_str(ui_champion[i].text_alive.text_write, ui_champion[i].text_name.text_write, " is dead");
        }
        sfText_setString(ui_champion[i].text_alive.text, ui_champion[i].text_alive.text_write);
        sfRenderWindow_drawText(gr_window, ui_champion[i].text_alive.text, NULL);
    }
}

static void render_cycle_ui(int num_cycle)
{
    sfRenderWindow_drawRectangleShape(gr_window, cycle_ui.box, NULL);
    my_memset(cycle_ui.text_write, 0, 50);
    build_str(cycle_ui.text_write, "Nb_cycle = ", INT(num_cycle));
    sfText_setString(cycle_ui.text, cycle_ui.text_write);

    sfRenderWindow_drawText(gr_window, cycle_ui.text, NULL);
}

static bool is_pc(node_t *current_cor)
{
    node_t *current = NULL;
    bool result = false;

    for (int i = 0; i < nb_champion; ++i) {
        if (head_all_champion[i] == NULL) {
            continue;
        }
        current = head_all_champion[i];
        do {
            result = result ? result :
            (GET_DATA(current, champion_t)->pc_ptr == current_cor);
            current = current->next;
        } while (current != head_all_champion[i]);
    }
    return result;
}

static void update_vm_core(node_t *head_vm)
{
    char hex[3] = {0};
    sfRectangleShape *rect_cursor;

    for (int i = 0; i < MEM_SIZE; ++i) {
        if (is_pc(head_vm)) {
            rect_cursor = sfRectangleShape_create();
            sfRectangleShape_setPosition(rect_cursor, sfText_getPosition(gr_vm.core[i]));
            sfRectangleShape_setSize(rect_cursor, (sfVector2f) {13, 12});
            sfRectangleShape_setFillColor(rect_cursor, gr_player_color[GET_DATA(head_vm, core_t)->num_player]);
            if (not is_instruction_exist(GET_DATA(head_vm, core_t)->data)) {
                sfRectangleShape_setFillColor(rect_cursor, (sfColor) {
                    gr_player_color[GET_DATA(head_vm, core_t)->num_player].r,
                    gr_player_color[GET_DATA(head_vm, core_t)->num_player].g,
                    gr_player_color[GET_DATA(head_vm, core_t)->num_player].b,
                    gr_player_color[GET_DATA(head_vm, core_t)->num_player].a * 0.3});
            }
            sfText_setFillColor(gr_vm.core[i], (sfColor) {0, 0, 0, 255});
            sfRenderWindow_drawRectangleShape(gr_window, rect_cursor, NULL);
            sfRectangleShape_destroy(rect_cursor);
        } else {
            sfText_setFillColor(gr_vm.core[i],
            gr_player_color[GET_DATA(head_vm, core_t)->num_player]);
        }
        byte_to_hex(GET_DATA(head_vm, core_t)->data, hex);
        sfText_setString(gr_vm.core[i], hex);
        sfRenderWindow_drawText(gr_window, gr_vm.core[i], NULL);
        head_vm = head_vm->next;
    }
}

static void render_box_percent(void)
{
    sfRenderWindow_drawRectangleShape(gr_window, box_percent_control.box, NULL);
    sfRenderWindow_drawText(gr_window, box_percent_control.title.text, NULL);
}

static void count_coverage_each_champ(node_t *head_vm, int *coverage_champ)
{
    node_t *current = head_vm;
    if (head_vm == NULL) {
        return;
    }
    do {
        ++ coverage_champ[GET_DATA(current, core_t)->num_player];
        current = current->next;
    } while (current != head_vm);
}

static void render_each_percent_champion(node_t *head_vm)
{
    int coverage_champ[5] = {0};
    double size_gauge = 0.0;

    count_coverage_each_champ(head_vm, coverage_champ);

    for (int i = 0; i < nb_champion; ++i) {
        char str[100] = {0};
        char nb_processus[12] = {0};
        build_str(str, DOUBLE(((double) coverage_champ[i] / MEM_SIZE) * 100.0, 2), "%");
        size_gauge = 0.0;
        size_gauge = (((((double)coverage_champ[i] / MEM_SIZE) * 100.0) * 100.0) / 100.0) * 2;
        sfText_setString(percent_each_champ[i].percent_champ.text, str);
        sfRenderWindow_drawText(gr_window, percent_each_champ[i].name_champ.text, NULL);
        percent_each_champ[i].second_box.size_box = (sfVector2f) {size_gauge, 50};
        sfRectangleShape_setSize(percent_each_champ[i].second_box.box, percent_each_champ[i].second_box.size_box);
        sfRenderWindow_drawRectangleShape(gr_window, percent_each_champ[i].first_box.box, NULL);
        sfRenderWindow_drawRectangleShape(gr_window, percent_each_champ[i].second_box.box, NULL);
        sfRenderWindow_drawText(gr_window, percent_each_champ[i].percent_champ.text, NULL);

        build_str(nb_processus, "nb proc : ", INT(get_nb_of_champion_processus(i)));
        sfText_setString(percent_each_champ[i].nb_processus.text, nb_processus);
        sfRenderWindow_drawText(gr_window, percent_each_champ[i].nb_processus.text, NULL);
    }
}

void game_loop(node_t *head_vm, int num_cycle)
{
    if (game_activated == true) {
        update_vm_core(head_vm);
        render_ui_champion();
        render_cycle_ui(num_cycle);
        render_box_percent();
        render_each_percent_champion(head_vm);
    }
}

sfBool is_mouse_over_rectangle_shape(sfRectangleShape* rectangle_shape)
{
    sfFloatRect rectangle_bound =
    sfRectangleShape_getGlobalBounds(rectangle_shape);
    return sfFloatRect_contains(&rectangle_bound, mouse_pos.x, mouse_pos.y);
}

void game_menu(void)
{
    if (game_activated == true) {
        return;
    }
    for (int i = 0; i < 2; ++i) {
        if (mouse_button_pressed == true && is_mouse_over_rectangle_shape(menu_game[i].box) == true) {
            game_activated = true;
        }
        sfRenderWindow_drawRectangleShape(gr_window, menu_game[i].box, NULL);
        sfRenderWindow_drawText(gr_window, menu_game[i].menu_text.text, NULL);
    }
}

sfVector2i mouse_pos;
bool mouse_button_pressed;

static void set_nb_cycle_per_frame(void)
{
    size_t total_process = 0;
    for (int i = 0; i < nb_champion; ++i) {
        total_process += get_nb_of_champion_processus(i);
    }
    if (total_process > 2000) {
        NB_CYCLE_PER_FRAME = 1;
    } else if (total_process > 1500) {
        NB_CYCLE_PER_FRAME = 5;
    } else {
        NB_CYCLE_PER_FRAME = 10;
    }
}

void update_visualization(node_t *head_vm, int num_cycle)
{
    game_loop(head_vm, num_cycle);
    set_nb_cycle_per_frame();
}

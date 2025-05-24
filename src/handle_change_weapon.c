/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** handle_change_weapon
*/

#include "../include/wolf.h"
#include "../include/struct.h"

//gives the number of weapons
static int get_nb_weapons(player_t *player)
{
    weapon_t *tmp = player->weapon;
    int count = 0;

    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

//changes the weapon with the numpad
static void handle_change_button_weapon(player_t *player, sfEvent event)
{
    if (event.key.code == sfKeyNum1 && 0 <= get_nb_weapons(player))
        change_to_id(player, 0);
    if (event.key.code == sfKeyNum2 && 1 <= get_nb_weapons(player))
        change_to_id(player, 1);
    if (event.key.code == sfKeyNum3 && 2 <= get_nb_weapons(player))
        change_to_id(player, 2);
    if (event.key.code == sfKeyNum4 && 3 <= get_nb_weapons(player))
        change_to_id(player, 3);
    if (event.key.code == sfKeyNum5 && 4 <= get_nb_weapons(player))
        change_to_id(player, 4);
}

// changes the weapon with the scroll
static void mouse_scroll_change(player_t *player, sfEvent event)
{
    if (event.mouseWheelScroll.delta > 0 &&
        player->weapon->id + 1 < get_nb_weapons(player))
        change_to_id(player, player->weapon->id + 1);
    else if (event.mouseWheelScroll.delta < 0 &&
        player->weapon->id - 1 < get_nb_weapons(player))
        change_to_id(player, player->weapon->id - 1);
}

/// changes the weapon with scroll or numpad
void handle_change_weapon(player_t *player, sfEvent event)
{
    if (!player->weapon)
        return;
    if (event.type == sfEvtMouseWheelScrolled &&
        event.mouseWheelScroll.wheel == sfMouseVerticalWheel)
        return mouse_scroll_change(player, event);
    return handle_change_button_weapon(player, event);
}

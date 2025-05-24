/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** change_weapon_to_id
*/

#include "../include/struct.h"

//changes the weapon to the one with the id
void change_to_id(player_t *player, int id)
{
    while (player->weapon->id != id && player->weapon->last != NULL)
        player->weapon = player->weapon->last;
    while (player->weapon->id != id && player->weapon->next != NULL)
        player->weapon = player->weapon->next;
}

/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** handle_shoot
*/

#include "../include/struct.h"
#include <stdio.h>

// updates the animation
void update_shoot_animation(weapon_t *weapon,
    sfIntRect *rectangle, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);
    double firerate = weapon->firerate * 0.1f;

    if (!weapon)
        return;
    if (seconds >= firerate) {
        if (rectangle->left != 0 && rectangle->left < 1000) {
            rectangle->left += 205;
            sfSprite_setTextureRect(weapon->sprite, *rectangle);
            sfClock_restart(clock);
        }
        if (rectangle->left >= 1000) {
            rectangle->left = 0;
            sfSprite_setTextureRect(weapon->sprite, *rectangle);
            sfClock_restart(clock);
        }
    }
}

//looks when the left mouse click happens
void trigger_shoot(weapon_t *weapon, sfIntRect *rectangle,
    sfClock *clock, sfEvent event)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (!weapon)
        return;
    if (event.type == sfEvtMouseButtonPressed &&
        rectangle->left == 0 && seconds >= 0.1f && weapon->ammo != 0) {
        weapon->ammo--;
        sfSound_play(weapon->sound);
        rectangle->left += 205;
        sfSprite_setTextureRect(weapon->sprite, *rectangle);
        sfClock_restart(clock);
    }
}

//makes the animation of the shoot
void handle_shoot(player_t *player, sfEvent event)
{
    weapon_t *weapon = player->weapon;
    static sfIntRect rectangle = {0, 0, 205, 205};
    static sfClock *clock = NULL;

    if (!clock)
        clock = sfClock_create();
    update_shoot_animation(weapon, &rectangle, clock);
    trigger_shoot(weapon, &rectangle, clock, event);
}

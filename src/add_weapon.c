/*
** EPITECH PROJECT, 2025
** wolf3dwactest
** File description:
** add_weapon
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// Adds a new weapon to the linked list
static void add_new_weapon(weapon_t **weapon, weapon_t *new_weapon)
{
    weapon_t *tmp;

    if (!*weapon) {
        *weapon = new_weapon;
        return;
    }
    tmp = *weapon;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_weapon;
    new_weapon->last = tmp;
}

//initializes weapons's statistics
static void set_weapon_stats(weapon_t *weapon, char **object)
{
    char *content = get_name("\nammo", object);

    if (content)
        weapon->ammo = atoi(content);
    content = get_name("\ndmg", object);
    if (content)
        weapon->damage = atoi(content);
    content = get_name("\nmax", object);
    if (content)
        weapon->max_ammo = atoi(content);
    content = get_name("\nsound", object);
    if (content)
        weapon->sbuffer = sfSoundBuffer_createFromFile(content);
    content = get_name("\nfirerate", object);
        if (content)
            weapon->firerate = atoi(content);
}

static void set_sprite_stats(sfSprite *sprite, sfTexture *texture,
    sfRenderWindow *window)
{
        sfIntRect rect = {0, 0, 205, 205};
        sfVector2f pos = {
            sfRenderWindow_getSize(window).x / 2,
            sfRenderWindow_getSize(window).y - 205
        };

        sfSprite_setOrigin(sprite, (sfVector2f){140, 102});
        sfSprite_setPosition(sprite, pos);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTextureRect(sprite, rect);
}

static int verify_texture(sfTexture *texture)
{
    sfVector2u size = sfTexture_getSize(texture);

    if (size.x >= 950 && size.x <= 1050)
        return 0;
    return 1;
}

static void init_weapon_stats(weapon_t *weapon, char **object,
    sfRenderWindow *window)
{
    char *content = get_name("\nsprite", object);

    set_weapon_stats(weapon, object);
    if (content) {
        weapon->texture = sfTexture_createFromFile(content, NULL);
        if (!weapon->texture) {
            return;
        }
        if (verify_texture(weapon->texture) != 0) {
            sfTexture_destroy(weapon->texture);
            weapon->texture = NULL;
            return;
        }
        set_sprite_stats(weapon->sprite, weapon->texture, window);
    }
}

// creates a node to the linked list weapon
static weapon_t *create_weapon(int id, char **object, sfRenderWindow *window)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (!weapon)
        return NULL;
    weapon->id = id;
    weapon->sprite = sfSprite_create();
    weapon->sound = sfSound_create();
    weapon->next = NULL;
    weapon->last = NULL;
    init_weapon_stats(weapon, object, window);
    if ((!weapon->sprite) || (!weapon->sound) || (!weapon->sbuffer)
        || (!weapon->texture)) {
        free_weapon(weapon);
        return NULL;
    }
    sfSound_setBuffer(weapon->sound, weapon->sbuffer);
    return weapon;
}

//adds a weapon
void add_weapon(char **object, data_t *data, sfRenderWindow *window)
{
    static int id = 0;
    weapon_t *new_weapon;

    if (!object || !data || !data->player)
        return;
    new_weapon = create_weapon(id, object, window);
    if (new_weapon) {
        add_new_weapon(&data->player->weapon, new_weapon);
        id++;
    }
}

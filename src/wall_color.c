/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** wall_color
*/

#include "../include/struct.h"

// give the color from a ray
static sfColor get_base_wall_color(ray_t *ray)
{
    if (ray->side == 0)
        return sfColor_fromRGB(255, 0, 0);
    else
        return sfColor_fromRGB(255, 0, 0);
}

//applies shadows effect
static void apply_side_shading(sfColor *color, ray_t *ray)
{
    if (ray->side == 1) {
        color->r /= 2;
        color->g /= 2;
        color->b /= 2;
    }
}

// applies flashlights effects
static void apply_flashlight_effect(sfColor *color,
    ray_t *ray, player_t *player)
{
    float brightness = 1.0f;

    if (!player)
        return;
    if (player->flashlight_on == 0) {
        if (ray->perp_wall_dist > 2.0f)
            brightness = 1.0f / (ray->perp_wall_dist / 2.0f);
        if (brightness < 0.1f)
            brightness = 0.1f;
        color->r *= brightness;
        color->g *= brightness;
        color->b *= brightness;
    }
}

// gives the color of a wall
sfColor get_wall_color(ray_t *ray, player_t *player)
{
    sfColor color = get_base_wall_color(ray);

    if (!ray || !player)
        return color;
    apply_side_shading(&color, ray);
    apply_flashlight_effect(&color, ray, player);
    return color;
}

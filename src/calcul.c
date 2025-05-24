/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** calcul
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// calculates the data from the ray's projection
void calculate_projection_data(ray_t *ray, float pos_x, float pos_y)
{
    if (ray->side == 0)
        ray->perp_wall_dist =
            (ray->map_x - pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->perp_wall_dist =
            (ray->map_y - pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

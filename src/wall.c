/*
** EPITECH PROJECT, 2025
** wolf3d_clone
** File description:
** Simple raycasting engine
*/

#include "../include/struct.h"
#include "../include/wolf.h"

//makes the player turn with the mouse
void handle_mouse_rotation(sfRenderWindow *window, player_t *player)
{
    static const float sensitivity = 0.002f;
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfVector2i center = { (int)(win_size.x / 2), (int)(win_size.y / 2) };
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int delta_x = mouse_pos.x - center.x;
    float angle = -delta_x * sensitivity;
    float old_dir_x = player->dirX;
    float old_plane_x = player->planeX;

    if (delta_x != 0) {
        player->dirX = player->dirX * cos(angle) - player->dirY * sin(angle);
        player->dirY = old_dir_x * sin(angle) + player->dirY * cos(angle);
        player->planeX =
            player->planeX * cos(angle) - player->planeY * sin(angle);
        player->planeY =
            old_plane_x * sin(angle) + player->planeY * cos(angle);
        sfMouse_setPositionRenderWindow(center, window);
    }
}

// give wall's collisions
void try_move(map_t *map, float *pos_x, float *pos_y, sfVector2f move)
{
    float next_x = *pos_x + move.x;
    float next_y = *pos_y + move.y;

    if (map->map[(int)(*pos_y)][(int)(next_x)] != 'W')
        *pos_x = next_x;
    if (map->map[(int)(next_y)][(int)(*pos_x)] != 'W')
        *pos_y = next_y;
}

// handle player's movement
void handle_movement(player_t *player, float frame_time, map_t *map)
{
    int move_speed = MOVE_SPEED;
    float speed;

    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        move_speed += 7;
    speed = move_speed * frame_time;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        try_move(map, &player->pos_x, &player->pos_y,
        (sfVector2f){player->dirX * speed, player->dirY * speed});
    if (sfKeyboard_isKeyPressed(sfKeyS))
        try_move(map, &player->pos_x, &player->pos_y,
        (sfVector2f){- player->dirX * speed, - player->dirY * speed});
    if (sfKeyboard_isKeyPressed(sfKeyD))
        try_move(map, &player->pos_x, &player->pos_y,
        (sfVector2f){player->planeX * speed, player->planeY * speed});
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        try_move(map, &player->pos_x, &player->pos_y,
        (sfVector2f){- player->planeX * speed, - player->planeY * speed});
}

// inits the direction of a ray and the deltas
static void init_ray_direction_and_deltas(ray_t *ray, int x, player_t *player)
{
    float camera_x = 2 * x / (float)SCREEN_WIDTH - 1;

    ray->ray_dir_x = player->dirX + player->planeX * camera_x;
    ray->ray_dir_y = player->dirY + player->planeY * camera_x;
    ray->map_x = (int)player->pos_x;
    ray->map_y = (int)player->pos_y;
    ray->delta_dist_x =
        (ray->ray_dir_x == 0) ? 1e30 : fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y =
        (ray->ray_dir_y == 0) ? 1e30 : fabs(1 / ray->ray_dir_y);
    ray->hit = 0;
}

// init rays's steps and sidedists
static void init_ray_steps_and_sidedists(ray_t *ray, player_t *player)
{
    if (ray->ray_dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x =
            (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y =
            (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
    }
}

// inits a ray for raycasting
static void init_ray_data(ray_t *ray, int x, player_t *player)
{
    init_ray_direction_and_deltas(ray, x, player);
    init_ray_steps_and_sidedists(ray, player);
}

//draws the walls
static void draw_wall_column(sfRenderWindow *window, int x,
    ray_t *ray, player_t *player)
{
    int line_height;
    int draw_start;
    int draw_end;
    sfVertex line[2];

    line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
    draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
    draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= SCREEN_HEIGHT)
        draw_end = SCREEN_HEIGHT - 1;
    line[0].position = (sfVector2f){x, draw_start};
    line[0].color = get_wall_color(ray, player);
    line[0].texCoords = (sfVector2f){0, 0};
    line[1].position = (sfVector2f){x, draw_end};
    line[1].color = get_wall_color(ray, player);
    line[1].texCoords = (sfVector2f){0, 0};
    sfRenderWindow_drawPrimitives(window, line, 2, sfLines, NULL);
}

// raycasting with the map
static void perform_dda(ray_t *ray, map_t *map)
{
    while (!ray->hit) {
        if (ray->side_dist_x < ray->side_dist_y) {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        } else {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (map->map[ray->map_y][ray->map_x] == 'W')
            ray->hit = 1;
    }
}

// displays the walls
void render_walls(sfRenderWindow *window,
    player_t *player, map_t *map, float *z_buffer)
{
    ray_t ray;

    for (int x = 0; x < SCREEN_WIDTH; x++) {
        init_ray_data(&ray, x, player);
        perform_dda(&ray, map);
        calculate_projection_data(&ray, player->pos_x, player->pos_y);
        z_buffer[x] = ray.perp_wall_dist;
        draw_wall_column(window, x, &ray, player);
    }
}

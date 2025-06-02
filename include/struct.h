/*
** EPITECH PROJECT, 2025
** csfml
** File description:
** sprite.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <math.h>

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define MOVE_SPEED 4
    #define ROT_SPEED 3
    #define MINIMAP_SCALE 8
    #define MINIMAP_MARGIN 10


//structures for data
typedef struct enemy {
    struct enemy *next;
    struct enemy *previous;
    int hp;
    int dmg;
    int firerate;
    int fire_distance;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f e_pos;
} enemy_t;

typedef struct weapon {
    int damage;
    int firerate;
    int max_ammo;
    int ammo;
    int fire_distance;
    int id;
    char *filepath;
    struct weapon *next;
    struct weapon *last;
    sfSprite *sprite;
    sfSound *sound;
    sfSoundBuffer *sbuffer;
    sfTexture *texture;
} weapon_t;

typedef struct ray {
    float ray_dir_x;
    float ray_dir_y;
    int map_x;
    int map_y;
    float side_dist_x;
    float side_dist_y;
    float delta_dist_x;
    float delta_dist_y;
    float perp_wall_dist;
    int step_x;
    int step_y;
    int side;
    int hit;
} ray_t;

typedef struct player {
    int hp;
    int max_hp;
    int min_hp;
    int money;
    float pos_x;
    float pos_y;
    float end_x;
    float end_y;
    float dirX;
    float dirY;
    float angle;
    float planeX;
    float planeY;
    int flashlight_on;
    weapon_t *weapon;
} player_t;

typedef struct map {
    int height;
    int length;
    int id;
    char **map;
    struct map *next;
    struct map *last;
    sfMusic *music;
} map_t;

typedef struct save {
    int lv;
    int hp;
    int nb_weapons;
    int money;
    int *ammo;
}save_t;

//data
typedef struct data {
    player_t *player;
    map_t *map;
    enemy_t *enemy;
    save_t *save;
}data_t;


typedef struct obj {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f e_pos;
} obj_t;

    #define TILE_SIZE 64
    #define M_PI 3.14159265358979323846

//window structure
typedef struct wd {
    sfRenderWindow *window;
    sfVideoMode vm;
    sfTexture *text;
    sfSprite *sprite;
    sfEvent event;
    int music_muted;
    int sound_muted;
    obj_t *head;
} wd_t;

//menu structure
typedef struct menu {
    sfSprite* play_button;
    sfSprite* quit_button;
    sfTexture* play_texture;
    sfTexture* quit_texture;
    sfRectangleShape* play_box;
    sfRectangleShape* quit_box;
    sfSprite* bg_sprite;
    sfTexture* bg_texture;
    sfTexture *settings_texture;
    sfSprite *settings_button;
} menu_t;

typedef struct settings {
    sfRenderWindow **window_ptr;
    sfText *title;
    sfText *audio;
    sfText *video;
    sfText *volume;
    sfFont *font;
} settings_t;

//functions using the structures
sfColor get_wall_color(ray_t *ray, player_t *player);
void draw_minimap(sfRenderWindow *window, map_t *map, player_t *player);
int launch_game(int game_status, char *filepath);
void fill_enemies(map_t *map, data_t *data);
void add_enemy(int pos_x, int pos_y, data_t *data);
void update_enemies(enemy_t *enemies, player_t *player,
    map_t *map, float *z_buffer);
void draw_enemies(sfRenderWindow *window, enemy_t *enemies,
    player_t *player, float *z_buffer);
map_t *create_valid_map(map_t *map);
void calculate_projection_data(ray_t *ray, float pos_x, float pos_y);
void handle_mouse_rotation(sfRenderWindow *window, player_t *player);
void handle_movement(player_t *player, float frame_time, map_t *map);
void render_walls(sfRenderWindow *window,
    player_t *player, map_t *map, float *z_buufer);
void draw_floor_plus_ceiling(sfRenderWindow* window);
wd_t *create_window(int vm);
menu_t *create_menu(sfRenderWindow *window);
map_t *generate_map_from_file(char *file);
void give_player_stat(player_t *player);
void change_to_id(player_t *player, int id);
void draw_menu(sfRenderWindow *window, menu_t *menu);
void destroy_menu(menu_t *menu);
int handle_menu_events(sfRenderWindow *window, menu_t *menu, wd_t *wd);
void display_map(map_t *map);
void free_data(data_t *data);
data_t *create_data(char *filepath, sfRenderWindow *window);
void give_data(data_t *data, char **object, sfRenderWindow *window);
void add_map(char **object, data_t *data);
void handle_shoot(player_t *player, wd_t *window);
void handle_change_weapon(player_t *player, sfEvent event);
obj_t *create_head_obj(void);
void display_head(obj_t *head, sfRenderWindow *window, int pv,
    sfVector2u win_size);
void display_ammo(sfRenderWindow *window, int nb_ammo,
    sfVector2u win_size);
weapon_t *create_knife(sfRenderWindow *window);
void change_player_stat(player_t *player, map_t *map);
void free_map(map_t *map);
int check_bounds(map_t *map);
void free_window(wd_t *window);
void launch_settings_menu(sfRenderWindow **window_ptr, wd_t *wd);
void change_resolution(sfRenderWindow **window_ptr);
int handle_settings_clicks(sfRenderWindow **window_ptr, wd_t *wd,
    sfText *audio, sfText *video);
void set_video_mode(sfVideoMode *mode, int state);
void toggle_music(wd_t *window);
settings_t *create_struct_settings(sfRenderWindow **window_ptr);
void add_weapon(char **object, data_t *data, sfRenderWindow *window);
void free_weapon(weapon_t *weapon);
void play_music(wd_t *window, data_t *data);
void destroy_settings_texts(settings_t *set);
void toggle_sound(wd_t *window);
#endif /* !STRUCT_H_ */

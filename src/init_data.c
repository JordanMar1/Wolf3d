/*
** EPITECH PROJECT, 2025
** wolf3dwactest
** File description:
** init_data
*/

#include "../include/wolf.h"
#include "../include/struct.h"

// allocates a string
static char *get_buffer(int size, int fd)
{
    int rd;
    char *buf;

    buf = malloc(size + 1);
    rd = read(fd, buf, size);
    if (rd <= 0) {
        free(buf);
        close(fd);
        return NULL;
    }
    buf[size] = '\0';
    return buf;
}

// initializes the data
static data_t *init_data(int is_save, char *savepath)
{
    data_t *data = malloc(sizeof(data_t));

    if (!data)
        return NULL;
    data->player = malloc(sizeof(player_t));
    data->save = malloc(sizeof(save_t));
    data->map = NULL;
    data->enemy = NULL;
    if (!data->player || !data->save) {
        free_data(data);
        return NULL;
    }
    give_player_stat(data->player);
    if (is_save == 0 || !savepath || strcmp(savepath, "") == 0) {
        free(data->save);
        data->save = NULL;
    }
    return data;
}

//fills the data
static int fill_data(data_t *data, char **arr, sfRenderWindow *window)
{
    char **object;

    for (int i = 0; arr[i] != NULL; i++) {
        object = my_str_to_word_array(arr[i], ":");
        if (!object)
            return -1;
        give_data(data, object, window);
        free_array(object);
    }
    return 0;
}

// loads the data from an array
static char **load_map_array(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size;
    char *buf;
    char **arr;

    if (fd < 0)
        return NULL;
    size = size_file(filepath);
    buf = get_buffer(size, fd);
    close(fd);
    if (!buf)
        return NULL;
    arr = my_str_to_word_array(buf, "#");
    free(buf);
    return arr;
}

// fills the data
static data_t *init_and_fill_data(char **arr, sfRenderWindow *window)
{
    data_t *data = init_data(1, "");

    if (!data)
        return NULL;
    if (fill_data(data, arr, window) < 0) {
        free_data(data);
        return NULL;
    }
    return data;
}

// creates the structure data
data_t *create_data(char *filepath, sfRenderWindow *window)
{
    char **arr = load_map_array(filepath);
    data_t *data;

    if (!arr) {
        printf("e");
        return NULL;
    }
    data = init_and_fill_data(arr, window);
    free_array(arr);
    return data;
}

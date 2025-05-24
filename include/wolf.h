/*
** EPITECH PROJECT, 2025
** G-ING-210-LIL-2-1-wolf3d-fabien.skotarek
** File description:
** wolf
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef WOLF_H_
    #define WOLF_H_

char *my_rev_str(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *src, char *dest);
int my_strlen(char *str);
void my_putstr(char *str);
int my_strcmp(char *s1, char *s2);
char **my_str_to_word_array(char *str, char *seps);
int my_len_arr(char **arr);
void free_array(char **arr);
int size_file(const char *filepath);
void my_putchar(char c);
void my_putnbr(int nb);
char *get_name(char *elem, char **content);
int look_menu(void);
int look_music(void);
int look_fonts(void);
#endif /* !WOLF_H_ */

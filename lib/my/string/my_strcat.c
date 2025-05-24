/*
** EPITECH PROJECT, 2025
** B-PSU-200-LIL-2-1-minishell1-jordan.marescaux
** File description:
** my_strcat
*/

char *my_strcat(char *src, char *dest)
{
    int i = 0;
    int j = 0;

    for (; src[i] != '\0'; i++);
    for (; dest[j] != '\0'; j++) {
        src[i + j] = dest[j];
    }
    src[i + j] = '\0';
    return src;
}

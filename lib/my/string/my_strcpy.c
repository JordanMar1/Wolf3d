/*
** EPITECH PROJECT, 2025
** string
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int cara = 0;

    for (cara; src[cara] != '\0'; cara++) {
        dest[cara] = src[cara];
    }
    return dest;
}

/*
** EPITECH PROJECT, 2025
** setting_up
** File description:
** size_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int size_file(const char *filepath)
{
    struct stat sb;

    if (stat(filepath, &sb) < 0) {
        return -1;
    }
    return (long int)sb.st_size;
}

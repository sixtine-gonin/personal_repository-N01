/*
** EPITECH PROJECT, 2024
** hunter_test
** File description:
** my_revstr.c
*/

#include "../include/game.h"

void my_revstr(char *str, int len)
{
    int start = 0;
    int end = len - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void int_to_str(int num, char *str)
{
    int i = 0;
    int is_negative = 0;

    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    while (num) {
        str[i] = (num % 10) + '0';
        i++;
        num /= 10;
    }
    if (is_negative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str, i);
}

void my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

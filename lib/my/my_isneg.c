/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** check is n is negative
*/

#include <unistd.h>

int my_isneg(int number)
{
    char p = 'P';
    char n = 'N';

    if (number < 0){
        write(1, &n, 1);
    } else {
        write(1, &p, 1);
    }
    return 0;
}

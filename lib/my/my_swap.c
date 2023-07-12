/*
** EPITECH PROJECT, 2022
** my swap
** File description:
** Swap two number
*/

void my_swap(int *a, int *b)
{
    int tmp_swap = *a;
    *a = *b;
    *b = tmp_swap;
}

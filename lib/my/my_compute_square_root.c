/*
** EPITECH PROJECT, 2022
** recursive day
** File description:
** compute square root
*/

static int find_square_root(int nb, int num_try)
{
    if (num_try > (nb / 2))
        return 0;
    if ((nb % num_try) == 0 && (nb / num_try) == num_try)
        return num_try;
    return find_square_root(nb, num_try + 1);
}

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return 0;
    if (nb == 1)
        return 1;
    return find_square_root(nb, 1);
}

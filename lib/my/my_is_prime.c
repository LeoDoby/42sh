/*
** EPITECH PROJECT, 2022
** recursive day
** File description:
** is prime ?
*/

static int calcul_is_prime(int nb, int try_num, int num_of_div, int max_value)
{
    if (!(nb % try_num))
        num_of_div += 1;
    if (try_num > max_value)
        return 1;
    if ((num_of_div) > 2)
        return 0;
    return calcul_is_prime(nb, try_num + 1, num_of_div, max_value);
}

int my_is_prime(int nb)
{
    if (nb == 2)
        return 1;
    if (nb <= 1 || (nb % 2) == 0)
        return 0;
    return calcul_is_prime(nb, 1, 0, 46340);
}

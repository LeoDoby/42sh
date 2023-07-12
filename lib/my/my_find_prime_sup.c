/*
** EPITECH PROJECT, 2022
** recursive day
** File description:
** find prime sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if ( nb < 0)
        nb = 0;
    if (my_is_prime(nb))
        return nb;
    return my_find_prime_sup(nb + 1);
}

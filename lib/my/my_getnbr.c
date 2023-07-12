/*
** EPITECH PROJECT, 2022
** my get nbr
** File description:
** get a number from str
*/

int my_strlen(char const *str);

static int build_int(char a, long *sum, int *sign)
{
    if (a >= '0' && a <= '9'){
        *sum *= 10;
        *sum += a - 48;
        if ((*sum * *sign) != (int)(*sum * *sign)){
            *sum = 0;
            return 0;
        }
        return 1;
    }
    if (a == '-'){
        *sign *= -1;
        return 1;
    }
    if (a == '+'){
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int size = my_strlen(str);
    long return_value = 0;
    int sign = 1;

    for (int i = 0; i < size; i++){
        int a = build_int(str[i], &return_value, &sign);
        if (!a){
            return return_value * sign;
        }
    }

    return return_value * sign;
}

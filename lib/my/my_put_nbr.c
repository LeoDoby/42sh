/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** write a number
*/

void my_putchar(char c);

static int isneg(long number)
{
    if (number < 0){
        return 1;
    } else {
        return 0;
    }
}

static int my_expo(int a, int b)
{
    int sum = 1;
    for (int i = 0;i < b; i++){
        sum *= a;
    }
    return sum;
}

static int print_nbr(long n)
{
    int numOfNumber = 0;

    while ((n / (my_expo(10,numOfNumber))) > 9){
        numOfNumber += 1;
    }
    for (int i = numOfNumber; i >= 0; i--){
        my_putchar((n / my_expo(10,i)) + 48);
        n -= ((n / my_expo(10, i))) * my_expo(10, i);
    }
    return 0;
}

int my_put_nbr(int n)
{
    long tmp = (long)n;

    if (isneg(tmp)){
        my_putchar('-');
        tmp *= -1;
    }
    print_nbr(tmp);
    return 0;
}

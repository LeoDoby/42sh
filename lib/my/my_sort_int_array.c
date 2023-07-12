/*
** EPITECH PROJECT, 2022
** my array sort
** File description:
** sort a array
*/

void my_swap(int *a, int *b);

static void my_sort(int *array, int size, int i)
{
    for (int j = i + 1; j < size; j++){
        if (array[j] < array[i]){
            my_swap(&array[i], &array[j]);
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++){
        my_sort(array, size, i);
    }
}

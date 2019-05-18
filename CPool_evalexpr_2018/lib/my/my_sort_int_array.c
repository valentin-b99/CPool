/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int int_temp;

    while (i < size - 1) {
        if (array[i + 1] < array[i]) {
            int_temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = int_temp;
            i = 0;
        }
        else {
            i = i + 1;
        }
    }
}

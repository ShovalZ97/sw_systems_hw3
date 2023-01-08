#include <stdio.h>
//arr size
#define SIZEARR 50


// shift_element - jump one step to the right
// arr - the address of the starting pointer that we want to move
// i - num of elements that we left to move
// (arr+num) == arr[num]



void shift_element(int* arr, int i)
{
    for (int num = i; num > 0; --num)
        *(arr + num) = *(arr + num - 1);
}

//insertion_sort - insertion sort ( sort size = len)
// temp - 
void insertion_sort(int* arr, int len)
{
    for (int j = 1; j < len; ++j)
    {
        int temp = *(arr + j);
        int i = j - 1;
        while (i >= 0 && *(arr + i) > temp)
            --i;

        shift_element((arr + i), (j - i));
        *(arr + i + 1) = temp;
    }

}


int main()
{
    int arr[SIZEARR] = { 0 };

    for (int i = 0; i < SIZEARR; ++i)
        scanf("%d", &(*(arr + i)));

    insertion_sort(arr, SIZEARR);

    for (int i = 0; i < SIZEARR; ++i)
        printf("%d%c", *(arr + i), ((i == (SIZEARR - 1)) ? '\n' : ','));

    return 0;
}
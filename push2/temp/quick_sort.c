#include <stdio.h>

void    quicksort(int *arr, int L, int R)
{
    int pivot;
    int temp;
    int left;
    int right;

    left = L;
    right = R;
    pivot = arr[(L + R) / 2];
    while (L <= R)
    {
        while (arr[L] < pivot)
            L++;
        while (arr[R] > pivot)
            R--;
        if (L <= R)
        {
            temp = arr[R];
            arr[R] = arr[L];
            arr[L] = temp;
            L++;
            R--;
        }
    }
    if (R > left)
        quicksort(arr, left, R);
    if (L < right)
        quicksort(arr, L, right);
}

int main(void)
{
    int arr[10] = {2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
    for (int i = 0; i <= 9; i++)
        printf("%d\n", arr[i]);
    printf("change\n");
    quicksort(arr, 0, 9);
    for (int i = 0; i <= 9; i++)
        printf("%d\n", arr[i]);
    return (0);
}
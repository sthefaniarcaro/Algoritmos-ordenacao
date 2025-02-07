#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void gnomeSort(int arr[], int n)
{
    int index = 0;

    while (index < n)
    {
        if (index == 0 || arr[index] >= arr[index - 1])
        {
            index++;
        }
        else
        {
            int temp = arr[index];
            arr[index] = arr[index - 1];
            arr[index - 1] = temp;
            index--;
        }
    }
}

int main()
{
    return 0;
}

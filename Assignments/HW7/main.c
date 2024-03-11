#include <stdio.h>
#include <stdlib.h>

void print(int[], int);
void populate(int[], int);
void swap(int *, int *);
void swap_elements(int *, int);

int main()
{
    int array[100];
    int sizeOfArray;

    printf("How many numbers will be loaded into the array: ");
    scanf("%d", &sizeOfArray);

    populate(array, sizeOfArray);
    swap_elements(array, sizeOfArray);
    print(array, sizeOfArray);

    printf("\n\n\t\tThis is the Better Bubble Sort Algorithm!\n\n\n");

    return 0;
}

void print(int *a, int size)
{
    int index = 0;
    while(index < size) {
        printf("array[%d] = %d\n", index, a[index++]);
    }
}

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swap_elements(int *a, int size)
{
    int i, j;

    for(i = (size - 1); i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                swap(a+j, a+j+1);
            }
        }
    }
}

void populate(int *a, int size)
{
    int i;
    for(i = 0; i < size; i++) {
        printf("Enter the number for a[%d]: ", (i+1));
        scanf("%d", &a[i]);
    }
    printf("\n");
}

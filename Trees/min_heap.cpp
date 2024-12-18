#include <stdio.h>

int array[25], n = 1;

void insert() {
    int number;
    printf("\nEnter a number: ");
    scanf("%d", &number);

    int position = n;
    array[position] = number; // Add the new element to the end of the array
    while (position > 1 && array[position] < array[position / 2]) {
        // Swap with the parent
        int temp = array[position];
        array[position] = array[position / 2];
        array[position / 2] = temp;
        position = position / 2;
    }
    n++; // Increment the size of the array
}

void display() {
    for (int i = 1; i < n; i++)
        printf("\n%d", array[i]);
}

int main() {
    insert();
    insert();
    insert();
    insert();
    display();

    return 0;
}


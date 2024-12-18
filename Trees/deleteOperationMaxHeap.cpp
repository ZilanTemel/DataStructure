#include <stdio.h>

int heap[25], size = 0; // Array to store heap elements and heap size

// Function to insert a new element into the max heap
void insert() {
    int number, position;
    printf("\nEnter a number: ");
    scanf("%d", &number);
    size++; // Increment the size of the heap
    position = size;
    heap[position] = number;

    // Bubble up to maintain max heap property
    while (position > 1 && heap[position] > heap[position / 2]) {
        int temp = heap[position];
        heap[position] = heap[position / 2];
        heap[position / 2] = temp;
        position = position / 2; // Move up to the parent node
    }
}

// Function to display the elements of the max heap
void display() {
    printf("\nHeap Elements: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Function to delete the root element (max element) from the heap
void deleteRoot() {
    if (size == 0) {
        printf("\nHeap is empty. Nothing to delete.\n");
        return;
    }

    printf("\nDeleted element: %d\n", heap[1]); // Root element
    heap[1] = heap[size]; // Replace root with the last element
    size--; // Reduce heap size
    int position = 1;

    // Bubble down to restore max heap property
    while (position * 2 <= size) {
        int leftChild = 2 * position;
        int rightChild = 2 * position + 1;
        int largest = position;

        // Check left child
        if (leftChild <= size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        // Check right child
        if (rightChild <= size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // Swap if necessary
        if (largest != position) {
            int temp = heap[position];
            heap[position] = heap[largest];
            heap[largest] = temp;
            position = largest; // Move down to the child
        } else {
            break; // Heap property restored
        }
    }
}

int main() {
    insert();
    insert();
    insert();
    insert();

    display(); // Display the heap after insertions

    deleteRoot(); // Delete the root element
}

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the stack structure
typedef struct {
    Node* top; // Pointer to the top node
    int cnt;   // Counter to track the number of elements
} stack;

// Initialization function
void initialize(stack* stk) {
    stk->top = NULL;
    stk->cnt = 0; // Initialize the count to 0
}

// Push operation
void push(stack* stk, int c) {
    if (stk->cnt == STACK_SIZE) {
        printf("Stack is full\n"); // Print an error if the stack is full
    } else {
        Node* temp = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        temp->data = c;           // Set the data of the new node
        temp->next = stk->top;    // Link the new node to the top
        stk->top = temp;          // Update the top of the stack
        stk->cnt++;               // Increment the element count
    }
}

// Pop operation
int pop(stack* stk) {
    if (stk->cnt == 0) {
        printf("Stack is empty\n");
        return -100; // Error value for empty stack
    } else {
        int x = stk->top->data;   // Retrieve data from the top node
        Node* temp = stk->top;    // Save the top node to free later
        stk->top = stk->top->next; // Move the top pointer to the next node
        free(temp);               // Free the old top node
        stk->cnt--;               // Decrease the element count
        return x;                 // Return the popped value
    }
}


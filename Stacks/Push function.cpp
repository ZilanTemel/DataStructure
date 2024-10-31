void push(Stack *stk, int value) {
    // Check if the stack is full
    if (stk->top == STACK_SIZE - 1) { 
        // Is the stack full?
        printf("Stack is full\n"); // Print a message indicating the stack is full
    } else {
        // If the stack is not full, proceed to push the new element
        stk->top++; // Move the top index up by one
        // Shift the top up by one
        stk->data[stk->top] = value; // Add the new element at the top of the stack
        // Insert the new element at the top of the stack
    }
}


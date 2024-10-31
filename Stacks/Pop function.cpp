

int pop(Stack *stk) {
    // Check if the stack is empty
    if (stk->top == -1) { 
        printf("Stack is empty\n"); // Print a message indicating the stack is empty
        return -100; // (Error condition)
    } else {
        // If the stack is not empty, proceed to pop the top element
        int x = stk->data[stk->top]; // Retrieve the top element
        stk->top--; // Decrease the top index
        
        return x; // Return the popped value
       
    }
}




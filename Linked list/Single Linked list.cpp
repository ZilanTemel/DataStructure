#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

// Function to add an element at the head
struct node* addhead(struct node* head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

// Function to add an element at the end
struct node* addlast(struct node* head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) { // If the list is empty, the new node becomes the head
        return new_node;
    }

    struct node* temp = head;
    while (temp->next != NULL) { // Traverse to the end of the list
        temp = temp->next;
    }
    temp->next = new_node; // Add the new node to the end
    return head;
}

// Function to print the list
void print(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node with a given value
struct node* delete(struct node* head, int data) {
    struct node* temp = head;
    struct node* prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Find the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to completely destroy the list
struct node* destroy(struct node* head) {
    struct node* temp = head;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL; // Return NULL since the list is now empty
}

// Function to count how many elements are in the list
int count(struct node* head) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to print information about the list (list all elements)
void listinfo(struct node* head) {
    struct node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements in the list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    struct node *head = NULL;

    while (1) {
        printf("1-Add element to the head of the list\n");
        printf("2-Add element to the end of the list\n");
        printf("3-View the list\n");
        printf("4-Delete a node with a given value\n");
        printf("5-Destroy the list\n");
        printf("6-Count the number of elements in the list\n");
        printf("7-Print all element information in the list\n");
        printf("8-Exit the program\n");
        printf("Your choice....?");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you want to add: ");
                scanf("%d", &data);
                head = addhead(head, data);
                break;
            case 2:
                printf("Enter the value you want to add: ");
                scanf("%d", &data);
                head = addlast(head, data);
                break;
            case 3:
                print(head);
                break;
            case 4:
                printf("Enter the value you want to delete: ");
                scanf("%d", &data);
                head = delete(head, data);
                break;
            case 5:
                head = destroy(head);
                break;
            case 6:
                printf("There are %d elements in the list\n", count(head));
                break;
            case 7:
                listinfo(head);
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

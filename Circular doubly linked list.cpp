#include <stdio.h>
#include <stdlib.h>

// Definition of a circular doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Insert a node at the beginning of the list
void insertAtFront(struct node** head, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;

    if (*head == NULL) {
        *head = temp;
        temp->next = temp; // Point to itself
        temp->prev = temp; // Point to itself
    } else {
        temp->next = *head;
        temp->prev = (*head)->prev;
        (*head)->prev->next = temp; // Link last node to new head
        (*head)->prev = temp;        // Update head's previous pointer
        *head = temp;                // Move head to the new node
    }
}

// Insert a node at the end of the list
void insertAtLast(struct node** head, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;

    if (*head == NULL) {
        *head = temp;
        temp->next = temp; // Point to itself
        temp->prev = temp; // Point to itself
    } else {
        temp->next = *head; // New node points to head
        temp->prev = (*head)->prev; // New node's previous points to last
        (*head)->prev->next = temp; // Last node links to new node
        (*head)->prev = temp; // Head's previous points to new node
    }
}

// Concatenate two circular doubly linked lists
void concatenate(struct node** list_1, struct node* list_2) {
    if (*list_1 == NULL) {
        *list_1 = list_2;
    } else if (list_2 != NULL) {
        struct node* last1 = (*list_1)->prev;
        struct node* last2 = list_2->prev;

        last1->next = list_2;          // Connect last of list_1 to head of list_2
        list_2->prev = last1;          // Connect head of list_2 back to last of list_1
        last2->next = *list_1;         // Connect last of list_2 to head of list_1
        (*list_1)->prev = last2;       // Connect head of list_1 back to last of list_2
    }
}

// Locate a node with a given data value
struct node* locate(int value, struct node* head) {
    if (head == NULL) return NULL; // List is empty

    struct node* temp = head;
    do {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;  // Value not found
}

// Delete a node with a given key
struct node* deletenode(struct node* head, int key) {
    if (head == NULL) {
        printf("The list is empty\n");
        return NULL;
    }

    struct node* temp = head;
    struct node* toDelete = NULL;

    // Check if the first node should be deleted
    if (head->data == key) {
        toDelete = head;
        if (head->next == head) {
            // Only one node in the list
            head = NULL;
        } else {
            head->prev->next = head->next; // Link last to the next
            head->next->prev = head->prev; // Link next to the last
            head = head->next;              // Move head to next
        }
        free(toDelete);
        return head;
    }

    // Check for other nodes
    do {
        temp = temp->next;
        if (temp->data == key) {
            toDelete = temp;
            temp->prev->next = temp->next; // Link previous to next
            temp->next->prev = temp->prev; // Link next to previous
            free(toDelete);
            return head; // Return the head as it does not change
        }
    } while (temp != head);

    printf("The data you want to delete is not found.\n");
    return head; // Return original head if key is not found
}

// Print the list
void printList(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data); // Show head to indicate circularity
}

// Main function
int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    int choice, value, list_choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add element to the front of the list\n");
        printf("2. Add element to the end of the list\n");
        printf("3. Concatenate the lists\n");
        printf("4. Find a specific node\n");
        printf("5. Delete a specific node\n");
        printf("6. Print the list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Which list do you want to add to? (1 or 2): ");
                scanf("%d", &list_choice);
                printf("Enter the value to add: ");
                scanf("%d", &value);
                if (list_choice == 1)
                    insertAtFront(&list1, value);
                else
                    insertAtFront(&list2, value);
                break;

            case 2:
                printf("Which list do you want to add to? (1 or 2): ");
                scanf("%d", &list_choice);
                printf("Enter the value to add: ");
                scanf("%d", &value);
                if (list_choice == 1)
                    insertAtLast(&list1, value);
                else
                    insertAtLast(&list2, value);
                break;

            case 3:
                printf("Concatenating the lists...\n");
                concatenate(&list1, list2);
                break;

            case 4:
                printf("Enter the value to find: ");
                scanf("%d", &value);
                struct node* foundNode = locate(value, list1);
                if (foundNode != NULL)
                    printf("Node found: %d\n", foundNode->data);
                else
                    printf("Node not found.\n");
                break;

            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                list1 = deletenode(list1, value);
                break;

            case 6:
                printf("List 1: ");
                printList(list1);
                printf("List 2: ");
                printList(list2);
                break;

            case 7:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}


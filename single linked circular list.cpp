#include <stdio.h>
#include <stdlib.h>

// Definition of a singly linked list node
struct node {
    int data;
    struct node* next;
};

// Insert a node at the beginning of the list
void insertAtFront(struct node** head, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = *head;
    *head = temp;
}

// Insert a node at the end of the list
void insertAtLast(struct node** head, int key) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

// Concatenate two lists
void concatenate(struct node** list_1, struct node* list_2) {
    if (*list_1 == NULL) {
        *list_1 = list_2;
    } else {
        struct node* last = *list_1;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = list_2;
    }
}

// Locate a node with a given data value
struct node* locate(int value, struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Value not found
}

// Delete a node with a given key
struct node* deletenode(struct node* head, int key) {
    if (head == NULL) {
        printf("The list is empty\n");
        return NULL;
    }

    struct node* temp = head;

    // Check if the first node should be deleted
    if (head->data == key) {
        head = head->next;
        free(temp);
        return head;
    }

    // Check for other nodes
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("The data you want to delete is not found.\n");
    } else {
        struct node* temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }

    return head;
}

// Print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

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


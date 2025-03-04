#include <stdlib.h>
#include <stdio.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Global head pointer
struct Node *head = NULL;

// Function to insert a node at the end
void insert(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    ptr->data = value;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
    }
    printf("Inserted: %d\n", value);
}

// Function to traverse and print the list
void traverse() {
    struct Node *current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the list
void search(int value) {
    struct Node *current = head;
    int position = 0;

    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        if (current->data == value) {
            printf("Match Found at position: %d\n", position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("No Match Found\n");
}

// Function to delete a node with a specific value
void deleteNode(int value) {
    struct Node *current = head, *prev = NULL;

    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        printf("Deleted: %d\n", value);
        return;
    }

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found\n", value);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("Deleted: %d\n", value);
}

// Main function for user interaction
int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Traverse\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again\n");
        }
    }
}

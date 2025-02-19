#include <stdio.h>

// Function to insert an element at a given position
void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position! Please enter position between 0 and %d\n", *size);
        return;
    }

    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert new element
    arr[position] = element;
    (*size)++; // Increase size of array

    printf("Element inserted successfully!\n");
}

// Function to delete an element from a given position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position! Please enter position between 0 and %d\n", *size - 1);
        return;
    }

    // Shift elements to the left
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Decrease size of array

    printf("Element deleted successfully!\n");
}

// Function to display the array
void displayArray(int arr[], int size) {
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], size, choice, element, position;

    // Getting the array size and elements from the user
    printf("Enter number of elements in array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insertElement(arr, &size, element, position);
                break;
            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function declarations
void printList();
void addNode(int value, int option, ...);
void deleteNode(int option, ...);

// Global variables
struct Node* head = NULL;

void addNode(int value, int option, ...) {
    va_list args;
    va_start(args, option);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (option == 1) { // Add to the beginning
        newNode->next = head;
        head = newNode;
    } else if (option == 2) { // Add to the end
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    } else if (option == 3) { // Add in between
        int targetValue = va_arg(args, int);

        // If the target is the first node
        if (head != NULL && head->data == targetValue) {
            newNode->next = head;
            head = newNode;
        } else {
            struct Node* temp = head;

            // Traverse to find the target value
            while (temp != NULL && temp->next != NULL && temp->next->data != targetValue) {
                temp = temp->next;
            }

            if (temp != NULL && temp->next != NULL) { // Target value found
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                printf("Target value not found.\n");
                free(newNode);
            }
        }
    }
    va_end(args);
    printList();
}

void deleteNode(int option, ...) {
    va_list args;
    va_start(args, option);

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (option == 4) { // Delete from the beginning
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else if (option == 5) { // Delete from the end
        if (head->next == NULL) { // Only one element in the list
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    } else if (option == 6) { // Delete a specific value
        int targetValue = va_arg(args, int);

        if (head->data == targetValue) { // Target is the first element
            struct Node* temp = head;
            head = head->next;
            free(temp);
        } else {
            struct Node* temp = head;
            while (temp->next != NULL && temp->next->data != targetValue) {
                temp = temp->next;
            }
            if (temp->next != NULL) { // Target value found
                struct Node* toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            } else {
                printf("Value not found in the list.\n");
            }
        }
    }
    va_end(args);
    printList();
}

void printList() {
    system("cls"); // Clear the console
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    while (1) {
        int choice, value;
        printf("\n1 - Add to the beginning");
        printf("\n2 - Add to the end");
        printf("\n3 - Add in between");
        if (head != NULL) {
            printf("\n4 - Delete from the beginning");
            printf("\n5 - Delete from the end");
            printf("\n6 - Delete a specific value");
        }
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to add at the beginning: ");
                scanf("%d", &value);
                addNode(value, choice);
                break;

            case 2:
                printf("Enter the value to add at the end: ");
                scanf("%d", &value);
                addNode(value, choice);
                break;

            case 3:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                int target;
                printf("Enter the value before which to add: ");
                scanf("%d", &target);
                addNode(value, choice, target);
                break;

            case 4:
                deleteNode(choice);
                break;

            case 5:
                deleteNode(choice);
                break;

            case 6:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(choice, value);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

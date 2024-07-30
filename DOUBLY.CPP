#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a new node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the new node
    newNode->data = newData;

    // Set the next pointer of the new node to the current head
    newNode->next = *head;

    // Set the previous pointer of the new node to NULL
    newNode->prev = NULL;

    // If the doubly linked list is not empty, update the previous pointer of the current head
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    // Update the head to point to the new node
    *head = newNode;
}

// Function to display the doubly linked list in forward direction
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("The doubly linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}
// Function to display the doubly linked list in reverse direction
void displayReverse(struct Node* head) {
    if (head == NULL) {
        printf("The doubly linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    // Traverse to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Doubly Linked List (Reverse): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }

    printf("\n");
}

int main() {
    // Initialize an empty doubly linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    // Display the doubly linked list in forward and reverse directions
    displayForward(head);
    displayReverse(head);
    getch();
    return 0;
}

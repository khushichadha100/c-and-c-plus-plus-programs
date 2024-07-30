#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign data to the new node
    newNode->data = newData;

    // If the circular linked list is empty, make the new node as the only node
    if (*head == NULL) {
        newNode->next = newNode;
    }
    else {
        // Find the last node in the circular linked list
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        // Set the next pointer of the new node to the current head
        newNode->next = *head;

        // Update the next pointer of the last node to the new node
        last->next = newNode;
    }

    // Update the head to point to the new node
    *head = newNode;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    // Initialize an empty circular linked list
    struct Node* head = NULL;
    //clrscr();

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 9);

    // Display the circular linked list
    displayList(head);
    getch();
    return 0;
}

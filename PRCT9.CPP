#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void splitLinkedList(struct Node* head, struct Node** firstList,
struct Node** secondList) {
    struct Node* curr = head;
    int count = 0;

    while (curr != NULL) {
        if (count % 2 == 0) {
            insertNode(firstList, curr->data);
        } else {
            insertNode(secondList, curr->data);
        }
        count++;
        curr = curr->next;
    }
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* current = temp;
        temp = temp->next;
        free(current);
    }
}

int main() {
    struct Node* list = NULL;
    struct Node* firstList = NULL;
    struct Node* secondList = NULL;
    clrscr();
    // Insert elements into the main list
    insertNode(&list, 1);
    insertNode(&list, 2);
    insertNode(&list, 3);
    insertNode(&list, 4);
    insertNode(&list, 5);
    insertNode(&list, 6);
    insertNode(&list, 7);
    insertNode(&list, 8);
    insertNode(&list, 9);
    insertNode(&list, 10);

    // Split the main list into two lists
    splitLinkedList(list, &firstList, &secondList);

    // Print the first list
    printf("First List: ");
    printList(firstList);

    // Print the second list
    printf("Second List: ");
    printList(secondList);

    // Free the memory occupied by the lists
    freeList(firstList);
    freeList(secondList);
    getch();
    return 0;
}

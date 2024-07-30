#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
 

// Structure for dynamic dequeue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

// Function to check if the dynamic dequeue is empty
int isDynamicEmpty() {
    return (front == NULL);
}

// Function to insert an element at the front of the dynamic dequeue
void enqueueFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (isDynamicEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
    
    printf("%d enqueued from the front.\n", value);
}

// Function to insert an element at the rear of the dynamic dequeue
void enqueueRear(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (isDynamicEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    printf("%d enqueued from the rear.\n", value);
}

// Function to remove an element from the front of the dynamic dequeue
void dequeueFront() {
    if (isDynamicEmpty()) {
        printf("Dynamic Dequeue is empty. Cannot dequeue from the front.\n");
    } else {
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        free(temp);
        
        printf("%d dequeued from the front.\n", value);
    }
}

// Function to remove an element from the rear of the dynamic dequeue
void dequeueRear() {
    if (isDynamicEmpty()) {
        printf("Dynamic Dequeue is empty. Cannot dequeue from the rear.\n");
    } else {
        Node* current = front;
        Node* previous = NULL;
        
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        
        int value = current->data;
        
        if (previous == NULL) {
            front = rear = NULL;
        } else {
            previous->next = NULL;
            rear = previous;
        }
        
        free(current);
        
        printf("%d dequeued from the rear.\n", value);
    }
}

// Function to display the elements of the dynamic dequeue
void displayDynamicDequeue() {
    if (isDynamicEmpty()) {
        printf("Dynamic Dequeue is empty.\n");
    } else {
        Node* current = front;
        
        printf("Elements of the Dynamic Dequeue: ");
        
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        
        printf("\n");
    }
}

// Static Dequeue
#define MAX_SIZE 5
int staticDequeue[MAX_SIZE];
int staticFront = -1, staticRear = -1;

// Function to check if the static dequeue is empty
int isStaticEmpty() {
    return (staticFront == -1);
}

// Function to check if the static dequeue is full
int isStaticFull() {
    return ((staticFront == 0 && staticRear == MAX_SIZE - 1) || (staticFront == staticRear + 1));
}

// Function to insert an element at the front of the static dequeue
void enqueueStaticFront(int value) {
    if (isStaticFull()) {
        printf("Static Dequeue is full. Cannot enqueue front.\n");
    } else if (isStaticEmpty()) {
        staticFront = staticRear = 0;
        staticDequeue[staticFront] = value;
        printf("%d enqueued from the front.\n", value);
    } else if (staticFront == 0) {
        staticFront = MAX_SIZE - 1;
        staticDequeue[staticFront] = value;
        printf("%d enqueued from the front.\n", value);
    } else {
        staticFront--;
        staticDequeue[staticFront] = value;
        printf("%d enqueued from the front.\n", value);
    }
}

// Function to insert an element at the rear of the static dequeue
void enqueueStaticRear(int value) {
    if (isStaticFull()) {
        printf("Static Dequeue is full. Cannot enqueue rear.\n");
    } else if (isStaticEmpty()) {
        staticFront = staticRear = 0;
        staticDequeue[staticRear] = value;
        printf("%d enqueued from the rear.\n", value);
    } else if (staticRear == MAX_SIZE - 1) {
        staticRear = 0;
        staticDequeue[staticRear] = value;
        printf("%d enqueued from the rear.\n", value);
    } else {
        staticRear++;
        staticDequeue[staticRear] = value;
        printf("%d enqueued from the rear.\n", value);
    }
}

// Function to remove an element from the front of the static dequeue
void dequeueStaticFront() {
    if (isStaticEmpty()) {
        printf("Static Dequeue is empty. Cannot dequeue from the front.\n");
    } else if (staticFront == staticRear) {
        int value = staticDequeue[staticFront];
        staticFront = staticRear = -1;
        printf("%d dequeued from the front.\n", value);
    } else if (staticFront == MAX_SIZE - 1) {
        int value = staticDequeue[staticFront];
        staticFront = 0;
        printf("%d dequeued from the front.\n", value);
    } else {
        int value = staticDequeue[staticFront];
        staticFront++;
        printf("%d dequeued from the front.\n", value);
    }
}

// Function to remove an element from the rear of the static dequeue
void dequeueStaticRear() {
    if (isStaticEmpty()) {
        printf("Static Dequeue is empty. Cannot dequeue from the rear.\n");
    } else if (staticFront == staticRear) {
        int value = staticDequeue[staticRear];
        staticFront = staticRear = -1;
        printf("%d dequeued from the rear.\n", value);
    } else if (staticRear == 0) {
        int value = staticDequeue[staticRear];
        staticRear = MAX_SIZE - 1;
        printf("%d dequeued from the rear.\n", value);
    } else {
        int value = staticDequeue[staticRear];
        staticRear--;
        printf("%d dequeued from the rear.\n", value);
    }
}

// Function to display the elements of the static dequeue
void displayStaticDequeue() {
    if (isStaticEmpty()) {
        printf("Static Dequeue is empty.\n");
    } else {
        int i;
        printf("Elements of the Static Dequeue: ");
        if (staticFront <= staticRear) {
            for (i = staticFront; i <= staticRear; i++) {
                printf("%d ", staticDequeue[i]);
            }
        } else {
            for (i = staticFront; i < MAX_SIZE; i++) {
                printf("%d ", staticDequeue[i]);
            }
            for (i = 0; i <= staticRear; i++) {
                printf("%d ", staticDequeue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
    printf("======= Dequeue Menu =======\n");
    printf("1. Enqueue Front (Dynamic Dequeue)\n");
    printf("2. Enqueue Rear (Dynamic Dequeue)\n");
    printf("3. Dequeue Front (Dynamic Dequeue)\n");
    printf("4. Dequeue Rear (Dynamic Dequeue)\n");
    printf("5. Display Dynamic Dequeue\n");
    printf("6. Enqueue Front (Static Dequeue)\n");
    printf("7. Enqueue Rear (Static Dequeue)\n");
    printf("8. Dequeue Front (Static Dequeue)\n");
    printf("9. Dequeue Rear (Static Dequeue)\n");
    printf("10. Display Static Dequeue\n");
    printf("11. Exit\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue from the front (Dynamic Dequeue): ");
                int dynamicFrontValue;
                scanf("%d", &dynamicFrontValue);
                enqueueFront(dynamicFrontValue);
                break;
                
            case 2:
                printf("Enter the element to enqueue from the rear (Dynamic Dequeue): ");
                int dynamicRearValue;
                scanf("%d", &dynamicRearValue);
                enqueueRear(dynamicRearValue);
                break;
                
            case 3:
                dequeueFront();
                break;
                
            case 4:
                dequeueRear();
                break;
                
            case 5:
                displayDynamicDequeue();
                break;
                
            case 6:
                printf("Enter the element to enqueue from the front (Static Dequeue): ");
                int staticFrontValue;
                scanf("%d", &staticFrontValue);
                enqueueStaticFront(staticFrontValue);
                break;
                
            case 7:
                printf("Enter the element to enqueue from the rear (Static Dequeue): ");
                int staticRearValue;
                scanf("%d", &staticRearValue);
                enqueueStaticRear(staticRearValue);
                break;
                
            case 8:
                dequeueStaticFront();
                break;
                
            case 9:
                dequeueStaticRear();
                break;
                
            case 10:
                displayStaticDequeue();
                break;
                
            case 11:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    getch();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Structure for dynamic circular queue node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Static circular queue
#define MAX_SIZE 5
int staticQueue[MAX_SIZE];
int staticFront = -1, staticRear = -1;

// Dynamic circular queue
struct QueueNode* dynamicFront = NULL;
struct QueueNode* dynamicRear = NULL;

// Function prototypes
void staticEnqueue(int value);
void staticDequeue();
void dynamicEnqueue(int value);
void dynamicDequeue();
void displayStaticQueue();
void displayDynamicQueue();

int main() {
    int choice, value;
    
    while (1) {
        printf("\n------ Circular Queue Menu ------\n");
        printf("1. Enqueue (Static Circular Queue)\n");
        printf("2. Dequeue (Static Circular Queue)\n");
        printf("3. Display (Static Circular Queue)\n");
        printf("4. Enqueue (Dynamic Circular Queue)\n");
        printf("5. Dequeue (Dynamic Circular Queue)\n");
        printf("6. Display (Dynamic Circular Queue)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                staticEnqueue(value);
                break;
            case 2:
                staticDequeue();
                break;
            case 3:
                displayStaticQueue();
                break;
            case 4:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                dynamicEnqueue(value);
                break;
            case 5:
                dynamicDequeue();
                break;
            case 6:
                displayDynamicQueue();
                break;
            case 7:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}

// Function to check if the static circular queue is full
int staticIsFull() {
    if ((staticFront == 0 && staticRear == MAX_SIZE - 1)|| (staticRear == staticFront - 1))
        return 1;
    else
        return 0;
}

// Function to check if the static circular queue is empty
int staticIsEmpty() {
    if (staticFront == -1)
        return 1;
    else
        return 0;
}

// Function to enqueue an element in the static circular queue
void staticEnqueue(int value) {
    if (staticIsFull()) {
        printf("Static Circular Queue is full. Cannot enqueue.\n");
        return;
    }

    if (staticFront == -1)
        staticFront = 0;

    staticRear = (staticRear + 1) % MAX_SIZE;
    staticQueue[staticRear] = value;

    printf("Enqueued %d to Static Circular Queue.\n", value);
}

// Function to dequeue an element from the static circular queue
void staticDequeue() {
    if (staticIsEmpty()) {
        printf("Static Circular Queue is empty. Cannot dequeue.\n");
        return;
    }

    int value = staticQueue[staticFront];

    if (staticFront == staticRear)
        staticFront = staticRear = -1;
    else
        staticFront = (staticFront + 1) % MAX_SIZE;

    printf("Dequeued %d from Static Circular Queue.\n", value);
}

// Function to display the static circular queue
void displayStaticQueue() {
if (staticIsEmpty()) {
printf("Static Circular Queue is empty.\n");
return;
}
int i;
printf("Static Circular Queue: ");
for (i = staticFront; i != staticRear; i = (i + 1) % MAX_SIZE) {
    printf("%d ", staticQueue[i]);
}
printf("%d\n", staticQueue[i]);
}

// Function to enqueue an element in the dynamic circular queue
void dynamicEnqueue(int value) {
struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
newNode->data = value;
newNode->next = NULL;
if (dynamicFront == NULL) {
    dynamicFront = dynamicRear = newNode;
} else {
    dynamicRear->next = newNode;
    dynamicRear = newNode;
}

dynamicRear->next = dynamicFront;

printf("Enqueued %d to Dynamic Circular Queue.\n", value);
}

// Function to dequeue an element from the dynamic circular queue
void dynamicDequeue() {
if (dynamicFront == NULL) {
printf("Dynamic Circular Queue is empty. Cannot dequeue.\n");
return;
}
int value = dynamicFront->data;
struct QueueNode* temp = dynamicFront;

if (dynamicFront == dynamicRear) {
    dynamicFront = dynamicRear = NULL;
} else {
    dynamicFront = dynamicFront->next;
    dynamicRear->next = dynamicFront;
}

free(temp);

printf("Dequeued %d from Dynamic Circular Queue.\n", value);
}

// Function to display the dynamic circular queue
void displayDynamicQueue() {
if (dynamicFront == NULL) {
printf("Dynamic Circular Queue is empty.\n");
return;
}
struct QueueNode* temp = dynamicFront;

printf("Dynamic Circular Queue: ");
while (temp->next != dynamicFront) {
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("%d\n", temp->data);
getch();
}
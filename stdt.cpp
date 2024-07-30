#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Define the maximum size for the static stack
#define MAX_SIZE 100

// Structure for the static stack
struct StaticStack {
    int arr[MAX_SIZE];
    int top;
};

// Structure for the dynamic stack node
struct DynamicStackNode {
    int data;
    struct DynamicStackNode* next;
};

// Structure for the dynamic stack
struct DynamicStack {
    struct DynamicStackNode* top;
};

// Function to initialize the static stack
void initializeStaticStack(struct StaticStack* stack) {
    stack->top = -1;
}

// Function to push an element into the static stack
void pushStaticStack(struct StaticStack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack->arr[++stack->top] = data;
    printf("Element %d pushed into the static stack\n", data);
}

// Function to pop an element from the static stack
void popStaticStack(struct StaticStack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    int data = stack->arr[stack->top--];
    printf("Popped element from the static stack: %d\n", data);
}

// Function to display the static stack
void displayStaticStack(struct StaticStack* stack) {
    if (stack->top == -1) {
        printf("Static stack is empty\n");
        return;
    }

    printf("Static Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Function to initialize the dynamic stack
void initializeDynamicStack(struct DynamicStack* stack) {
    stack->top = NULL;
}

// Function to check if the dynamic stack is empty
int isDynamicStackEmpty(struct DynamicStack* stack) {
    return stack->top == NULL;
}

// Function to create a new node for the dynamic stack
struct DynamicStackNode* createDynamicStackNode(int data) {
    struct DynamicStackNode* newNode = (struct DynamicStackNode*)malloc(sizeof(struct DynamicStackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element into the dynamic stack
void pushDynamicStack(struct DynamicStack* stack, int data) {
    struct DynamicStackNode* newNode = createDynamicStackNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Element %d pushed into the dynamic stack\n", data);
}

// Function to pop an element from the dynamic stack
void popDynamicStack(struct DynamicStack* stack) {
    if (isDynamicStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return;
    }

    struct DynamicStackNode* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped element from the dynamic stack: %d\n", data);
}

// Function to display the dynamic stack
void displayDynamicStack(struct DynamicStack* stack) {
    if (isDynamicStackEmpty(stack)) {
        printf("Dynamic stack is empty\n");
        return;
    }

    printf("Dynamic Stack: ");
    struct DynamicStackNode* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
       }
printf("\n");
}

int main() {
struct StaticStack staticStack;
struct DynamicStack dynamicStack;
int choice, data;
// Initialize the static and dynamic stacks
initializeStaticStack(&staticStack);
initializeDynamicStack(&dynamicStack);

do {
    printf("********** MENU **********\n");
    printf("1. Push into Static Stack\n");
    printf("2. Pop from Static Stack\n");
    printf("3. Display Static Stack\n");
    printf("4. Push into Dynamic Stack\n");
    printf("5. Pop from Dynamic Stack\n");
    printf("6. Display Dynamic Stack\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the element to push into the static stack: ");
            scanf("%d", &data);
            pushStaticStack(&staticStack, data);
            break;
        case 2:
            popStaticStack(&staticStack);
            break;
        case 3:
            displayStaticStack(&staticStack);
            break;
        case 4:
            printf("Enter the element to push into the dynamic stack: ");
            scanf("%d", &data);
            pushDynamicStack(&dynamicStack, data);
            break;
        case 5:
            popDynamicStack(&dynamicStack);
            break;
        case 6:
            displayDynamicStack(&dynamicStack);
            break;
        case 0:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid choice\n");
    }
} while (choice != 0);
getch();
return 0;
}

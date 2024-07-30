#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

void displayCount(struct Stack* stack) {
    printf("Total number of patients: %d\n", stack->top + 1);
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int choice, patientID;
    clrscr();
    while (1) {
        printf("\n--- Patient's Coupon Generator ---\n");
        printf("1. Generate Coupon for Patient\n");
        printf("2. Display Total Number of Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &patientID);
                push(&stack, patientID);
                printf("Coupon generated for Patient %d\n", patientID);
                break;
            case 2:
                displayCount(&stack);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    getch();
    return 0;
}

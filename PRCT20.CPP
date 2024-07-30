#include <stdio.h>
#include<conio.h>
#define MAX_SIZE 100

typedef struct {
    int top1;            // Top index of the first stack
    int top2;            // Top index of the second stack
    int stack[MAX_SIZE]; // Array to store the stacks
} TwoStacks;

// Initialize the two stacks
void initializeTwoStacks(TwoStacks *ts) {
    ts->top1 = -1;        // Initialize top1 for stack 1
    ts->top2 = MAX_SIZE;  // Initialize top2 for stack 2
}

// Check if the first stack is empty
int isStack1Empty(TwoStacks *ts) {
    return ts->top1 == -1;
}

// Check if the second stack is empty
int isStack2Empty(TwoStacks *ts) {
    return ts->top2 == MAX_SIZE;
}

// Check if the first stack is full
int isStack1Full(TwoStacks *ts) {
    return ts->top1 == ts->top2 - 1;
}

// Check if the second stack is full
int isStack2Full(TwoStacks *ts) {
    return ts->top2 == ts->top1 + 1;
}

// Push an element to the first stack
void push1(TwoStacks *ts, int item) {
    if (isStack1Full(ts)) {
        printf("Stack 1 is full. Overflow!\n");
        return;
    }
    
    ts->stack[++ts->top1] = item;
}

// Push an element to the second stack
void push2(TwoStacks *ts, int item) {
    if (isStack2Full(ts)) {
        printf("Stack 2 is full. Overflow!\n");
        return;
    }
    
    ts->stack[--ts->top2] = item;
}

// Pop an element from the first stack
int pop1(TwoStacks *ts) {
    if (isStack1Empty(ts)) {
        printf("Stack 1 is empty. Underflow!\n");
        return -1;  // Return a default value in case of underflow
    }
    
    return ts->stack[ts->top1--];
}

// Pop an element from the second stack
int pop2(TwoStacks *ts) {
    if (isStack2Empty(ts)) {
        printf("Stack 2 is empty. Underflow!\n");
        return -1;  // Return a default value in case of underflow
    }
    
    return ts->stack[ts->top2++];
}

int main() {
    TwoStacks ts;
    initializeTwoStacks(&ts);
    clrscr();
    // Push elements to stack 1
    push1(&ts, 10);
    push1(&ts, 20);
    push1(&ts, 30);

    // Push elements to stack 2
    push2(&ts, 40);
    push2(&ts, 50);

    // Pop elements from stack 1
    int item1 = pop1(&ts);
    printf("Popped from stack 1: %d\n", item1);

    // Pop elements from stack 2
    int item2 = pop2(&ts);
    printf("Popped from stack 2: %d\n", item2);
    getch();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
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

int evaluatePrefix(char prefix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(stack);

    int i, operand1, operand2, result;
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            push(stack, prefix[i] - '0');
        } else {
            operand1 = pop(stack);
            operand2 = pop(stack);
            switch (prefix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(stack, result);
        }
    }

    int finalResult = pop(stack);
    free(stack);
    return finalResult;
}

int evaluatePostfix(char postfix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(stack);

    int i, operand1, operand2, result;
    for (i = 0; i < strlen(postfix); i++) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(stack, result);
        }
    }

    int finalResult = pop(stack);
    free(stack);
    return finalResult;
}

int main() {
    char prefix[100];
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strlen(prefix) - 1] = '\0';
    clrscr();
    int prefixResult = evaluatePrefix(prefix);
    printf("Result of prefix expression: %d\n", prefixResult);

    char postfix[100];
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strlen(postfix) - 1] = '\0';

    int postfixResult = evaluatePostfix(postfix);
    printf("Result of postfix expression: %d\n", postfixResult);
    getch();
    return 0;
}

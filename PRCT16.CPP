#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    char items[MAX_SIZE];
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

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[(stack->top)--];
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPrefix(char infix[], char prefix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(stack);

    int i, j;
    j = 0;

    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (isOperand(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(stack, infix[i]);
        } else if (infix[i] == '(') {
            while (!isEmpty(stack) && stack->items[stack->top] != ')') {
                prefix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->items[stack->top] != ')') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(stack->items[stack->top])) {
                prefix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        prefix[j++] = pop(stack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (i = 0; i < len / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[len - i - 1];
        prefix[len - i - 1] = temp;
    }

    free(stack);
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    initialize(stack);

    int i, j;
    j = 0;

    for (i = 0; i < strlen(infix); i++) {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && stack->items[stack->top] != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->items[stack->top] != '(') {
                printf("Invalid Expression\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->items[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';

    free(stack);
}

int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';
    char prefix[100];
    infixToPrefix(infix, prefix);
    
    char postfix[100];
    infixToPostfix(infix, postfix);
    
    printf("Infix Expression: %s\n", infix);
    printf("Prefix Expression: %s\n", prefix);
    printf("Postfix Expression: %s\n", postfix);
    getch();
    return 0;
}

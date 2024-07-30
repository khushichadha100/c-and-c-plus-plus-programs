#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

// Node structure to represent each term of the polynomial
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new term node
Node* createTerm(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to the polynomial
void addTerm(Node** poly, int coefficient, int exponent) {
    Node* newTerm = createTerm(coefficient, exponent);
    
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                addTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    
    return result;
}

// Function to display the polynomial
void displayPolynomial(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free the memory allocated for the polynomial
void freePolynomial(Node* poly) {
    Node* current = poly;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create the first polynomial: 3x^2 + 4x^1 + 2x^0
    Node* poly1 = NULL;
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 4, 1);
    addTerm(&poly1, 2, 0);
    clrscr();
    
    // Create the second polynomial: 1x^2 + 2x^1 + 5x^0
    Node* poly2 = NULL;
    addTerm(&poly2, 1, 2);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 5, 0);
    
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    
    Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);
    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    getch();
    return 0;
}

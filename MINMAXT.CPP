#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum value in the BST
struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

// Function to find the maximum value in the BST
struct Node* findMax(struct Node* root) {
    if (root == NULL)
        return NULL;
    else if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

int main() {
    struct Node* root = NULL;
    int data;
    char choice;
    clrscr();
    printf("Enter data for the root node: ");
    scanf("%d", &data);
    root = insertNode(root, data);

    do {
        printf("Enter data to insert into the BST: ");
        scanf("%d", &data);

        root = insertNode(root, data);

        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);

    if (minNode != NULL)
        printf("Minimum value in the BST: %d\n", minNode->data);
    else
        printf("BST is empty\n");

    if (maxNode != NULL)
        printf("Maximum value in the BST: %d\n", maxNode->data);
    else
        printf("BST is empty\n");
    getch();
    return 0;
}

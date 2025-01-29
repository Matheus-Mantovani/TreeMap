#include "library.h"
#include <stdlib.h>
#include <string.h>

void menu() {
    printf("\n===== AVL Tree Menu =====\n");
    printf("1. Insert Node\n");
    printf("2. Print All Keys\n");
    printf("3. Print All Values\n");
    printf("4. Print All Keys and Values\n");
    printf("0. Exit\n");
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}

void updateHeight(Node* node) {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getBalance(Node* node) {
    if(node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

void inOrderValues(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrderValues(root->left);
    printf("%s ", root->value);
    inOrderValues(root->right);
}

void inOrderKeys(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrderKeys(root->left);
    printf("%d ", root->key);
    inOrderKeys(root->right);
}

void inOrderKeysAndValues(Node* root) {
    if(root == NULL) {
        return;
    }
    inOrderKeysAndValues(root->left);
    printf("[Key: %d || Value: %s]\n", root->key, root->value);
    inOrderKeysAndValues(root->right);
}


Node* newNode(int key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = strdup(value); //replace the use of malloc
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}


Node* leftRotate(Node* root) {
    Node* pivot = root->right;
    Node* pivotLeftChild = pivot->left;

    pivot->left = root;
    root->right = pivotLeftChild;

    root->height = max(height(root->left), height(root->right)) + 1;
    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;

    return pivot;
}



Node* rightRotate(Node* root) {
    Node* pivot = root->left;
    Node* pivotRightChild = pivot->right;

    pivot->right = root;
    root->left = pivotRightChild;

    root->height = max(height(root->left), height(root->right)) + 1;
    pivot->height = max(height(pivot->left), height(pivot->right)) + 1;

    return pivot;
}


Node* insert(Node* node, int key, char* value) {
    if(node == NULL) {
        return newNode(key, value);
    }

    if(key < node->key) {
        //lower keys go to the left
        node->left = insert(node->left, key, value);
    } else if(key > node->key) {
        //higher keys go to the right
        node->right = insert(node->right, key, value);
    } else {
        printf("Key already exists. Try again.\n");
        return node;
    }
    printf("Node inserted successfully!\n");

    updateHeight(node);

    int balance = getBalance(node);

    //simple right rotation
    //occurs when the newNode is inserted to the left of the left subtree
    if(balance > 1 && node->left && key < node->left->key) {
        return rightRotate(node);
    }

    //simple left rotation
    //occurs when the newNode is inserted to the right of the right subtree
    if(balance < -1 && node->right && key > node->right->key) {
        return leftRotate(node);
    }

    //double rotation, left then right
    //occurs when the newNode is inserted to the right of the left subtree
    if(balance > 1 && node->left && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //double rotation, right then left
    //occurs when the newNode is inserted to the left of the right subtree
    if(balance < -1 && node->right && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}



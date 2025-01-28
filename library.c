#include "library.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}


int height(Node* node) {
    return (node == NULL) ? 0 : node->height;
}



int getBalance(Node* node) {
    if(node == NULL) {
        return 0;
    }

    return height(node->left) - height(node->right);
}


Node* newNode(int key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    strcpy(newNode->value, value);
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

}



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


Node* leftRotate(Node* node) {

}



Node* rightRotate(Node* node) {

}


Node* insert(Node* node, int key, char* value) {

}



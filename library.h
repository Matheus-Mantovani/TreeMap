#include <stdio.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int max(int a, int b);
int height(Node* node);
int getBalance(Node* node);
Node* leftRotate(Node* node);
Node* rightRotate(Node* node);
Node* newNode(int key, char* value);
Node* insert(Node* node, int key, char* value);
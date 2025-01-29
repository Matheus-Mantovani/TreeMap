#include "library.h"

int main() {
    Node* root = NULL;
    int choice, key;
    char value[100];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%s", value);
                root = insert(root, key, value);
                break;
                
            case 2:
                printf("Keys in the tree: ");
                inOrderKeys(root);
                printf("\n");
                break;
                
            case 3:
                printf("Values in the tree: ");
                inOrderValues(root);
                printf("\n");
                break;
                
            case 4:
                printf("Keys and Values in the tree: \n");
                inOrderKeysAndValues(root);
                break;
                
            case 0:
                printf("Exiting...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 0);
    
    return 0;
}
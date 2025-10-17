#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct Node* insert(struct Node* root, char word[], char meaning[]) {
    if (root == NULL)
        return createNode(word, meaning);
    
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word already exists in dictionary.\n");

    return root;
}

// Function to search for a word
void search(struct Node* root, char word[]) {
    if (root == NULL) {
        printf("Word not found!\n");
        return;
    }

    if (strcmp(word, root->word) == 0)
        printf("Meaning of '%s' is: %s\n", word, root->meaning);
    else if (strcmp(word, root->word) < 0)
        search(root->left, word);
    else
        search(root->right, word);
}

// Function for in-order traversal (display all words in order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[MAX_WORDS], meaning[MAX_WORDS];
    
    do {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert Word\n2. Search Word\n3. Display Dictionary\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter Word: ");
                 scanf("%s", word); 

                printf("Enter Meaning: ");
                scanf(" %[^\n]", meaning);
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter Word to Search: ");
                scanf("%s", word);
                search(root, word);
                break;
            case 3:
                printf("\n--- Dictionary Words ---\n");
                inorder(root);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
    
    return 0;
}
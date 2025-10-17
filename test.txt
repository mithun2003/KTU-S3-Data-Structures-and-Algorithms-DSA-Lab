#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree node structure
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

// Stack node structure
typedef struct Stack {
    struct Node* data;
    struct Stack* next;
} Stack;

Stack* top = NULL;

// Function to create new tree node
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Stack operations
void push(Node* treeNode) {
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->data = treeNode;
    temp->next = top;
    top = temp;
}

Node* pop() {
    if (top == NULL) return NULL;
    Stack* temp = top;
    struct Node* res = top->data;
    top = top->next;
    free(temp);
    return res;
}

// Create Expression Tree from postfix expression
Node* createExpressionTree(char postfix[]) {
    int i = 0;
    char symbol;
    while ((symbol = postfix[i]) != '\0') {
        if (isdigit(symbol)) {  // Operand
            Node* operandNode = createNode(symbol);
            push(operandNode);
        } else {  // Operator
            Node* operatorNode = createNode(symbol);
            operatorNode->right = pop();
            operatorNode->left = pop();
            push(operatorNode);
        }
        i++;
    }
    return pop();  // Root node
}

// Inorder traversal (infix)
void inorder(Node* root) {
    if (root != NULL) {
        if (root->left && root->right) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left && root->right) printf(")");
    }
}

// Preorder traversal (prefix)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (postfix)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    Node* root = NULL;
    int choice;
    char postfix[MAX];

    do {
        printf("\nMenu\n----\n");
        printf("1. Create Expression Tree\n");
        printf("2. Inorder Traversal (Infix Expression)\n");
        printf("3. Preorder Traversal (Prefix Expression)\n");
        printf("4. Postorder Traversal (Postfix Expression)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                root = createExpressionTree(postfix);
                printf("Expression Tree Created Successfully.\n");
                break;
            case 2:
                if (root == NULL)
                    printf("Create the tree first!\n");
                else {
                    printf("Inorder Traversal (Infix): ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Create the tree first!\n");
                else {
                    printf("Preorder Traversal (Prefix): ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Create the tree first!\n");
                else {
                    printf("Postorder Traversal (Postfix): ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (1);

    return 0;
}

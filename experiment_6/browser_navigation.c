#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

// Function to visit a new page
void visitPage() {
    char url[100];
    printf("Enter URL: ");
    scanf("%s", url);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = current;
    newNode->next = NULL;

    if (current != NULL) {
        // Remove all forward history
        Node* temp = current->next;
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newNode;
    } else {
        head = newNode;  // First node
    }

    current = newNode;
    printf("Visited: %s\n", current->url);
}

// Function to go back
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page.\n");
    } else {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
}

// Function to go forward
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No next page.\n");
    } else {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
}

// Function to display current page
void displayCurrent() {
    if (current == NULL) {
        printf("No page currently opened.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}

// Function to display browsing history
void displayHistory() {
    if (head == NULL) {
        printf("No browsing history.\n");
        return;
    }
    Node* temp = head;
    printf("Browsing History:\n");
    while (temp != NULL) {
        if (temp == current)
            printf(">> %s\n", temp->url);  // highlight current page
        else
            printf("%s\n", temp->url);
        temp = temp->next;
    }
}

int main() {
    int choice;
    printf("\nBrowser Navigation Simulation:\n");
    printf("1. Visit New Page\n");
    printf("2. Back\n");
    printf("3. Forward\n");
    printf("4. Display Current Page\n");
    printf("5. Display Browsing History\n");
    printf("6. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitPage();
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrent();
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter a valid choice (1-6)\n");
        }
    }
    return 0;
}

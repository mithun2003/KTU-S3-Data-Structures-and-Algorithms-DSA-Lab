#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Insert term at the end
void insertTerm(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Add term in result combining like terms
Node* addTerm(Node* result, int coeff, int exp) {
    Node* temp = result;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->exp == exp) {
            temp->coeff += coeff;
            return result;
        }
        prev = temp;
        temp = temp->next;
    }
    // No matching term found, insert at end
    Node* newNode = createNode(coeff, exp);
    if (prev == NULL)
        result = newNode;
    else
        prev->next = newNode;
    return result;
}

// Multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    for (Node* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != NULL; p2 = p2->next) {
            result = addTerm(result, p1->coeff * p2->coeff, p1->exp + p2->exp);
        }
    }
    return result;
}

// Display polynomial
void displayPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *product = NULL;
    int n, coeff, exp;

    printf("Enter number of terms for Polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("\nEnter number of terms for Polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    product = multiplyPolynomials(poly1, poly2);

    printf("Product: ");
    displayPolynomial(product);

    return 0;
}
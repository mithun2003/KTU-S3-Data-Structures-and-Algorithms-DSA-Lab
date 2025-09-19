#include <stdio.h>

int addPoly(int p1[][2], int p2[][2], int sum[][2], int size1, int size2);
void displayPoly(int poly[][2], int size);
int enterPoly(int poly[][2]);

int addPoly(int p1[][2], int p2[][2], int sum[][2], int size1, int size2) {    
    int i=0, j=0, k=0;
    while (i < size1 && j < size2) {
        if (p1[i][1] == p2[j][1]) {
            sum[k][0] = p1[i][0] + p2[j][0];
            sum[k][1] = p1[i][1];
            i++;
            j++;
        } else if (p1[i][1] > p2[j][1]) {
            sum[k][0] = p1[i][0];
            sum[k][1] = p1[i][1];
            i++;
        } else {
            sum[k][0] = p2[j][0];
            sum[k][1] = p2[j][1];
            j++;
        }
        k++;
    }

    while(i < size1) {
        sum[k][0] = p1[i][0];
        sum[k][1] = p1[i][1];
        i++;
        k++;
    }

    while(j < size2) {
        sum[k][0] = p2[j][0];
        sum[k][1] = p2[j][1];
        j++;
        k++;
    }
    return k;  // Return the number of non-zero terms in the sum
}

void displayPoly(int poly[][2], int size) {
    for (int i = 0; i < size; i++) {
        if (poly[i][0] != 0) {
            printf("%dx^%d ", poly[i][0], poly[i][1]);
            if (i < size - 1) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

int enterPoly(int poly[][2]) {
    int size;
    printf("Enter the number of non-zero terms in the polynomial: ");
    scanf("%d", &size);
    printf("Enter the coefficients and exponents (coefficient exponent) in descending order of exponents:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &poly[i][0], &poly[i][1]);
    }
    printf("\n");
    return size;
}

int main() {
    int p1[100][2], p2[100][2], sum[200][2];
    int size1, size2, sumSize;

    printf("Enter first polynomial:\n");
    size1 = enterPoly(p1);
    
    printf("Enter second polynomial:\n");
    size2 = enterPoly(p2);
    
    sumSize = addPoly(p1, p2, sum, size1, size2);
    
    printf("First Polynomial: ");
    displayPoly(p1, size1);
    
    printf("Second Polynomial: ");
    displayPoly(p2, size2);
    
    printf("Sum of Polynomials: ");
    displayPoly(sum, sumSize);
    
    return 0;
}
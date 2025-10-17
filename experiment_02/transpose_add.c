#include <stdio.h>

#define MAX 100

void readSparseMatrix(int matrix[MAX][3], char name);
void transposeSparseMatrix(int matrix[MAX][3], char name);
void addSparseMatrices(int mat1[MAX][3], int mat2[MAX][3]);
void displaySparseMatrix(int matrix[MAX][3]);

void readSparseMatrix(int matrix[MAX][3], char name) {
  int rows, cols, nonZero;
  printf("Enter number of rows, columns and non-zero elements for matrix %c: ",
         name);
  scanf("%d %d %d", &rows, &cols, &nonZero);
  matrix[0][0] = rows;
  matrix[0][1] = cols;
  matrix[0][2] = nonZero;

  printf(
      "Enter the row index, column index and value of each non-zero element "
      "(row col value):\n");
  for (int i = 1; i <= nonZero; i++) {
    printf("Row %d: ", i);
    scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
  }
  printf("\n");
}

void displaySparseMatrix(int matrix[MAX][3]) {
  printf("Row Col Value\n");
  for (int i = 0; i <= matrix[0][2]; i++) {
    printf("%d   %d   %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
  }
}

void transposeSparseMatrix(int matrix[MAX][3], char name) {
  int transposed[MAX][3];
  int i, j, k = 1;

  transposed[0][0] = matrix[0][0];
  transposed[0][1] = matrix[0][1];
  transposed[0][2] = matrix[0][2];

  for (i = 0; i < matrix[0][1]; i++) {
    for (j = 1; j <= matrix[0][2]; j++) {
      if (matrix[j][1] == i) {
        transposed[k][0] = matrix[j][1];
        transposed[k][1] = matrix[j][0];
        transposed[k][2] = matrix[j][2];
        k++;
      }
    }
  }
  printf("\nTransposed Sparse Matrix %c:\n", name);
  displaySparseMatrix(transposed);
}

void addSparseMatrices(int mat1[MAX][3], int mat2[MAX][3]) {
  if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]) {
    printf("Matrices dimensions do not match for addition.\n");
    return;
  }

  int sum[MAX][3];
  sum[0][0] = mat1[0][0];
  sum[0][1] = mat1[0][1];
  int i = 1, j = 1, k = 1;

  while (i <= mat1[0][2] && j <= mat2[0][2]) {
    if (mat1[i][0] == mat2[j][0] && mat1[i][1] == mat2[j][1]) {
      sum[k][0] = mat1[i][0];
      sum[k][1] = mat1[i][1];
      sum[k][2] = mat1[i][2] + mat2[j][2];
      i++;
      j++;
    } else if ((mat1[i][0] < mat2[j][0]) ||
               (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
      sum[k][0] = mat1[i][0];
      sum[k][1] = mat1[i][1];
      sum[k][2] = mat1[i][2];
      i++;
    } else {
      sum[k][0] = mat2[j][0];
      sum[k][1] = mat2[j][1];
      sum[k][2] = mat2[j][2];
      j++;
    }
    k++;
  }

  while (i <= mat1[0][2]) {
    sum[k][0] = mat1[i][0];
    sum[k][1] = mat1[i][1];
    sum[k][2] = mat1[i][2];
    i++;
    k++;
  }

  while (j <= mat2[0][2]) {
    sum[k][0] = mat2[j][0];
    sum[k][1] = mat2[j][1];
    sum[k][2] = mat2[j][2];
    j++;
    k++;
  }
  sum[0][2] = k - 1;
  printf("\nSum of Sparse Matrices:\n");
  displaySparseMatrix(sum);
}

int main() {
  int mat1[MAX][3], mat2[MAX][3];
  readSparseMatrix(mat1, 'A');
  readSparseMatrix(mat2, 'B');

  printf("\nMatrix A:\n");
  displaySparseMatrix(mat1);
  printf("\nMatrix B:\n");
  displaySparseMatrix(mat2);

  transposeSparseMatrix(mat1, 'A');
  transposeSparseMatrix(mat2, 'B');

  addSparseMatrices(mat1, mat2);

  return 0;
}
# Experiment 02: Find the Transpose of a Sparse Matrix and Sum of Two Sparse Matrices

## 🎯 Aim

To implement a program that finds **transpose** of a sparse matrix and **sum of two sparse matrices**.

## 📝 Algorithm

1. Start

2. Read matrix `mat1`.

   - Input dimensions and non-zero elements: Read the number of rows, columns, and non-zero elements for `mat1`.

   - Store these in` mat1[0][0], mat1[0][1], mat1[0][2]` respectively.

   - Input row index, column index, and value of non-zero elements:
     ```
     for i = 1 to mat1[0][2] do
        Read row index, column index and value
        Store in mat1[i][0], mat1[i][1], mat1[i][2]
     ```

3. Read matrix `mat2`.

   - Read `mat2` using the same procedure as for mat1.

4. Display matrices `mat1` and `mat2`

   - Print the contents of `mat1` and `mat2`.

5. Transpose matrix `mat1`

- Initialize a new matrix `transposed`

- Copy dimensions:

  - transposed[0][0] = mat1[0][1] (rows of transpose = columns of original)

  - transposed[0][1] = mat1[0][0] (columns of transpose = rows of original)

  - transposed[0][2] = mat1[0][2] (no.of non-zero elements remains the same)

- set k = 1(index for `transposed` matrix)

- Iterate through columns of the original matrix

  ```
   for each column i = 0 to mat1[0][1]-1 do
      for each element j = 1 to mat1[0][2] do
            if `mat1[j][1] == i` then
               transposed[k][0] = mat1[j][1]  // New row index is original column index
               transposed[k][1] = mat1[j][0]  // New column index is original row index
               transposed[k][2] = mat1[j][2]  // Value remains the same
               k++
            end if
      end for
   end for
  ```

- Display transposed matrix.

6. Transpose matrix `mat2`

   - Transpose `mat2` using the same procedure as for `mat1`

7. Add matrix `mat1` and `mat2`

   - if (mat1[0][0] != mat2[0][0]) OR (mat1[0][1] != mat2[0][1])

     - Print "Matrices dimensions do not match for addition"

     - Stop

   - else

     - Initialize sum[100][3]

     - sum[0][0] = mat1[0][0]

     - sum[0][1] = mat1[0][1]

     - set i = 1, j = 1, k = 1

     - while `i <= mat1[0][2]` AND `j <= mat2[0][2]` do

       - if (mat1[i][0] == mat2[j][0]) AND (mat1[i][1] == mat2[j][1]) then

         - sum[k][0] = mat1[i][0]
         - sum[k][1] = mat1[i][1]
         - sum[k][2] = mat1[i][2] + mat2[j][2]
         - i++, j++

       - else if (mat1[i][0] < mat2[j][0]) OR (mat1[i][0] == mat2[j][0] AND mat1[i][1] < mat2[j][1])

         - sum[k][0] = mat1[i][0]
         - sum[k][1] = mat1[i][1]
         - sum[k][2] = mat1[i][2]
         - i++

       - else

         - sum[k][0] = mat1[j][0]
         - sum[k][1] = mat1[j][1]
         - sum[k][2] = mat1[j][2]
         - j++

       - k++

8. Copy remaining terms of `mat1` to `sum`(if any)

   - while `i<=mat1[0][2]`
     - sum[k][0] = mat1[i][0]
     - sum[k][1] = mat1[i][1]
     - sum[k][2] = mat1[i][2]
     - i++, k++;

9. Copy remaining terms of `mat2` to `sum`(if any)

   - while `i<=mat2[0][2]`
     - sum[k][0] = mat2[i][0]
     - sum[k][1] = mat2[i][1]
     - sum[k][2] = mat2[i][2]
     - i++, k++;

10. set sum[0][2] = k - 1

11. Display sum

    - Print "Resultant Sparse Matrix"

    - for i = 0 to k - 1 do

      Print sum[i][0] sum[i][1] sum[i][2]

12. Stop

## ⌨️ Output (Example)

```
Enter number of rows, columns and non-zero elements for matrix A: 3 3 2
Enter the row index, column index and value of each non-zero element (row col value):
Row 1: 1 0 1
Row 2: 2 2 1

Enter number of rows, columns and non-zero elements for matrix B: 3 3 2
Enter the row index, column index and value of each non-zero element (row col value):
Row 1: 1 1 9
Row 2: 2 2 5

Matrix A:
Row Col Value
3   3   2
1   0   1
2   2   1

Matrix B:
Row Col Value
3   3   2
1   1   9
2   2   5

Transposed Sparse Matrix A:
Row Col Value
3   3   2
0   1   1
2   2   1

Transposed Sparse Matrix B:
Row Col Value
3   3   2
1   1   9
2   2   5

Sum of Sparse Matrices:
Row Col Value
3   3   3
1   0   1
1   1   9
2   2   6
```


## 💻 Code Screenshot

![Code Screenshot](/screenshots/2.1.png)
![Code Screenshot](/screenshots/2.2.png)
![Code Screenshot](/screenshots/2.3.png)

## 🖥️ Output Screenshot

![Code Screenshot](/screenshots/2.out.png)

# Experiment 01: Find the Sum of Two Sparse Polynomials using Arrays

## 🎯 Aim

To implement a program that finds the sum of two sparse polynomials using arrays.

## 📝 Algorithm

1. Start

2. Read polynomial `p1` (sotre as coeff-exponent pairs in descending order of exponents) with size `size1`.

3. Read polynomial `p2` (same way) with size `size2`.

4. Initialize i,j,k=0.

5. while both `i<size1` and `j<size2`

   - if p1[i][1]==p2[j][1] then

     - add `coefficients` → sum [k][0] = p1[i][0]+p2[j][0]

     - store `exponent` → sum[k][1]= p1[i][1]

     - increment i,j → i++, j++

   - else if `p[i][i]> p[j][1]` then

     - store `coefficient` of p1 → sum[k][0] = p1[i][0]

     - store `exponent` of p1 → sum [k][1]=p1[i][1]

     - increment i → i++

   - else then

     - store `coefficient` of p2 → sum[k][0] = p2[j][0]

     - store `exponent` of p2 → sum [k][1]=p1[j][1]

     - increment j → j++

   - increment k → k++

6. Copy remaining terms of `p1`(if any)

   - while `i<size1`

     - sum[k][0] = p1[i][0]

     - sum[k][1] = p1[i][1]

     - increment i, k → i++, k++;

7. Copy remaining terms of `p2`(if any)

   - while `j<size2`

     - sum[k][0] = p2[j][0]

     - sum[k][1] = p2[j][1]

     - increment j, k → j++, k++;

8. set sumSize = k (no.of terms in sum)

9. Display all terms of sum

   - for i=0 to sumSize - 1 do

     - Print sum[i][0]x^sum[i][1]

     - if `i < sumSize - 1`

       - print(" + ")

10. Stop

## ⌨️ Output (Example)

```
Enter first polynomial:
Enter number of terms in Polynomial 1: 3
Polynomial 1 terms (coefficient exponent):
3 2
6 1
5 0

Enter second polynomial:
Enter number of terms in Polynomial 2: 3
Polynomial 2 terms (coefficient exponent):
5 2
1 1
9 0

First Polynomial: 3x^2 + 6x^1 + 5x^0
Second Polynomial: 5x^2 + 1x^1 + 0x^0
Sum of Polynomial: 8x^2 + 7x^1 + 14x^0
```

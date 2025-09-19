# Experiment 01: Sum of Two Sparse Polynomials using Arrays


## 🎯 Aim
To implement a program that finds the sum of two sparse polynomials using arrays.


## 📝 Algorithm
1. Represent each polynomial using an array of triplets `(coefficient, exponent)`.  
   Example: `ax^n + bx^m` → `[(a, n), (b, m)]`
2. Read both polynomials and store them in arrays.
3. Initialize a result array to store the sum.
4. Traverse both arrays simultaneously:
   - If exponents are equal → add coefficients and store in the result.
   - If exponent of polynomial 1 is greater → copy the term from polynomial 1.
   - Else → copy the term from polynomial 2.
5. Copy any remaining terms from either polynomial.
6. Print the resulting polynomial.



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
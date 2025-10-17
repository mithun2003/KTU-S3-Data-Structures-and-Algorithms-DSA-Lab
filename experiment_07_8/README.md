# Experiment 6: Implement Addition And Multiplication Of Polynomials Using Singly Linked Lists

## 🔹 6.1 Addition of Polynomials using Singly Linked List

## 🎯 Aim

To implement **addition of two polynomials** using **singly linked lists** and display the result.

## Algorithm

1. Start

2. Represent Polynomial

   - Each term is represented as a **node** with:
     - `coeff` → coefficient of the term
     - `exp` → exponent of the term
     - `next` → pointer to the next term

3. Read the number of terms and corresponding `(coefficient, exponent)` pairs for the first polynomial and store them in `poly1`.

4. Read the number of terms and corresponding `(coefficient, exponent)` pairs for the second polynomial and store them in `poly2`.

5. Polynomial Addition

   1. Initialize `result` as an empty polynomial.
   2. While both `poly1` and `poly2` are not NULL do
      - if `poly1→exponent` == `poly2→exponent` then
        - Sum coefficients and create term in `result`.
        - Move both `poly1` and `poly2` to next.
      - else if `poly1→exponent > poly2→exponent` then
        - Add `poly1` term to `result`.
        - Move `poly1` to next.
      - else then
        - Add `poly2` term to `result`.
        - Move `poly2` to next.
   3. Append remaining terms from `poly1` or `poly2` to `result`.

6. Display `poly1`, `poly2`, and the `result` polynomials
   - Traverse through the list.
   - Print each term in the format `coeff x^exp`.
   - If not the last term, print `" + "`.
7. Stop

## ⌨️ Output (Example)

```
Enter number of terms for Polynomial 1: 3
Enter coefficient and exponent for term 1: 5 2
Enter coefficient and exponent for term 2: 3 1
Enter coefficient and exponent for term 3: 2 0

Enter number of terms for Polynomial 2: 3
Enter coefficient and exponent for term 1: 4 3
Enter coefficient and exponent for term 2: 2 1
Enter coefficient and exponent for term 3: 1 0

Polynomial 1: 5x^2 + 3x^1 + 2x^0
Polynomial 2: 4x^3 + 2x^1 + 1x^0
Sum: 4x^3 + 5x^2 + 5x^1 + 3x^0

```

---

## 🔹 6.2 Multiplication of Polynomials using Singly Linked List

## 🎯 Aim

To implement **multiplication of two polynomials** using **singly linked lists** and display the result.

## Algorithm

1. Start

2. Represent Polynomial

   - Each term is represented as a **node** with:
     - `coeff` → coefficient of the term
     - `exp` → exponent of the term
     - `next` → pointer to the next term

3. Read the number of terms and corresponding `(coefficient, exponent)` pairs for the first polynomial and store them in `poly1`.

4. Read the number of terms and corresponding `(coefficient, exponent)` pairs for the second polynomial and store them in `poly2`.

5. Multiply Two Polynomials (with Combining Like Terms)

   - Initialize `result = NULL`.
   - For each term in `poly1`:
     - For each term in `poly2`:
     - Multiply coefficients → `coeff = poly1→coeff * poly2→coeff`.
     - Add exponents → `exp = poly1→exp + poly2→exp`.
     - Insert `(coeff, exp)` into `result` as follows:
       - If a term with the same exponent exists in `result`, add the new coefficient to it.
       - Otherwise, create a new node and append it to the list.
   - Return `result`.

6. Display `poly1`, `poly2`, and the `result` polynomials

   - Traverse through the list.
   - Print each term in the format `coeff x^exp`.
   - If not the last term, print `" + "`.

7. Stop.

## ⌨️ Output (Example)

```
Enter number of terms for Polynomial 1: 2
Enter coefficient and exponent for term 1: 3 2
Enter coefficient and exponent for term 2: 2 1

Enter number of terms for Polynomial 2: 2
Enter coefficient and exponent for term 1: 1 1
Enter coefficient and exponent for term 2: 4 0

Polynomial 1: 3x^2 + 2x^1
Polynomial 2: 1x^1 + 4x^0
Product: 3x^3 + 14x^2 + 8x^1
```

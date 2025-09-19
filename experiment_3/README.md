# Experiment 03: Convert Infix Expression To Postfix Prefix And Evaluate Using Stack


## 🎯 Aim
To implement a program that converts an **Infix Expression** into its equivalent **Postfix** and **Prefix** expressions using stack operations.


## Algorithm

### Infix to Postfix
1. Initialize an empty stack.
2. Scan the infix expression from left to right.
3. If the symbol is an operand, add it to the output.
4. If the symbol is '(', push it onto the stack.
5. If the symbol is ')', pop and add all operators to the output until '(' is encountered. Discard the pair of parentheses.
6. If the symbol is an operator:
   - While the stack is not empty **and** the precedence of the top operator is greater or equal to the scanned operator, pop from stack and add to output.
   - Push the scanned operator.
7. After scanning, pop and append all remaining operators from the stack.
8. The final string is the postfix expression.

### Infix to Prefix
1. Reverse the infix expression.
2. Swap '(' with ')' and vice versa.
3. Convert the modified expression to postfix using the above algorithm.
4. Reverse the resulting postfix expression to get the prefix expression.



## ⌨️ Output (Example)
```
Enter an infix expression: (a+b)*(c+d)
Original Infix Expression: (a+b)*(c+d)

Postfix Expression: ab+cd+*
Prefix Expression: *+ab+cd
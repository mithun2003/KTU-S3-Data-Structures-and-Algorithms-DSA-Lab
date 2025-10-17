# Experiment 03: Convert Infix Expression To Postfix Prefix And Evaluate Using Stack

## 🎯 Aim

To implement a program that converts an **Infix Expression** into its equivalent **Postfix** and **Prefix** expressions using stack operations.

## Algorithm

### Infix to Postfix

1. Start
2. Initialize an empty stack.
3. Scan the infix expression from left to right.
4. If the symbol is an operand, add it to the output.
5. If the symbol is '(', push it onto the stack.
6. If the symbol is ')', pop and add all operators to the output until '(' is encountered. Discard the pair of parentheses.
7. If the symbol is an operator:
   - While the stack is not empty **and** the precedence of the top operator is greater or equal to the scanned operator, pop from stack and add to output.
   - Push the scanned operator.
8. After scanning, pop and append all remaining operators from the stack.
9. The final string is the postfix expression.
10. Stop

### Infix to Prefix

1. Start
2. Reverse the infix expression.
3. Swap '(' with ')' and vice versa.
4. Convert the modified expression to postfix using the above algorithm.
5. Reverse the resulting postfix expression to get the prefix expression.
6. Stop

## ⌨️ Output (Example)

```
Enter an infix expression: (a+b)*(c+d)
Original Infix Expression: (a+b)*(c+d)

Postfix Expression: ab+cd+*
Prefix Expression: *+ab+cd
```

## 💻 Code Screenshot

![Code Screenshot](/screenshots/3.1.png)
![Code Screenshot](/screenshots/3.2.png)
![Code Screenshot](/screenshots/3.3.png)

## 🖥️ Output Screenshot

![Code Screenshot](/screenshots/3.out.png)

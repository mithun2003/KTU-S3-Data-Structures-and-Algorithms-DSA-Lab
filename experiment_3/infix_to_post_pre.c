#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char infix[MAX], postfix[MAX], prefix[MAX], stack[MAX];
int top = -1;

void push(char c) {
  if (top < MAX - 1) {
    stack[++top] = c;
  }
}

char pop() {
  if (top >= 0) {
    return stack[top--];
  }
  return '\0';  // Return null character if stack is empty
}

char peek() {
  if (top >= 0) {
    return stack[top];
  }
  return '\0';  // Return null character if stack is empty
}

int precedence(char c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

void infix_to_postfix() {
  int i, j = 0;
  char c;

  for (i = 0; infix[i] != '\0'; i++) {
    c = infix[i];
    if (!(isspace(c))) {
      switch (c) {
        case '(':
          push(c);
          break;
        case ')':
          while (top != -1 && peek() != '(') {
            postfix[j++] = pop();
          }
          pop();  // Remove '(' from stack
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
          while (top != -1 && precedence(peek()) >= precedence(c)) {
            postfix[j++] = pop();
          }
          push(c);
          break;
        default:
          postfix[j++] = c;
      }
    }
  }

  while (top != -1) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';

  printf("Postfix Expression: ");
  puts(postfix);
}

void infix_to_prefix() {
  int i, j = 0, n = strlen(infix) - 1;
  char c;

  for (i = n; infix[i] != 0; i--) {
    c = infix[i];
    if (!(isspace(c))) {
      switch (c) {
        case ')':
          push(c);
          break;
        case '(':
          while (top != -1 && peek() != ')') {
            prefix[j++] = pop();
          }
          pop();  // Remove ')' from stack
          break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
          while (top != -1 && precedence(peek()) > precedence(c)) {
            prefix[j++] = pop();
          }
          push(c);
          break;
        default:
          prefix[j++] = c;
      }
    }
  }

  while (top != -1) {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';

  // Reverse the prefix expression to get the final result
  printf("Prefix Expression: ");
  i = n;
  while (i >= 0) {
    printf("%c", prefix[i--]);
  }
  printf("\n");
}

int main() {
  printf("Enter an infix expression: ");
  fgets(infix, MAX, stdin);

  printf("Original Infix Expression: ");
  puts(infix);

  infix_to_postfix();

  // Reset stack for prefix conversion
  top = -1;
  infix_to_prefix();

  return 0;
}
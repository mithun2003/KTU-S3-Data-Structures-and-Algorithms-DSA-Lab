# **Experiment 09: Create a Binary Tree for an Arithmetic Expression and Find its Prefix and Postfix Equivalents**

## 🎯 Aim

To implement a program that **creates a binary tree for a given arithmetic expression** and then **converts it into prefix and postfix equivalents** using tree traversals.


## 📝 Algorithm

1. Start

2. Input the arithmetic expression in postfix form.

3. Initialize an empty stack to store pointers to tree nodes.

4. Scan the postfix expression from left to right:
   - If the symbol is an operand (number or variable):
     - Create a new tree node.
     - Push the new node onto the stack.
   - If the symbol is an operator (`+`, `-`, `*`, `/`, etc.):
     - Pop two nodes from the stack.  
       - The first popped node becomes the right child.  
       - The second popped node becomes the left child.
     - Create a new node for the operator.
     - Attach the two popped nodes as its children.
     - Push the new operator node back onto the stack.

5. After the entire postfix expression is processed,  
   the single remaining node on the stack becomes the root of the binary expression tree.

6. Perform Traversals
   - Inorder Traversal (Infix Expression)
     ```
     inorder(node):
        if node != NULL:
            if node has both left and right child:
                print "("
            inorder(node->left)
            print node->data
            inorder(node->right)
            if node has both left and right child:
                print ")"
     ```
     → Produces the infix form `(a + b)` etc.

   - Preorder Traversal (Prefix Expression)
     ```
     preorder(node):
        if node != NULL:
            print node->data
            preorder(node->left)
            preorder(node->right)
     ```
     → Produces the prefix form `+ab`.

   - Postorder Traversal (Postfix Expression)
     ```
     postorder(node):
        if node != NULL:
            postorder(node->left)
            postorder(node->right)
            print node->data
     ```
     → Produces the postfix form `ab+`.

7. Display the expressions obtained from each traversal:
   - Inorder → Infix  
   - Preorder → Prefix  
   - Postorder → Postfix

8. Stop



## 🌳 Visual Representation of Expression Tree

For the infix expression: (3+2)*4


The equivalent postfix is: 32+4*


**Expression Tree Structure:**
  ```
    *
   / \
  +   4
 / \
3   2
```


## 🔁 Traversal Results

| **Traversal Type** | **Node Visiting Order** | **Equivalent Expression** |
|---------------------|--------------------------|----------------------------|
| **Inorder**         | Left → Root → Right      | ((3 + 2) * 4) (Infix)     |
| **Preorder**        | Root → Left → Right      | * + 3 2 4 (Prefix)        |
| **Postorder**       | Left → Right → Root      | 3 2 + 4 * (Postfix)       |

---

## ⌨️ Sample Input / Output
```
Menu
----
1. Create Expression Tree
2. Inorder Traversal (Infix Expression)
3. Preorder Traversal (Prefix Expression)
4. Postorder Traversal (Postfix Expression)
5. Exit
Enter your choice: 1
Enter postfix expression: 32+4*
Expression Tree Created Successfully.

Menu
----
1. Create Expression Tree
2. Inorder Traversal (Infix Expression)
3. Preorder Traversal (Prefix Expression)
4. Postorder Traversal (Postfix Expression)
5. Exit
Enter your choice: 2
Inorder Traversal (Infix): ((3+2)*4)

Menu
----
1. Create Expression Tree
2. Inorder Traversal (Infix Expression)
3. Preorder Traversal (Prefix Expression)
4. Postorder Traversal (Postfix Expression)
5. Exit
Enter your choice: 3
Preorder Traversal (Prefix): *+324

Menu
----
1. Create Expression Tree
2. Inorder Traversal (Infix Expression)
3. Preorder Traversal (Prefix Expression)
4. Postorder Traversal (Postfix Expression)
5. Exit
Enter your choice: 4
Postorder Traversal (Postfix): 32+4*

Menu
----
1. Create Expression Tree
2. Inorder Traversal (Infix Expression)
3. Preorder Traversal (Prefix Expression)
4. Postorder Traversal (Postfix Expression)
5. Exit
Enter your choice: 5
Exiting program.
```



## 💻 Code Screenshot

![Code Screenshot](/screenshots/9.1.png)  
![Code Screenshot](/screenshots/9.2.png)



## 🖥️ Output Screenshot

![Output Screenshot](/screenshots/9.out.png)



## 🧠 Notes

- The **expression tree** represents operators as internal nodes and operands as leaf nodes.  
- The **prefix** expression is obtained through **preorder traversal**, while the **postfix** expression is obtained through **postorder traversal**.  
- Inorder traversal with parentheses displays the **original infix** arithmetic expression.


✅ **Hence, the program successfully constructs a binary expression tree and derives its prefix and postfix equivalents from it.**
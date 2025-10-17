# **Experiment 10: Implement a Dictionary of Word–Meaning Pairs using Binary Search Trees**

## 🎯 Aim

To implement a dictionary that stores word–meaning pairs using a Binary Search Tree (BST), allowing efficient insertion, searching, and alphabetical display of words.



## 📝 Algorithm

1. Start

2. Create a Node Structure
   - Each node contains:
     - `word` – the keyword (string).
     - `meaning` – its respective meaning (string).
     - left and right pointers to represent BST links.

3. Insert Operation
   - If the tree is empty, create a new node and set it as the root.
   - If the new word is alphabetically smaller than the root’s word, insert it into the left subtree.
   - If it is greater, insert it into the right subtree.
   - If the word already exists, display a message “Word already exists in dictionary.”
   - Repeat recursively until the correct position is found.

4. Search Operation
   - Compare the given word with the current node’s word:
     - If they match → display its meaning.
     - If the target word is smaller, move to the left subtree.
     - If it’s larger, move to the right subtree.
   - If the node is `NULL`, print “Word not found!”

5. Inorder Traversal (Display Dictionary)
   - Traverse the BST in inorder (Left → Root → Right).
   - This traversal displays all stored words in alphabetical order.
   - For each node visited, print → `word : meaning`.

6. Stop



## 🌳 Visual Representation

Example after inserting words **apple**, **banana**, and **cat**:
```
    apple
       \
        banana
           \
            cat
```


If we also insert **ant**, it becomes:
```
         apple
        /    \
     ant     banana
                \
                 cat
```


## ⌨️ Sample Input / Output
```
--- Dictionary Menu ---

Insert Word
Search Word
Display Dictionary
Exit
Enter your choice: 1
Enter Word: apple
Enter Meaning: A fruit that grows on trees
--- Dictionary Menu ---

Insert Word
Search Word
Display Dictionary
Exit
Enter your choice: 1
Enter Word: cat
Enter Meaning: A small domesticated carnivorous mammal
--- Dictionary Menu ---

Insert Word
Search Word
Display Dictionary
Exit
Enter your choice: 1
Enter Word: banana
Enter Meaning: A long curved fruit
--- Dictionary Menu ---

Insert Word
Search Word
Display Dictionary
Exit
Enter your choice: 3
--- Dictionary Words ---
apple : A fruit that grows on trees
banana : A long curved fruit
cat : A small domesticated carnivorous mammal

--- Dictionary Menu ---
Enter your choice: 2
Enter Word to Search: banana
Meaning of 'banana' is: A long curved fruit

Enter your choice: 4
Exiting...
```



## 💻 Code Screenshot

![Code Screenshot](/screenshots/10.1.png)  
![Code Screenshot](/screenshots/10.2.png)



## 🖥️ Output Screenshot

![Output Screenshot](/screenshots/10.out.png)



## 🧠 Notes

- The **Binary Search Tree** ensures that words are stored in **alphabetical order** while maintaining fast insertion and search times.
- Time complexity:
  - **Insertion/Search:** Average `O(log n)`, Worst `O(n)` (if skewed tree)
- The dictionary grows dynamically using **dynamic memory allocation** (`malloc()`).
- **Inorder traversal** naturally lists all entries alphabetically.



✅ **Hence, the dictionary using a Binary Search Tree was successfully implemented, allowing insertion, searching, and alphabetical display of word–meaning pairs.**
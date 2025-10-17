# **Experiment 12: Implement a Spell Checker using a Hash Table**

## 🎯 Aim

To implement a **Spell Checker** in C using a **Hash Table** that stores dictionary words for fast lookup.  
The program should validate entered words and suggest possible corrections for misspelled words.

---

## 📝 Algorithm

1. Start

2. Initialize the Hash Table
   - Create an array of fixed size (`TABLE_SIZE`) to represent the hash table.
   - Each index stores a linked list (to handle collisions using chaining).

3. Define a Hash Function
   - Generate an index based on the word’s characters, typically by:
     ```
     hash(word) = (sum of ASCII values of all characters) % TABLE_SIZE
     ```

4. Insert Words into Dictionary
   - For each word in the predefined dictionary list:
     - Compute its hash using the hash function.
     - Insert it into the linked list at that index.

5. Search for a Word
   - Compute the hash of the input word.
   - Traverse the chain at that index.
   - If the word is found → display “Word is valid”.
   - Else → display “Word not found”.

6. Suggest Corrections
   - If the word is not found, generate possible suggestions using a simple rule:
     - Display dictionary words starting with the same first character as the misspelled word.
   - (Can be extended to use Edit Distance algorithms for better accuracy).

7. Display Dictionary (optional)
   - Traverse the entire hash table and print all stored words.

8. Stop



## 🌳 Visual Representation

**Hash Table (with chaining):**
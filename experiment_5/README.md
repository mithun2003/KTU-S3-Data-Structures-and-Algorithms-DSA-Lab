# Experiment 5: Browser Navigation Simulation using Doubly Linked List

## Aim

To simulate the **backward and forward navigation of visited web pages** in a web browser using **doubly linked list operations**.

## Algorithm

We assume:

- Each visited page is represented as a **Node** with:
  - `url` → the page URL
  - `prev` → pointer to the previous page
  - `next` → pointer to the next page
- `head` → points to the first page in history
- `current` → points to the current page being viewed

### 1. Visit New Page

**Algorithm visit_page(url):**

1. Create a new node `newNode` with `newNode→url = url`.
2. Set `newNode→prev = current` and `newNode→next = NULL`.
3. If `current` is not NULL:
   - Remove all forward history (all nodes after `current`).
   - Set `current→next = newNode`.
4. Else (no pages visited yet):
   - Set `head = newNode`.
5. Set `current = newNode`.
6. Display "Visited: url".

---

### 2. Go Back

**Algorithm go_back():**

1. If `current == NULL` or `current→prev == NULL`:
   - Output "No previous page."
2. Else:
   - Set `current = current→prev`.
   - Display "Moved back to: current→url".

### 3. Go Forward

**Algorithm go_forward():**

1. If `current == NULL` or `current→next == NULL`:
   - Output "No next page."
2. Else:
   - Set `current = current→next`.
   - Display "Moved forward to: current→url".

### 4. Display Current Page

**Algorithm display_current():**

1. If `current == NULL`:
   - Output "No page currently opened."
2. Else:
   - Display "Current Page: current→url".

### 5. Display Browsing History

**Algorithm display_history():**

1. If `head == NULL`:
   - Output "No browsing history."
2. Else:
   - Initialize `temp = head`.
   - While `temp != NULL`:
     - If `temp == current`, highlight as current page: `>> temp→url`
     - Else, display `temp→url`
     - Move `temp = temp→next`.

## ⌨️ Output (Example)

```
Browser Navigation Simulation:
1. Visit New Page
2. Back
3. Forward
4. Display Current Page
5. Display Browsing History
6. Exit
Enter your choice: 1
Enter URL: www.google.com
Visited: www.google.com

Enter your choice: 1
Enter URL: www.github.com
Visited: www.github.com

Enter your choice: 1
Enter URL: www.stackoverflow.com
Visited: www.stackoverflow.com

Enter your choice: 2
Moved back to: www.github.com

Enter your choice: 2
Moved back to: www.google.com

Enter your choice: 3
Moved forward to: www.github.com

Enter your choice: 4
Current Page: www.github.com

Enter your choice: 5
Browsing History:
www.google.com
>> www.github.com
www.stackoverflow.com

Enter your choice: 1
Enter URL: www.reddit.com
Visited: www.reddit.com

Enter your choice: 5
Browsing History:
www.google.com
>> www.reddit.com

Enter your choice: 6
Exiting program...
```

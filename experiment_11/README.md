# **Experiment 11: Implement Binary Search Algorithm**

## 🎯 Aim

To implement the **Binary Search algorithm** in C to efficiently find the position of a given key in a **sorted array**.


## 📝 Algorithm

1. Start

2. Input the number of elements `n`.

3. Read `n` sorted elements into an array `arr`.

4. Input the key element to search.

5. Initialize:

   - `low = 0`
   - `high = n - 1`

6. while `low <= high`:

   - Find the middle index:  
     `mid = (low + high) / 2`
   - If `arr[mid] == key`, the key is found.  
      Print `mid`.
   - Else if `key < arr[mid]`:  
     `high = mid - 1`(search in left half)
   - Else:  
     `low = mid + 1`(search in right half)

7. If `low > high`, print “Key not found”.

8. Stop


## ⌨️ Sample Output

### Example 1
```
Enter number of elements: 7
Enter sorted elements:
2 4 6 8 10 12 14
Enter the key to search: 10
Key found at index 4.
```
### Example 2
```
Enter number of elements: 5
Enter sorted elements:
1 3 5 7 9
Enter the key to search: 8
Key not found.
```


## 🧮 Time Complexity

| **Case** | **Explanation** | **Time Complexity** |
|-----------|----------------|---------------------|
| **Best Case** | Key equals the middle element on the first comparison. | **O(1)** |
| **Average Case** | Key found after several halvings of the list. | **O(log n)** |
| **Worst Case** | Element not found; array fully halved until exhausted. | **O(log n)** |

> Binary search continually divides the search interval in half, producing logarithmic time efficiency.



## 💾 Space Complexity
 **Space Complexity = O(1)**.



## 📊 Summary

| **Aspect** | **Details** |
|-------------|-------------|
| **Algorithm Type** | Divide and Conquer |
| **Input Requirement** | Array must be sorted |
| **Efficiency** | Very high for large datasets |
| **Time Complexity** | O(log n) |
| **Space Complexity** | O(1) |
| **Applications** | Searching in sorted arrays, databases, dictionaries |



## 🖥️ Output Screenshot

![Output Screenshot](/screenshots/11.out.png)



✅ **Hence, the binary search algorithm was successfully implemented, demonstrating logarithmic time complexity and constant space efficiency for searching in sorted datasets.**
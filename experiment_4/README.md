# Experiment 4: Queue, Dequeue, and Circular Queue using Arrays

## 🔹 4.1 Queue using Arrays

## 🎯 Aim

To implement a **queue** using **array**.

## Algorithm for Basic Queue Operations

We assume:

- `queue[MAX]` is an array to hold queue elements.
- `front` and `rear` are integers initialized to `-1`.
- `MAX` is the maximum size of the queue.

#### 1. Enqueue (Insert element)

1. If `rear == MAX - 1` then Output `"Queue Overflow"` and Return.
2. If `front == -1` then `front = 0`.
3. `rear = rear + 1`
4. `queue[rear] = item`
5. Output `"Enqueued item"`

#### 2. Dequeue (Remove element)

1. If `front == -1` then Output `"Queue Underflow"` and Return.
2. If `front == rear` then
   - Output `"Dequeued: queue[front]"`
   - Reset `front = rear = -1`
3. Else
   - Output `"Dequeued: queue[front]"`
   - `front = front + 1`

#### 3. Peek (View Front Element)

1. If `front == -1` then Output `"Queue is Empty"` and Return.
2. Else Output `"Front element = queue[front]"`

#### 4. isEmpty (Check if queue is empty)

1. If `front == -1` then Return `TRUE`
2. Else Return `FALSE`

#### 5. isFull (Check if queue is full)

1. If `rear == MAX - 1` then Return `TRUE`
2. Else Return `FALSE`

#### 6. Display (Show all elements)

1. If `front == -1` then Output `"Queue is Empty"` and Return.
2. Else For `i = front` to `rear` Output `queue[i]`

#### 7. Size (Number of elements)

1. If `front == -1` then Return `0`
2. Else Return `(rear - front + 1)`

## ⌨️ Output (Example)

```
Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 1
Enter value to enqueue: 10
Enqueued: 10

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 1
Enter value to enqueue: 20
Enqueued: 20

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 3
Queue elements: 10 20

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 2
Dequeued: 10

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 4
Front element: 20

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 5
Queue size: 1

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 6
```

---

## 🔹 4.2 Circular Queue using Arrays

## 🎯 Aim

To implement a **circular queue** using **array**.

## Algorithm for Basic Queue Operations

We assume:

- `queue[MAX]` is an array to hold queue elements.
- `front` and `rear` are integers initialized to `-1`.
- `MAX` is the maximum size of the queue.

### 1. Enqueue (Insert element)

1. If `(rear + 1) % MAX == front` → Queue Overflow
2. Else, if queue is empty (`front == -1`) → set `front = rear = 0`
3. Else → `rear = (rear + 1) % MAX`
4. Insert the element at `queue[rear]`

---

### 2. Dequeue (Remove element)

1. If `front == -1` → Queue Underflow
2. Else → output `queue[front]`
3. If `front == rear` → reset `front = rear = -1`
4. Else → `front = (front + 1) % MAX`

---

### 3. Peek (View Front Element)

1. If `front == -1` → Queue is empty
2. Else → output `queue[front]`

---

### 4. isEmpty (Check if queue is empty)

1. If `front == -1` → Return TRUE
2. Else → Return FALSE

---

### 5. isFull (Check if queue is full)

1. If `(rear + 1) % MAX == front` → Return TRUE
2. Else → Return FALSE

---

### 6. Display (Print all elements)

1. If queue is empty → Print "Queue is empty"
2. Else → Start from `front` and print elements until `(rear + 1) % MAX`, using wrap-around

---

### 7. Size (Number of elements in queue)

1. If queue is empty → Return 0
2. Else if `rear >= front` → Size = `rear - front + 1`
3. Else → Size = `MAX - front + rear + 1`

## ⌨️ Output (Example)

```
Circular Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display Queue
4. Peek Front
5. Queue Size
6. Exit
Enter your choice: 1
Enter value to enqueue: 10
Enqueued: 10

Enter your choice: 1
Enter value to enqueue: 20
Enqueued: 20

Enter your choice: 1
Enter value to enqueue: 30
Enqueued: 30

Enter your choice: 3
Circular Queue elements: 10 20 30

Enter your choice: 2
Dequeued: 10

Enter your choice: 4
Front element: 20

Enter your choice: 5
Queue size: 2
```

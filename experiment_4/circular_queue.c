#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the circular queue is empty
int isEmpty() { return (front == -1) ? 1 : 0; }

// Function to check if the circular queue is full
int isFull() { return ((rear + 1) % MAX == front) ? 1 : 0; }

// Function to add an element to the circular queue
void enqueue() {
  int value;
  if (isFull()) {
    printf("Queue Overflow! Cannot enqueue\n");
    return;
  }
  printf("Enter value to enqueue: ");
  scanf("%d", &value);

  if (front == -1 && rear == -1) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % MAX;
  }
  queue[rear] = value;
  printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
void dequeue() {
  if (isEmpty()) {
    printf("Queue Underflow! Cannot dequeue\n");
    return;
  }
  printf("Dequeued: %d\n", queue[front]);
  if (front == rear) {
    front = rear = -1;  // Reset if last element removed
  } else {
    front = (front + 1) % MAX;
  }
}

// Function to display the circular queue elements
void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  printf("Circular Queue elements: ");
  int i = front;
  do {
    printf("%d ", queue[i]);
    i = (i + 1) % MAX;
  } while (i != (rear + 1) % MAX);
  printf("\n");
}

// Function to peek at front element
void peek() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Front element: %d\n", queue[front]);
}

// Function to get size of circular queue
void size() {
  if (isEmpty()) {
    printf("Queue size: 0\n");
    return;
  }
  int sz;
  if (rear >= front)
    sz = rear - front + 1;
  else
    sz = MAX - front + rear + 1;
  printf("Queue size: %d\n", sz);
}

int main() {
  int choice;
  printf("\nCircular Queue Operations Menu:\n");
  printf(
      "1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Peek Front\n5. Queue "
      "Size\n6. Exit\n");
  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        peek();
        break;
      case 5:
        size();
        break;
      case 6:
        exit(0);
      default:
        printf("Enter choice between 1-6\n");
    }
  }
  return 0;
}

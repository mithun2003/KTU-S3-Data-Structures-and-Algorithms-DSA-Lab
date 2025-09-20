#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() { return (front == -1) ? 1 : 0; }

// Function to check if the queue is full
int isFull() { return (rear == MAX - 1) ? 1 : 0; }

// Function to add an element to the queue
void enqueue() {
    int value;
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    if (isEmpty()) {
        front = 0;  // Initialize front if queue was empty
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue\n");
    } else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        // Queue has only one element, reset after dequeue
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

// Function to display the elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to get the front element of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to get the size of the queue
void size() {
    if (isEmpty()) {
        printf("Queue size: 0\n");
    } else {
        printf("Queue size: %d\n", rear - front + 1);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Peek Front\n");
        printf("5. Queue Size\n");
        printf("6. Exit\n");
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
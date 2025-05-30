#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1 || front > rear;
}

int isFull() {
    return rear == SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1; // Reset the queue
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue state: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Demonstrate queue operations
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    
    peek();
    
    dequeue();
    displayQueue();
    
    enqueue(40);
    enqueue(50);
    enqueue(60);
    displayQueue();
    
    // This will cause overflow
    enqueue(70);
    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    displayQueue();
    
    // This will cause underflow
    dequeue();
    
    return 0;
}

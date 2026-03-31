#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)   // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;   // queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    printf("Queue: ");

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(50);
    enqueue(60);
    display();

    return 0;
}
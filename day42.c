// Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

/* Queue Operations */
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

/* Stack Operations */
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

/* Reverse Queue using Stack */
void reverseQueue() {
    while (front <= rear) {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while (top != -1) {
        enqueue(pop());
    }
}

/* Display Queue */
void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    display();

    reverseQueue();

    printf("Reversed Queue: ");
    display();

    return 0;
}
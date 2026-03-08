// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    temp->data = value;

    if (front == NULL) {
        front = rear = temp;
        rear->next = front;
    } 
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }

    printf("%d inserted\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;

    if (front == rear) {
        printf("%d deleted\n", front->data);
        front = rear = NULL;
    } 
    else {
        printf("%d deleted\n", front->data);
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;

    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
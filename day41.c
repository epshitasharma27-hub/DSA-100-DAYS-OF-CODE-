// Implement a Queue using a linked list supporting enqueue and dequeue operations.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    if(temp == NULL) {
        printf("Overflow\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    if(rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue() {
    if(front == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("%d deleted from queue\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue
void display() {
    struct Node* temp = front;

    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}
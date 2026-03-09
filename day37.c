// Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#define MAX 100

int pq[MAX];
int n = 0;

// Insert element in priority queue
void insert(int value) {
    int i;

    if (n == MAX) {
        printf("Priority Queue Overflow\n");
        return;
    }

    // Find correct position for new element
    i = n - 1;
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    n++;

    printf("%d inserted into priority queue\n", value);
}

// Delete highest priority element (smallest)
void delete() {
    if (n == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d deleted from priority queue\n", pq[0]);

    for (int i = 1; i < n; i++) {
        pq[i - 1] = pq[i];
    }

    n--;
}

// Display queue
void display() {
    if (n == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
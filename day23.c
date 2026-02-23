//  Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Merge two sorted lists
struct node* mergeLists(struct node* head1, struct node* head2) {
    struct node* mergedHead = NULL;
    struct node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        int value;

        if (head1->data <= head2->data) {
            value = head1->data;
            head1 = head1->next;
        } else {
            value = head2->data;
            head2 = head2->next;
        }

        struct node* newNode = createNode(value);

        if (mergedHead == NULL) {
            mergedHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add remaining nodes
    while (head1 != NULL) {
        tail->next = createNode(head1->data);
        tail = tail->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        tail->next = createNode(head2->data);
        tail = tail->next;
        head2 = head2->next;
    }

    return mergedHead;
}

// Display list
void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int n1, n2, value;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n1);

    printf("Enter elements (in sorted order):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &n2);

    printf("Enter elements (in sorted order):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    printf("\nFirst List: ");
    display(head1);

    printf("Second List: ");
    display(head2);

    struct node* merged = mergeLists(head1, head2);

    printf("Merged Sorted List: ");
    display(merged);

    return 0;
}
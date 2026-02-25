// Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};


struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);

    if(head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}


int countOccurrences(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}


void display(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nLinked List: ");
    display(head);

    printf("\nEnter element to count: ");
    scanf("%d", &key);

    int result = countOccurrences(head, key);

    printf("Element %d occurs %d times in the linked list.\n", key, result);

    return 0;
}
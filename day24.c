//  Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation. 
#include <stdio.h>
#include <stdlib.h>

// Define node
struct node {
    int data;
    struct node *next;
};

// Insert at end
struct node* insert(struct node *head, int value) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct node* deleteFirstOccurrence(struct node *head, int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    // If head contains key
    if (head->data == key) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *current = head;

    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Key not found.\n");
        return head;
    }

    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

// Display list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert(head, value);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printf("Updated List:\n");
    display(head);

    return 0;
}
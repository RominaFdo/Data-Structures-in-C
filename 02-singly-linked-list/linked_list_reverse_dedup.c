/*
 * Singly linked list: build from user input, insert at a position,
 * print in reverse (recursively) and remove duplicate values.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void display(void) {
    struct node *ptr = head;
    printf("[head] => ");
    while (ptr != NULL) {
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Insert so the new node ends up at index pos (0-based). */
void insertAtPos(int data, int pos) {
    if (pos <= 0 || head == NULL) {
        insert(data);
        return;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    struct node *prev = head;
    for (int i = 1; i < pos && prev->next != NULL; i++) {
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
}

void displayReverse(struct node *ptr) {
    if (ptr == NULL) {
        return;
    }
    displayReverse(ptr->next);
    printf("%d <= ", ptr->data);
}

void removeDuplicates(void) {
    for (struct node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        struct node *prev = ptr1;
        struct node *ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr2->data == ptr1->data) {
                prev->next = ptr2->next;
                free(ptr2);
            } else {
                prev = ptr2;
            }
            ptr2 = prev->next;
        }
    }
}

int main(void) {
    int n, data;
    printf("Enter number of nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }
    printf("\nLinked list before inserting a new node:\n");
    display();

    int pos, newData;
    printf("\nEnter position to add the new node: ");
    scanf("%d", &pos);
    printf("Enter data for the new node: ");
    scanf("%d", &newData);
    insertAtPos(newData, pos);
    printf("\nLinked list after inserting a new node:\n");
    display();

    printf("\nLinked list in reverse order:\n");
    displayReverse(head);
    printf("[head]\n");

    printf("\nAfter removing duplicates:\n");
    removeDuplicates();
    display();
    return 0;
}

/*
 * Menu-driven stack using a singly linked list.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

bool isEmpty(void) {
    return head == NULL;
}

void push(void);
void pop(void);
void display(void);

int main(void) {
    while (1) {
        int choice;
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print all elements of the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            return 0;
        }
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n"); break;
        }
    }
}

void push(void) {
    struct node *ptr = malloc(sizeof(struct node));
    printf("Enter value to push onto the stack: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
}

void pop(void) {
    if (isEmpty()) {
        printf("Underflow: can't remove an item from the stack\n");
        return;
    }
    struct node *ptr = head;
    printf("Popped %d\n", ptr->data);
    head = head->next;
    free(ptr);
}

void display(void) {
    if (isEmpty()) {
        printf("Empty stack: nothing to display\n");
        return;
    }
    for (struct node *ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%d\n", ptr->data);
    }
}

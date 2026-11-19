/*
 * Doubly linked list: build from user input, traverse forwards and backwards,
 * and find the maximum and minimum values.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;

bool isEmpty(void) { return head == NULL; }

void display(struct node *ptr) {
    int x = 1;
    while (ptr != NULL) {
        printf("Data in node %d: %d\n", x++, ptr->data);
        ptr = ptr->next;
    }
}

void displayReverse(struct node *ptr) {
    int x = 1;
    while (ptr != NULL) {
        printf("Data in node %d: %d\n", x++, ptr->data);
        ptr = ptr->prev;
    }
}

void createList(int n) {
    for (int i = 1; i <= n; i++) {
        struct node *newNode = malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = last;

        if (isEmpty()) {
            head = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
    }
}

void findMaxMin(struct node *p, int *max, int *min) {
    if (p == NULL) {
        printf("The list is empty.\n");
        return;
    }
    *max = p->data;
    *min = p->data;
    while (p != NULL) {
        if (p->data > *max) *max = p->data;
        if (p->data < *min) *min = p->data;
        p = p->next;
    }
    printf("Maximum value: %d\n", *max);
    printf("Minimum value: %d\n", *min);
}

int main(void) {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("Data in forward order:\n");
    display(head);
    printf("Data in backward order:\n");
    displayReverse(last);

    int max, min;
    findMaxMin(head, &max, &min);
    return 0;
}

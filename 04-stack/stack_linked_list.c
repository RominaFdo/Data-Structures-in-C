/*
 * Stack implemented with a singly linked list: push, pop, peek, isEmpty.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void push(void);
int pop(void);
int peek(void);
bool isEmpty(void);

int main(void) {
    push();
    push();
    pop();
    peek();
    printf("Stack is %s\n", isEmpty() ? "empty" : "not empty");
    return 0;
}

bool isEmpty(void) {
    return head == NULL;
}

void push(void) {
    struct node *ptr = malloc(sizeof(struct node));
    printf("Enter value to push onto the stack: ");
    scanf("%d", &ptr->data);
    ptr->next = head;
    head = ptr;
}

int pop(void) {
    if (isEmpty()) {
        printf("Underflow: can't remove an item from the stack\n");
        return -1;
    }
    struct node *ptr = head;
    int val = ptr->data;
    head = head->next;
    free(ptr);
    printf("%d popped off the stack\n", val);
    return val;
}

int peek(void) {
    if (isEmpty()) {
        printf("Underflow: nothing to peek\n");
        return -1;
    }
    int x = head->data;
    printf("%d is the top element of the stack\n", x);
    return x;
}

/*
 * Stack implemented with a fixed-size array: push, pop, peek, isEmpty, isFull.
 */
#include <stdio.h>
#include <stdbool.h>

#define N 1000

int top = -1;
int stack[N];

void push(void);
int pop(void);
int peek(void);
bool isEmpty(void);
bool isFull(void);

int main(void) {
    push();
    push();
    pop();
    peek();
    isEmpty();
    isFull();
    return 0;
}

void push(void) {
    if (top == N - 1) {
        printf("Overflow: can't add more elements to the stack\n");
        return;
    }
    int x;
    printf("Enter element to push onto the stack: ");
    scanf("%d", &x);
    stack[++top] = x;
}

int pop(void) {
    if (top == -1) {
        printf("Nothing to pop: underflow\n");
        return -1;
    }
    int x = stack[top--];
    printf("Popped %d off the stack\n", x);
    return x;
}

int peek(void) {
    if (top == -1) {
        printf("Stack is empty: nothing to peek\n");
        return -1;
    }
    int x = stack[top];
    printf("%d is the top element of the stack\n", x);
    return x;
}

bool isEmpty(void) {
    if (top == -1) {
        printf("Stack is empty\n");
        return true;
    }
    printf("Stack is not empty\n");
    return false;
}

bool isFull(void) {
    if (top == N - 1) {
        printf("Stack is full\n");
        return true;
    }
    printf("Stack is not full\n");
    return false;
}

/*
 * Menu-driven stack using a fixed-size array.
 */
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int top = -1;
int stack[N];

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
    if (top == N - 1) {
        printf("Can't add more to the stack.\n");
        return;
    }
    int x;
    printf("Enter element to push onto the stack: ");
    scanf("%d", &x);
    stack[++top] = x;
}

void pop(void) {
    if (top == -1) {
        printf("Empty stack: nothing to pop.\n");
        return;
    }
    printf("Popped %d\n", stack[top--]);
}

void display(void) {
    if (top == -1) {
        printf("Empty stack: nothing to display.\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

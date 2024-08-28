#define N 1000
#include <stdio.h>
#include <stdbool.h>

int top = -1;
int stack[N];

void push();
void pop();
int peek();
bool isEmpty();
bool isFull();

int main(){
    push();
    push();
    pop();
    peek();
    isEmpty();
    isFull();
    return 0;
}

void push(){
    if (top == N-1){
        printf("Overflow State: can't add more elements in to the stack\n");
    }
    else{
        int x;
        printf("Enter element to be pushed into the stack:");
        scanf("%d" , &x);
        top += 1;
        stack[top] = x;
    }
}
void pop(){
    if (top == -1){
        printf("Mothing to pop. Underflow state\n");
    }
    else{
        int x = stack[top];
        printf("Popping %d out of the stack\n" , x);
        top-=1;
        return x;
    }
    return -1;
}

int peek(){
    int x = stack[top];
    printf("%d is the top most element of the stack\n" , x);
    return x;
}

bool isEmpty(){
    if (top == -1){
        printf("Stack is empty: underflow state\n");
        return true;
    }
    printf("Stack is not empty\n");
    return false;
}

bool isFull(){
    if(top == N-1){
        printf("Stack is full: overflow state\n");
        return true;
    }
    printf("Stack is not full\n");
    return false;
}


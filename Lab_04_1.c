#include <stdio.h>
#include <stdlib.h>

#define N 1000

int top = -1;
int stack[N];

void push();
void pop();
void display();

int main(){
    while(1){
        int choice;
        printf("Choose one from the below options....\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print all the elements of the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice =");
        scanf("%d" , &choice);
        switch(choice){
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(1);
                break;
        }

    }
    return 0;
}


void push(){
    if (top == N-1){
        printf("Can't add more to the stack.");
    }
    else{
        int x;
        printf("Enter element to be pushed into the stack:");
        scanf("%d" ,&x);
        top+= 1;
        stack[top] = x;

    }

}

void pop(){
    if (top == -1){
        printf("Empty stack nothing to pop.");
    }
    else{
        int x = stack[top];
        top-= 1;

    }
}

void display(){
    if (top == -1){
        printf("Empty stack nothing to display.");
    }
    else{
        for (int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

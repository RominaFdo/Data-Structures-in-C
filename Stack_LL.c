#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void push();
int pop();
int peek();
bool isEmpty();

struct node{
    int data;
    struct node*next;
};
struct node*head =NULL;

int main(){
    push();
    push();
    pop();
    peek();
    isEmpty();
    return 0;
}

bool isEmpty(){
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void push(){
    struct node* ptr = (struct node*)malloc(sizeof (struct node));
    printf("Enter value to push into the stack:");
    scanf("%d" , &ptr ->data);

    if (isEmpty()){
        head = ptr;
    }
    else{
        ptr->next = head;
        head = ptr;
    }
}

int pop(){
    struct node* ptr;
    int val;

    if (isEmpty()){
        printf("Underflow State: can't remove ant item from the stack\n");
        return NULL;
    }
    else{
        val = head->data;
        ptr = head;
        head = head-> next;
        free(ptr);
        printf("%d is popped out if the stack.\n",val);
        return val;


    }
}

int peek(){
    if (isEmpty()){
        printf("Underflow State: can't get a peek value\n");
        return NULL;
    }

    else{
        int x= head-> data;
        printf("%d is the top most element of the stack\n", x);
        return x;
    }
}
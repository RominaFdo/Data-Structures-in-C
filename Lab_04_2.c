#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;

bool isEmpty(){
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

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
    struct node* ptr = (struct node*)malloc(sizeof (struct node));
    printf("Enter value to push into the stack:");
    scanf("%d" , &ptr ->data);
    ptr->next=NULL;
    if (isEmpty()){
        head = ptr;
        return;
    }
    else{
        ptr->next = head;
        head = ptr;

    }

}

void pop(){
    struct node*ptr;
    if (isEmpty()){
        printf("Underflow State: can't remove ant item from the stack\n");

    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);

    }
}

void display(){
    struct node*ptr;
    ptr = head;
    if (isEmpty()){
        printf("Empty stack nothing to display\n");

    }
    else{
        while(ptr != NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->next;
        }

    }
}

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;

int main(){
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);
    display();
    insertAtBegin(5);
    display();
    InsertAtEnd(6);
    display();
    InsertAtPos(7,2);
    display();
    DeleteAtBegin();
    display();
    DeleteAtEnd();
    display();
    DeleteAtPos(2);
    display();
    return 0;

}
void insert(int data){
    struct node*temp =(struct node*)malloc(sizeof(struct node));
    temp-> data= data;
    temp-> next=head;
    head = temp;
}

void display(){
    struct node*ptr=head;
    printf("\n[head] =>");
    while(ptr != NULL){
        printf("%d =>",ptr->data);
        ptr = ptr->next;
    }
}
void insertAtBegin(int data){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head=temp;
        return;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void InsertAtEnd(int data){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head=temp;
        return;
    }
    else{
        struct node*ptr = head;
        while(ptr->next !=NULL){
            ptr=ptr->next;
        }
        ptr-> next = temp;
    }
}

void InsertAtPos(int data, int pos){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if (head == NULL){
        head=temp;
        return;
    }
    else{
        struct node* prev_ptr;
        struct node* ptr =head;
        for (int i=0; i<pos; i++){
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr;
        prev_ptr->next = temp;

    }
}

void DeleteAtBegin(){
    if (head ==NULL){
        printf("\nNothing to Delete ");
    }
    else{
        struct node*ptr = head;
        head = head->next;
        free(ptr);
        printf("\nNode Deleted.");
    }
}

void DeleteAtEnd(){
    if (head ==NULL){
        printf("\nNothing to Delete ");
    }
    else if(head->next == NULL){
        struct node*ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else{
        struct node*ptr = head;
        struct node*prev_ptr =NULL;
        while(ptr->next!=NULL){
            prev_ptr= ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
        printf("\nNode Deleted.");
    }
}

void DeleteAtPos(int pos){
    struct node*ptr = head;
    if (head ==NULL){
        printf("\nNothing to Delete ");
    }
    else if(pos == 0){
        ptr = head;
        head= ptr->next;
        free(ptr);

    }
    else{
        struct node*prev_ptr;
        for(int i=0; i<pos; i++){
            prev_ptr=ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        free(ptr);
        printf("\nNode Deleted.");
    }
}



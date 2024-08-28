#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head = NULL;
int main(){
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);
    printLinkedList();
    insertatBegin();
    printLinkedList();
    insertatEnd();
    printLinkedList();
    insertatPos();
    printLinkedList();
    deleteBegin();
    printLinkedList();
    deleteEnd();
    printLinkedList();
    return 0;
}

void insert(int data){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void printLinkedList()
{
    struct node*ptr =head;
    printf("\n[head] =>");
    while (ptr !=NULL){
        printf("%d =>",ptr->data);
        ptr = ptr->next;
    }
}

void insertatBegin(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
   if(head ==NULL){
        head = temp;
        return;
    }
    else{
        temp ->next = head;
        head = temp;
    }
}

void insertatEnd(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(head ==NULL){
        head = temp;
        return;
    }
    else{
        struct node*ptr = head;
        while(ptr -> next !=NULL){
            ptr = ptr ->next;
        }
        ptr ->next =temp;
    }
}

void insertatPos(){
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter node data : ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(head ==NULL){
        head = temp;
        return;
    }
    else{
        struct node*prev_ptr = NULL;
        struct node*ptr =head;
        int pos;
        printf("\nEnter position : ");
        scanf("%d",&pos);

        for(int i=0;i < pos ;i++)
        {
         prev_ptr = ptr;
         ptr = ptr ->next;
        }

        temp ->next =ptr;
        prev_ptr->next = temp;
        }
    }
void deleteBegin(){
    if (head ==NULL){
        printf("\n Linked List is empty");
        return;
    }
    else{
        struct node*ptr = head;
        head = head->next;
        free(ptr);
        printf("\nNode Deleted\n");
    }
}

void deleteEnd(){
    if (head ==NULL){
        printf("\nLinked List is empty.");
        return;
    }
    else if(head->next ==NULL){
        struct node*ptr =head;
        head =ptr ->next;
        free(ptr);
        printf("\nNode Deleted");
    }
    else{
        struct node*ptr = head;
        struct node*prev_ptr =NULL;
        while (ptr ->next !=NULL){
            prev_ptr =ptr;
            ptr = ptr->next;
        }
        prev_ptr ->next = NULL;
        free(ptr);
    }
}



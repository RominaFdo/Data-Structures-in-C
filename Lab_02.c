#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;

    struct node*next;
};
struct node*head=NULL;
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

void InsertAtPos(int data, int pos){
    struct node*temp =(struct node*)malloc(sizeof(struct node));
    temp-> data= data;
    temp-> next=NULL;
    if (head ==NULL){
        head=temp;
    }
    else{
        struct node*prev_ptr;
        struct node*ptr = head;
        for (int i=0; i<pos; i++){
            prev_ptr=ptr;
            ptr=ptr->next;
        }
        temp ->next =ptr;
        prev_ptr ->next = temp;
    }
}

void displayReverse(struct node*ptr){
    if (ptr-> next!= NULL){
        displayReverse(ptr->next) ;
    }
    printf("%d <=", ptr->data);
}

void duplicateRemove() {
    struct node* ptr1 = head;
    struct node* ptr2 = NULL;
    struct node* prev_ptr = NULL;
    if (head == NULL) {
        return;
    }
    else {
        while (ptr1 != NULL) {
            prev_ptr = ptr1;
            ptr2 = ptr1->next;
            while (ptr2 != NULL) {
                if (ptr1->data == ptr2->data) {
                    prev_ptr->next = ptr2->next;
                }
                else {
                    prev_ptr = ptr2;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }
}

int main(){
    int n;
    printf("Enter Number of Nodes in the Linked List :");
    scanf("%d",&n);
    int data;
    for (int i=0; i<n; i++){
        printf("Enter data %d :",i+1);
        scanf("%d",&data);
        insert(data);
    }
    printf("Linked List Before Inserting a New Node : ");
    display();
    int pos,data2;
    printf("\nEnter position to add the new node :");
    scanf("%d",&pos);
    printf("\nEnter data to add to the new node :");
    scanf("%d",&data2);
    InsertAtPos(data2,pos);
    printf("\nLinked List After Inserting a New Node : \n");
    display();
    printf("\nLinked List in Reverse Order :\n");
    displayReverse(head);
    printf("\nBefore removing the Duplicates from the Linked List :\n");
    display();
    printf("\nAfter removing the Duplicates from the Linked List :\n");
    duplicateRemove();
    display();
    return 0;

}

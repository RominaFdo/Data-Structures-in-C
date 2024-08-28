
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
int data;
struct node*next;

};
struct node*head=NULL;

void Display();
void DisplayReverse(struct node *ptr);
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPosition();
void DeleteAtBegin();
void DeleteAtEnd();
void DeleteAtPosition();
void Search();
void Update();
void freeList(struct node *ptr);


int main(){
    int choice;

    while (1)
    {
        printf("\n1.Insert at begin\n2.Insert at end\n3.Insert at position\n4.Delete at begin\n5.Delete at end\n6.Delete at position\n7.Display linked List\n8.Display Linked List(Reversed)\n9.Search data\n10.Update\n11.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtBegin();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPosition();
            break;
        case 7:
            Display();
            break;
        case 8:
            DisplayReverse(head);
            break;
        case 9:
            Search();
            break;
        case 10:
            Update();
            break;
        case 11:
            freeList(head);
            exit(0);
            break;
        default:
            printf("Invalid Operation\n\n");
            break;
        }
    }
    return 0;

}

void Display(){
}
void DisplayReverse(struct node *ptr){
}
void InsertAtBegin(){
}
void InsertAtEnd(){
}
void InsertAtPosition(){
}
void DeleteAtBegin(){
}
void DeleteAtEnd(){
}
void DeleteAtPosition(){
}
void Search(){
}
void Update(){
}
void freeList(struct node *ptr){
}

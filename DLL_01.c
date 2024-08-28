#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;

bool isEmpty() { return head == NULL; }

void display(struct node*head){
    struct node*ptr = head;
    int x=1;
    while(ptr != NULL){
        printf("Data in node %d: %d\n",x++,ptr->data);
        ptr = ptr->next;
    }
}

void displayReverse(struct node*last){
    struct node*ptr = last;
    int x=1;
    while(ptr != NULL){
        printf("Data in node %d: %d\n",x++,ptr->data);
        ptr = ptr->prev;

    }
}

struct node* createList(int n) {

    for (int i = 1; i <= n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        if (isEmpty()){
            head = newNode;
            last = newNode;
        }
        else{
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }

    }
    return head;
}
void findMaxMin(struct node *p, int *max, int *min) {
    if (isEmpty()) {
        printf("The list is empty.\n");
        return;
    }

    *max = p->data;
    *min = p->data;

    while (p != NULL) {
        if (p->data > *max) {
            *max = p->data;
        }
        if (p->data < *min) {
            *min = p->data;
        }
        p = p->next;
    }

    printf("Maximum value: %d\n", *max);
    printf("Minimum value: %d\n", *min);
}


int main(void) {
    printf("Enter Numeber of Nodes:");
    int n;
    scanf("%d", &n);
    struct node* head = createList(n);
    printf("Data in forward order are :\n");
    display(head);
    printf("Data in backward order are :\n");
    displayReverse(last);
    int max, min;
    findMaxMin(head, &max, &min);

    return 0;
}





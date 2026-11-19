/*
 * Singly linked list where the inserted values (and position) come from the user.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert(int data);
void printLinkedList(void);
void insertAtBegin(void);
void insertAtEnd(void);
void insertAtPos(void);
void deleteBegin(void);
void deleteEnd(void);

int main(void) {
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);
    printLinkedList();
    insertAtBegin();
    printLinkedList();
    insertAtEnd();
    printLinkedList();
    insertAtPos();
    printLinkedList();
    deleteBegin();
    printLinkedList();
    deleteEnd();
    printLinkedList();
    printf("\n");
    return 0;
}

void insert(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void printLinkedList(void) {
    struct node *ptr = head;
    printf("\n[head] => ");
    while (ptr != NULL) {
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void insertAtBegin(void) {
    struct node *temp = malloc(sizeof(struct node));
    printf("\nEnter node data: ");
    scanf("%d", &temp->data);
    temp->next = head;
    head = temp;
}

void insertAtEnd(void) {
    struct node *temp = malloc(sizeof(struct node));
    printf("\nEnter node data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    struct node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

/* Insert so the new node ends up at index pos (0-based). */
void insertAtPos(void) {
    struct node *temp = malloc(sizeof(struct node));
    int pos;
    printf("\nEnter node data: ");
    scanf("%d", &temp->data);
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        temp->next = head;
        head = temp;
        return;
    }
    struct node *prev = head;
    for (int i = 1; i < pos && prev->next != NULL; i++) {
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
}

void deleteBegin(void) {
    if (head == NULL) {
        printf("\nLinked list is empty.");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nNode deleted.");
}

void deleteEnd(void) {
    if (head == NULL) {
        printf("\nLinked list is empty.");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *ptr = head;
        struct node *prev = NULL;
        while (ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
    printf("\nNode deleted.");
}

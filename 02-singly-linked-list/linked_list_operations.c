/*
 * Singly linked list: insert and delete at the beginning, end and a given position.
 * Runs a fixed sequence of operations and prints the list after each one.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert(int data);
void display(void);
void insertAtBegin(int data);
void insertAtEnd(int data);
void insertAtPos(int data, int pos);
void deleteAtBegin(void);
void deleteAtEnd(void);
void deleteAtPos(int pos);

int main(void) {
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    insert(0);
    display();
    insertAtBegin(5);
    display();
    insertAtEnd(6);
    display();
    insertAtPos(7, 2);
    display();
    deleteAtBegin();
    display();
    deleteAtEnd();
    display();
    deleteAtPos(2);
    display();
    printf("\n");
    return 0;
}

void insert(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void display(void) {
    struct node *ptr = head;
    printf("\n[head] => ");
    while (ptr != NULL) {
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void insertAtBegin(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
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
void insertAtPos(int data, int pos) {
    if (pos <= 0 || head == NULL) {
        insertAtBegin(data);
        return;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;

    struct node *prev = head;
    for (int i = 1; i < pos && prev->next != NULL; i++) {
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
}

void deleteAtBegin(void) {
    if (head == NULL) {
        printf("\nNothing to delete.");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("\nNode deleted.");
}

void deleteAtEnd(void) {
    if (head == NULL) {
        printf("\nNothing to delete.");
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

/* Delete the node at index pos (0-based). */
void deleteAtPos(int pos) {
    if (head == NULL) {
        printf("\nNothing to delete.");
        return;
    }
    if (pos <= 0) {
        deleteAtBegin();
        return;
    }
    struct node *prev = head;
    for (int i = 1; i < pos && prev->next != NULL; i++) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        printf("\nPosition %d is out of range.", pos);
        return;
    }
    struct node *ptr = prev->next;
    prev->next = ptr->next;
    free(ptr);
    printf("\nNode deleted.");
}

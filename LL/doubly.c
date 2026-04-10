#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createnode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed");
        exit(1);
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void insertbeg(int data) {
    Node* newnode = createnode(data);

    if(head == NULL) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode; //join both sides, front and back 
        head = newnode;
    }
}

void insertback(int data) {
    Node* newnode = createnode(data);

    if(head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->next = NULL;
        tail = newnode;
    }
}

void popfront() {
    if(head == NULL) return;

    Node* temp = head;

    if(head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

void popback() {
    if(head == NULL) return;

    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    tail->prev = NULL;
    temp->next = NULL;
    tail = temp;
}

void print() {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    insertbeg(3);
    insertbeg(2);
    insertbeg(1);
    
    print();

    insertback(1);

    print();

    popfront();

    print();

    popback();
    
    print();
    return 0;
}
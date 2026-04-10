#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertBegin(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = newnode; 
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertend(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = NULL;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deletefront(){
    Node* temp = head;

    if(head == NULL) {
        printf("empty LL");
    }

    head = head->next;
    temp->next = NULL;
    free(temp);
}

void deleteback(){
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void deleteatpos(int position) {
    Node* temp = head;

    for(int i=0; i<position-1; i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void insertpos(int data, int position) {
    Node* newnode = createNode(data);
    Node* temp = head;

    if(head == NULL) {
        printf("empty LL\n");
        exit(1);
    }

    for(int i=0; i<position-1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void rev(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    tail = head;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void print() {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d  -->  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    insertBegin(5);
    insertBegin(4);
    insertBegin(3);
    insertBegin(2);
    insertBegin(1);

    print();

    // insertend(6);
    // insertend(7);
    // insertend(8);

    // print();

    // deletefront();

    // print();

    // deleteback();

    // print();

    // deleteatpos(2);
    
    // print();

    // insertpos(3, 2);

    // print();

    rev();
    print();
    return 0;
}
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

void insertatfront(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = newnode; 
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertatend(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = NULL;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteatfront(){
    Node* temp = head;

    if(head == NULL) {
        printf("empty LL");
    }

    head = head->next;
    temp->next = NULL;
    free(temp);
}

void deleteatend(){
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    temp->next = NULL;
}

void deleteatposition(int position) {
    Node* temp = head;

    for(int i=0; i<position-1; i++) {
        temp = temp->next;
    }

    temp->next = temp->next->next;
}

void insertatposition(int data, int position) {
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

void reverseLL(){
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

void printLL() {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d  -->  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    insertatfront(5);
    insertatfront(3);
    insertatfront(2);

    printLL();

    insertatend(6);

    printLL();

    insertatposition(4, 2);

    printLL();

    deleteatend();

    printLL();

    deleteatfront();

    printLL();

    deleteatposition(2);

    printLL();

    reverseLL();

    printLL();
    return 0;
}
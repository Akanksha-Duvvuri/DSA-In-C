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
    
    return 0;   
}
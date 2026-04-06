#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

//only allocates memory
Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) {
        printf("memory allocation failed\n");
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

//inserting at the end -  (connects nodes into a DS)
void insertNode(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void printNode() {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {

    insertNode(3);
    insertNode(2);
    insertNode(1);

    printNode();
    return 0;
}
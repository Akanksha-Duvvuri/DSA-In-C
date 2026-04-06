#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;


//creating the new node
Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL){
        printf("memory allocation failed");
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
    
}

//insert at the beginning
void insertNode(int data) {
    Node* newnode = createNode(data);

    if(head == NULL) {
        head = tail = newnode;
    } else {
        newnode->data = data;
        newnode->next = head;
        head = newnode;
    }
}

void print(){
    Node* temp = head;

    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    insertNode(3);
    insertNode(2);
    insertNode(1);
    print();
    return 0;
}
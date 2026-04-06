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
    }

    newnode->data = data;
    newnode->next = NULL;
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

//insert node at position
void insertNodePos(int data, int position) {
    Node* newnode = createNode(data);
    Node* temp = head;

    for(int i=0; i<position-1; i++) {
        if(temp == NULL) {
            printf("psoition is invalid");
            break;
        }
        temp = temp->next;
    }

    newnode->next = temp->next; //temp is in position 1 rn, so newnode ka next will become temp ka old next which is position 2 rn. 
    temp->next = newnode;
}   

void print(){
    Node* temp = head;

    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next; 
    }
    printf("NULL");
}

int main(){

    insertNode(4);
    insertNode(2);
    insertNode(1);

    print();
    
    printf("\n");

    insertNodePos(3, 2);

    print();

    return 0;
}
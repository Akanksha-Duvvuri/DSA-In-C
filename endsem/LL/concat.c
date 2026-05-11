#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head1 = NULL;
Node* tail1 = NULL;


Node* head2 = NULL;
Node* tail2 = NULL;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertend1(int data) {
    Node* newnode = createnode(data);

    if(head1 == NULL) {
        head1 = tail1 = newnode;
    } else {
        tail1->next = newnode;
        tail1 = newnode;
    }
}

void insertend2(int data) {
    Node* newnode = createnode(data);

    if(head2 == NULL) {
        head2 = tail2 = newnode;
    } else {
        tail2->next = newnode;
        tail2 = newnode;
    }
}

void concat(){
    if(head1 == NULL){
        head1 = head2;
        tail1 = tail2;
        return;
    }

    tail1->next = head2;

    if(head2 != NULL){
        tail1 = tail2;
    }
}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        printf("%d  -->  ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main(){
     insertend1(1);
    insertend1(2);
    insertend1(3);

    print(head1);

    printf("\n");
    insertend2(4);
    insertend2(5);
    insertend2(6);

    print(head2);
    printf("\n");

    concat();

    print(head1);
    printf("\n");
    return 0;
}
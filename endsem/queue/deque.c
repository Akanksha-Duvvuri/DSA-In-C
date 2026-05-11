#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

Node* createNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
}

int isEmpty(){
    return front == NULL;
}

void insertatbeg(int data){
    Node* newnode = createNode(data);

    if(isEmpty()){
        front = rear = newnode;
    }else {
        newnode->next = front;
        front->prev = newnode;
        front = newnode;
    }
}

void insertatend(int data){
    Node* newnode = createNode(data);

    if(isEmpty()){
        front = rear = newnode;
    } else {
        rear->next = newnode;
        newnode->prev = rear;
        rear = newnode;
    }
}

void deleteatbeg(){
    if(isEmpty()){
        printf("deque underflow");
        return;
    }

    Node* temp = front;

    if(front == rear){
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteatend(){
    if(isEmpty()){
        printf("deque underflow");
        return;
    }

    Node* temp = rear;

    if(front == rear){
        front = rear =  NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }

    free(temp);
}

void print(){
    if(isEmpty()){
        printf("empty deque");
        return;
    }

    Node* temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("  ");
}

int main(){
    insertatend(10);
    insertatend(20);
    insertatbeg(5);
    insertatbeg(2);

    print();

    deleteatbeg();
    deleteatend();

    print();

    insertatend(30);
    insertatbeg(1);

    print();
    return 0;
}
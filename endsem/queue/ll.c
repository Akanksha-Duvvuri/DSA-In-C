#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void enqueue(int data){
    Node* newnode = createnode(data);

    if(rear == NULL){
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("empty queue");
        return;
    }

    Node* temp = front;
    front = front->next;

    free(temp);
}

int peek(){
    if(front == NULL){
        printf("empty queue");
        return -1;
    }

    return front->data;
}

void print(){
    Node* temp = front;

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);

    print();

    dequeue();

    print();

    printf("%d", peek());
    return 0;
}